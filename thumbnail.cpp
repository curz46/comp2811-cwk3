//
// Created by twak on 11/11/2019.
//

#include <QImageReader>

#include "thumbnail.h"

#include "icons.h"

void Thumbnail::init(VideoInfo* i) {
    if (i->icon != nullptr) {
        this->setIcon(*i->icon);
    } else {
        QIcon *icon = createIcon(":/images/no-thumbnail.jpg");
        if (icon != nullptr)
            this->setIcon(*icon);
    }
    this->info = i;
}

void Thumbnail::clicked() {
    emit jumpTo(info);
}
