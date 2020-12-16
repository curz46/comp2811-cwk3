#include "video_control.h"

#include <QtGlobal>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QLabel>

#include <iostream>

#include "player.h"
#include "icons.h"

VideoControl::VideoControl(Player *player) {
    this->player = player;

    QHBoxLayout *layout = new QHBoxLayout();

    this->playIcon  = createIcon(":/images/play.png");
    this->pauseIcon = createIcon(":/images/pause.png");

    this->playBtn = new QPushButton();
    playBtn->setIcon(*this->pauseIcon);

    this->time = new QLabel();
    this->time->setText("00:00 / 00:00");

    this->bar = new QProgressBar();
    this->bar->setTextVisible(false);

    layout->addWidget(this->playBtn);
    layout->addWidget(this->bar);
    layout->addWidget(this->time);

    this->setLayout(layout);

    connect(
        player, SIGNAL( durationChanged(qint64) ),
        this, SLOT( updateDuration(qint64) ));
    connect(
        player, SIGNAL( positionChanged(qint64) ),
        this, SLOT( updatePosition(qint64) ));
}

void VideoControl::updateDuration(qint64 millis) {
    // int millis = this->player->duration();
    this->bar->setMaximum(millis / 1000); // length in seconds
    this->bar->setValue(0);
}

void VideoControl::updatePosition(qint64 millis) {
    // int millis = this->player->position();
    this->bar->setValue(millis / 1000);

    int elapsed_m = millis / (1000 * 60);
    int elapsed_s = millis / 1000 - elapsed_m * 60;

    int duration = this->bar->maximum();
    std::cout << duration << std::endl;
    int total_m = duration / 60;
    int total_s = duration - total_m * 60;

    char buf[42];
    // xx:xx / xx:xx 
    snprintf(buf, sizeof(buf), "%02d:%02d / %02d:%02d", elapsed_m, elapsed_s, total_m, total_s);
    this->time->setText(buf);
}
