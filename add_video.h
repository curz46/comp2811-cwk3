#ifndef TOMEO_ADD_VIDEO_H
#define TOMEO_ADD_VIDEO_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

class AddVideo : public QPushButton {
    Q_OBJECT

public:
    AddVideo(QWidget *parent) : QPushButton(parent) {
        QSize size = QSize(150, 40);
        this->setMinimumSize(size);
        this->setMaximumSize(size);
        this->setText("Add Video");
    }
    ~AddVideo() {}
private slots:
signals:
};

#endif
