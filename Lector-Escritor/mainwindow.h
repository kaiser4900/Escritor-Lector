#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class escritor;
class lector;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    int BaseDatos=0;
    int n_l;
    int n_e;


    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    escritor * c1_thread;
    lector * c2_thread;
signals:
    void tiempo(int);
};

#endif // MAINWINDOW_H
