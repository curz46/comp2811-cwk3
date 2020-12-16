/*
 *
 *    ______
 *   /_  __/___  ____ ___  ___  ____
 *    / / / __ \/ __ `__ \/ _ \/ __ \
 *   / / / /_/ / / / / / /  __/ /_/ /
 *  /_/  \____/_/ /_/ /_/\___/\____/
 *              video for sports enthusiasts...
 *
 *  2811 cw3 : twak
 */

#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <vector>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QLabel>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QDesktopServices>
#include <QImageReader>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>

#include "player.h"
#include "video_control.h"
#include "thumbnail.h"
#include "add_video.h"
#include "util.h"

using namespace std;

// read in videos and thumbnails to this directory
vector<VideoInfo> getInfoIn (string loc) {
    vector<VideoInfo> out =  vector<VideoInfo>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files
        QString f = it.next();
            if (f.contains("."))

#if defined(_WIN32)
            if (f.contains(".wmv"))  { // windows
#else
            if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
#endif

            QString filepath = f.left( f .length() - 4);
            QString title = QString::fromStdString( getFilename(filepath.toStdString()) );
            QString thumb = filepath + ".png";
            QIcon *icon = nullptr;

            // try to find an icon
            // we can still add the video if there's no thumbnail
            if (QFile(thumb).exists()) { // if a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                QImage sprite = imageReader->read(); // read the thumbnail
                if (!sprite.isNull())
                    icon = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
            }
            QUrl *url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
            out.push_back(VideoInfo( title, url , icon )); // add to the output list
        }
    }

    return out;
}


int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    qDebug() << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // collect all the videos in the folder
    string videosDir;
    vector<VideoInfo> videos;

    if (argc == 2) {
        videosDir = string(argv[1]);
        videos = getInfoIn( videosDir );
    }

    if (videos.size() == 0) {
        const int result = QMessageBox::question(
                    NULL,
                    QString("Tomeo"),
                    QString("no videos found! download, unzip, and add command line argument to \"quoted\" file location. Download videos from Tom's OneDrive?"),
                    QMessageBox::Yes |
                    QMessageBox::No );

        switch( result )
        {
        case QMessageBox::Yes:
          QDesktopServices::openUrl(QUrl("https://leeds365-my.sharepoint.com/:u:/g/personal/scstke_leeds_ac_uk/EcGntcL-K3JOiaZF4T_uaA4BHn6USbq2E55kF_BTfdpPag?e=n1qfuN"));
          break;
        default:
            break;
        }
        exit(-1);
    }

    // the widget that will show the video
    QWidget *videoContainer = new QWidget();
    QVBoxLayout *videoLayout = new QVBoxLayout();
    QLabel *videoLabel = new QLabel();
    videoLabel->setText("hello world");
    QVideoWidget *videoWidget = new QVideoWidget;
    videoLayout->addWidget(videoLabel);
    videoLayout->addWidget(videoWidget);

    videoContainer->setLayout(videoLayout);

    // the buttons are arranged vertically 
    QVBoxLayout *layout = new QVBoxLayout();

    // the QMediaPlayer which controls the playback
    Player *player = new Player(layout);
    player->setVideoOutput(videoWidget);
    player->setVideoLabel(videoLabel);

    // create video control
    VideoControl *control = new VideoControl(player);
    videoLayout->addWidget(control);

    // a row of buttons
    QScrollArea *area = new QScrollArea();
    area->setMinimumSize(200 + 60, 0);
    area->setMaximumSize(200 + 60, QWIDGETSIZE_MAX);
    area->setWidgetResizable(true);
    area->setFrameStyle(QFrame::NoFrame);
    area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QWidget *buttonWidget = new QWidget();
    // a list of the buttons
    vector<Thumbnail*> buttons;

    buttonWidget->setLayout(layout);
    area->setWidget(buttonWidget);

    // add the 'add video' button to the top
    AddVideo *addVideo = new AddVideo(buttonWidget, videosDir);
    addVideo->connect(
        addVideo, SIGNAL( addVideo(VideoInfo*) ),
        player, SLOT( addVideo(VideoInfo*) ));
    layout->addWidget(addVideo);

    layout->setAlignment(addVideo, Qt::AlignHCenter);

    // create a thumbnail for each video
    for (int i = 0; i < videos.size(); i++) {
        QWidget *wrapper = new QWidget();
        QVBoxLayout *btnLayout = new QVBoxLayout();
        
        Thumbnail *button = new Thumbnail(buttonWidget, player);
        button->connect(button, SIGNAL(jumpTo(VideoInfo* )), player, SLOT (jumpTo(VideoInfo* ))); // when clicked, tell the player to play.
        buttons.push_back(button);

        QLabel *label = new QLabel();
        label->setText(*videos.at(i).title);

        btnLayout->addWidget(label);
        btnLayout->addWidget(button);
        wrapper->setLayout(btnLayout);

        layout->addWidget(wrapper);
        layout->setAlignment(wrapper, Qt::AlignHCenter);
        button->init(&videos.at(i));
    }

    // tell the player what buttons and videos are available
    player->setContent(&buttons, & videos);

    // create the main window and layout
    QWidget window;
    QHBoxLayout *top = new QHBoxLayout();
    window.setLayout(top);
    window.setWindowTitle("tomeo");
    window.setMinimumSize(800, 680);

    // add the video and the buttons to the top level widget
    top->addWidget(videoContainer);
    top->addWidget(area);

    // showtime!
    window.show();

    // wait for the app to terminate
    return app.exec();
}
