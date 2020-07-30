#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lector.h"
#include "escritor.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c1_thread = new escritor(this);
    c1_thread->set(BaseDatos,n_l,n_e);


    c2_thread = new lector(this);
    c2_thread->set(BaseDatos,n_l,n_e);


    connect(c1_thread, &escritor::escribir, ui->textBrowser, &QTextBrowser::append);
    connect(c2_thread, &lector::leyendo, ui->textBrowser, &QTextBrowser::append);
    connect(this, SIGNAL(tiempo(int)),ui->lcdNumber,SLOT(display(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
clock_t inicio;
clock_t fin;
void MainWindow::on_pushButton_clicked()
{
    c1_thread->start();
    c2_thread->start();
    srand(time(NULL));
    inicio = clock();
}

void MainWindow::on_pushButton_2_clicked()
{
    c1_thread->terminate();
    c2_thread->terminate();
    srand(time(NULL));
    fin = clock();
    emit tiempo(fin-inicio);
}
