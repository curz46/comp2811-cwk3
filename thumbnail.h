//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_BUTTON_H
#define CW2_THE_BUTTON_H

#include <QPushButton>
#include <QUrl>

class VideoInfo {

public:
    QString* title;
    QUrl* url; // video file to play
    QIcon* icon; // icon to display

    VideoInfo ( QString &title, QUrl* url, QIcon* icon) : url (url), icon (icon) {
        this->title = new QString();
        this->title->append(title);
    }
};

class Thumbnail : public QPushButton {
    Q_OBJECT

public:
    VideoInfo* info;

    Thumbnail(QWidget *parent) : QPushButton(parent) {
        setIconSize(QSize(200,110));
        connect( this, SIGNAL(released()), this, SLOT (clicked()) ); // if QPushButton clicked...then run clicked() below
    }

    void init(VideoInfo* i);

private slots:
    void clicked();

signals:
    void jumpTo(VideoInfo*);

};

#endif //CW2_THE_BUTTON_H
