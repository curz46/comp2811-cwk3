#include "icons.h"

#include <QIcon>
#include <QImageReader>
#include <QImage>
#include <QPixmap>

QIcon* createIcon(char *path) {
    QImageReader *imageReader = new QImageReader(path);
    QImage sprite = imageReader->read(); // read the thumbnail
    if (sprite.isNull())
        return nullptr;
    return new QIcon(QPixmap::fromImage(sprite));
}
