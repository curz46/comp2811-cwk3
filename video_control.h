#ifndef VIDEO_CONTROL__H
#define VIDEO_CONTROL__H

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QLabel>

class Player;

class VideoControl : public QWidget {
private:
    QIcon *playIcon;
    QIcon *pauseIcon;

    QPushButton *playBtn;
    QProgressBar *bar;
    QLabel *time;
public:
    VideoControl(Player *player);
};

#endif // VIDEO_CONTROL__H
