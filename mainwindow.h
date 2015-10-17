#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "aboutwindow.h"
#include "webmconverter.h"
#include "iomodule.h"

#define DEFAULT_WINDOW_HEIGHT 270
#define DEFAULT_WINDOW_WIDTH 536
#define FULL_WINDOW_HEIGHT 400

#define NORMAL_EXIT 0
#define CRASH_EXIT 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionInformation_triggered();

    void on_actionOpen_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    int set_button_text();
    
    void on_actionSave_configuration_triggered();

    void on_actionQuit_triggered();

    void on_actionRead_configuration_triggered();

private:
    Ui::MainWindow *ui;
    WebmConverter *_wbm_converter;
    AboutWindow *_about_window;
    IOModule _config_file_handler;
};

#endif // MAINWINDOW_H
