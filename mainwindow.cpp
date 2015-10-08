#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "webmconverter.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionInformation_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{
    QString  filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files (*.*);;Video File (*.txt)"

                );
    QMessageBox::information(this,tr("File name"),filename);
    WebmConverter  convert;
    convert.set_base_filename(filename);
    ui->lineEdit->setText(convert.get_base_filename());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename2= QFileDialog::getSaveFileName(
                this,
                tr("Save File"),
                "C://",
                tr("video(*.txt)")
               );
}

void MainWindow::on_pushButton_clicked()
{
    WebmConverter convert;
    convert.set_base_filename(ui->lineEdit->text());
    convert.set_qmax(-1);
    convert.set_qmin(-1);
    convert.set_crf(-1);
    convert.set_seg_start(ui->spinBox->value()*60+ui->spinBox_2->value());
    convert.set_seg_end(ui->spinBox_3->value()*60+ui->spinBox_4->value());
    QString name=ui->lineEdit->text();
    convert.set_base_filename(name);
    name.chop(3);
    name=name+"webm";
      QMessageBox::information(this,tr("File name"),name);
    convert.set_output_filename(name);
    convert.convert();
}


