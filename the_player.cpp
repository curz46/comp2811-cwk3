//
// Created by twak on 11/11/2019.
//

#include <QtWidgets/QLabel>

#include "the_player.h"
using namespace std;

void ThePlayer::setVideoLabel(QLabel *label) {
    this->label = label;
}

// all buttons have been setup, store pointers here
void ThePlayer::setContent(std::vector<TheButton*>* b, std::vector<TheButtonInfo>* i) {
    buttons = b;
    infos = i;
    jumpTo(buttons -> at(0) -> info);
}

// // change the image and video for one button every one second
// void ThePlayer::shuffle() {
//     TheButtonInfo* i = & infos -> at (rand() % infos->size() );
// //        setMedia(*i->url);
//     buttons -> at( updateCount++ % buttons->size() ) -> init( i );
// }

void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    // update video label to current video
    if (this->currentInfo != nullptr) {
        this->label->setText( *this->currentInfo->title );
    }
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
            play(); // starting playing again...
            break;
    default:
        break;
    }
}

void ThePlayer::jumpTo (TheButtonInfo* button) {
    this->currentInfo = button;
    setMedia( * button -> url);
    play();
}
