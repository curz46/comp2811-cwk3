#include "search.h"
#include "thumbnail.h"

#include <QString>

#include <iostream>
#include <vector>

Search::Search(std::vector<Thumbnail*> *buttons) {
    this->buttons = buttons;

    QSize size = QSize(210, 30);
    this->setMinimumSize(size);
    this->setMaximumSize(size);
    this->setPlaceholderText("Type here to filter videos");
    this->setTextMargins(5, 5, 5, 5);

    connect(
        this, SIGNAL( textChanged(const QString&) ),
        this, SLOT( textChanged(const QString&) ));
}

void Search::textChanged(const QString& text) {
    string filter = text.toStdString();

    std::vector<Thumbnail*>::iterator ptr;
    for (ptr = this->buttons->begin(); ptr < this->buttons->end(); ptr++) {
        Thumbnail *button = *ptr;

        QString *title = button->info->title;
        string str     = title->toStdString();

        int i = str.find(filter);
        // visible if found in string
        // i.e. show video if the title contains our filter text
        button->setVisible(i != std::string::npos);
    }
}
