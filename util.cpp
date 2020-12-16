#include "util.h"

#include <QIcon>
#include <QImageReader>
#include <QImage>
#include <QPixmap>

#include <string>

QIcon* createIcon(char *path) {
    QImageReader *imageReader = new QImageReader(path);
    QImage sprite = imageReader->read(); // read the thumbnail
    if (sprite.isNull())
        return nullptr;
    return new QIcon(QPixmap::fromImage(sprite));
}

std::string getFilename(std::string path) {
    std::string filename = path;
    size_t last_slash = filename.find_last_of("\\/");
    if (std::string::npos != last_slash)
        filename.erase(0, last_slash+1);
    return filename;
}
