#include "endul.h"
#include "ui_endul.h"

endUl::endUl(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::endUl)
{
    ui->setupUi(this);
}

endUl::~endUl()
{
    delete ui;
}
