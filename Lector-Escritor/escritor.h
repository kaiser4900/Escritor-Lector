#ifndef ESCRITOR_H
#define ESCRITOR_H

#include<QThread>
#include<vector>

class escritor:public QThread
{
    Q_OBJECT

    int *BaseDatos;
    int *n_l;
    int *n_e;


public:
    escritor(QObject *parent = nullptr);
    void set(int B1,int a, int b);
signals:
    void escribir(QString);
protected:
    void run() override;
};

#endif // ESCRITOR_H
