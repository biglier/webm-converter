#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("WEBM Converter");

    _wbm_converter = new WebmConverter();

    this->resize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

    ui->comboBox->addItem("vp8");
    ui->comboBox->addItem("vp9");

    _about_window = new AboutWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (_wbm_converter) {
        delete _wbm_converter;
    }
    delete _about_window;

}

void MainWindow::on_actionInformation_triggered()
{
    _about_window->show();
}

void MainWindow::on_actionOpen_triggered()
{
    QString  filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files (*.*);;Video File (*.txt)"

                );

    _wbm_converter->set_base_filename(filename);

    QString output_filename = filename;
    output_filename.chop(3);
    output_filename += "webm";

    if (ui->spinBox_5->value() > 64) {
        QMessageBox::information(this,tr("Error"), "Value should not be greater than 6");
    } else {
        _wbm_converter->set_crf(ui->spinBox_5->value());
    }

    ui->lineEdit->setText(_wbm_converter->get_base_filename());
    ui->lineEdit_2->setText(output_filename);
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

int MainWindow::set_button_text()
{
    ui->pushButton->setText("Converting...");
    this->repaint();

    return 1;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setText("Converting...");
    this->repaint();

    _wbm_converter->set_output_filename(ui->lineEdit_2->text());
    _wbm_converter->set_seg_start(ui->spinBox->value() * 60 + ui->spinBox_2->value());
    _wbm_converter->set_seg_end(ui->spinBox_3->value() * 60 + ui->spinBox_4->value());
    _wbm_converter->set_codec(ui->comboBox->currentText());
    _wbm_converter->set_crf(ui->spinBox_5->value());

    _wbm_converter->create_exec_script();

    _wbm_converter->convert();

    QMessageBox::information(this, tr("Done"), "All done. Please enjoy your new webm");
    this->ui->pushButton->setText("Convert");
}



void MainWindow::on_actionSave_configuration_triggered()
{
    _config_file_handler.write_config_file(_wbm_converter);
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionRead_configuration_triggered()
{
    _config_file_handler.read_config_file(_wbm_converter);
    ui->lineEdit->setText(_wbm_converter->get_base_filename());
    ui->lineEdit_2->setText(_wbm_converter->get_output_filename());
    ui->spinBox->setValue(_wbm_converter->get_seg_start() / 60);
    ui->spinBox_2->setValue(_wbm_converter->get_seg_start() % 60);
    ui->spinBox_3->setValue(_wbm_converter->get_seg_end() / 60);
    ui->spinBox_4->setValue(_wbm_converter->get_seg_end() % 60);
    ui->spinBox_5->setValue(_wbm_converter->get_crf());
}
