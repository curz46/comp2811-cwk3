#ifndef TOMEO_ADD_VIDEO_H
#define TOMEO_ADD_VIDEO_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

#include <string>

#include "thumbnail.h"

class AddVideo : public QPushButton {
    Q_OBJECT

private:
    string videosDir;
public:
    AddVideo(QWidget *parent, string videosDir) : QPushButton(parent) {
        this->videosDir = videosDir;
        if (this->videosDir.back() != '/')
            this->videosDir.append("/");

        QSize size = QSize(150, 40);
        this->setMinimumSize(size);
        this->setMaximumSize(size);
        this->setText("Add Video");

        connect(
            this, SIGNAL( clicked() ),
            this, SLOT( clicked() ));
    }
    ~AddVideo() {}
private slots:
    void clicked();
signals:
    void addVideo(VideoInfo *info);
};

#endif
