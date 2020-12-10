//
// Created by twak on 11/11/2019.
//

#include <QImageReader>

#include "thumbnail.h"

QIcon* createIcon(char *path) {
    QImageReader *imageReader = new QImageReader(path);
    QImage sprite = imageReader->read(); // read the thumbnail
    if (sprite.isNull())
        return nullptr;
    return new QIcon(QPixmap::fromImage(sprite));
}

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
