#include "video_control.h"

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QLabel>

#include <iostream>

#include "player.h"
#include "icons.h"

VideoControl::VideoControl(Player *player) {
    QHBoxLayout *layout = new QHBoxLayout();

    this->playIcon  = createIcon(":/images/play.png");
    this->pauseIcon = createIcon(":/images/pause.png");

    std::cout << this->playIcon << std::endl;

    this->playBtn = new QPushButton();
    playBtn->setIcon(*this->playIcon);

    this->time = new QLabel();
    this->time->setText("dummy text");

    this->bar = new QProgressBar();

    layout->addWidget(this->playBtn);
    layout->addWidget(this->bar);
    layout->addWidget(this->time);

    this->setLayout(layout);

    // connect up signals
}
