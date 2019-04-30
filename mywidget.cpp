#include "mywidget.h"
#include "ui_mywidget.h"
#include <QLabel>
#include <QMovie>
#include <QDir>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    QString currentPath;
    QDir dir;
    currentPath=dir.currentPath();
    qDebug()<<"path"<<currentPath;
    QDir temDir("../test07/wait.gif");
    QString filePath = temDir.absolutePath();
    qDebug()<<filePath<<endl;


    ui->setupUi(this);
    QMovie *movie = new QMovie(filePath);
    ui->label->setMovie(movie);
    movie->start();
    this->resize(1000,600);
    this->setFixedSize(1000,600);
}

MyWidget::~MyWidget()
{
    delete ui;
}
