#ifndef SEARCH__H
#define SEARCH__H

#include <QtWidgets/QLineEdit>
#include <QString>

#include <vector>

class Thumbnail;

class Search : public QLineEdit {
    Q_OBJECT
private:
    std::vector<Thumbnail*> *buttons;
public:
    Search(std::vector<Thumbnail*> *buttons);
private slots:
    void textChanged(const QString& text);
};

#endif // SEARCH__H
