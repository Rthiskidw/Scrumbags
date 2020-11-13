#include "secdialog.h"
#ifndef MAINWINDOW_H_
#define MAINWNDOW_H_

#include <QMainWindow>
//#include "secdialog.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

private:
        Ui::MainWindow *ui;
        SecDialog *secDialog;
};

#endif

