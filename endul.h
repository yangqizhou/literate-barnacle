#ifndef ENDUL_H
#define ENDUL_H

#include <QDockWidget>

namespace Ui {
class endUl;
}

class endUl : public QDockWidget
{
    Q_OBJECT

public:
    explicit endUl(QWidget *parent = 0);
    ~endUl();

private:
    Ui::endUl *ui;
};

#endif // ENDUL_H
