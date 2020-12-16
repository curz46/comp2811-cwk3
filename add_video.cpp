#include "add_video.h"

#include <QtWidgets/QFileDialog>
#include <QUrl> 
#include <QtDebug>

#include <string>
#include <fstream>
#include <iostream>

#include "util.h"

void AddVideo::clicked() {
    QString result = QFileDialog::getOpenFileName(this, "Choose Video", "/home/dylan", "Video Files (*.mp4, *.mov)");
    string filepath = result.toStdString();
    
    // get filename
    string new_path = getFilename(filepath);
    new_path.insert(0, this->videosDir);

    std::ifstream src(filepath, std::ios::binary);
    std::ofstream dst(new_path, std::ios::binary);
    
    dst << src.rdbuf();

    std::cout << new_path << std::endl;

    QString qpath = QString::fromStdString(new_path);

    QUrl *url = new QUrl(QUrl::fromLocalFile(qpath));
    // copy the file to the images directory
    
    emit addVideo(new VideoInfo(qpath, url, nullptr));
}
