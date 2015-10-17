#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Information");
    ui->label->setWordWrap(true);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setWordWrap(true);
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setAlignment(Qt::AlignCenter);
    //ui->label->resize(this->width(), this->height());
    ui->label->setText("This program was written by Pasha, Slavik and DimaSS");
    ui->label_2->setText("© webm-converter 2015");
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
