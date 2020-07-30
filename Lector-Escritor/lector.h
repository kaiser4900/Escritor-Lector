#ifndef LECTOR_H
#define LECTOR_H
#include<QThread>


class lector:public QThread
{

    Q_OBJECT
    int *BaseDatos;
    int *n_l;
    int *n_e;

public:
    lector(QObject *parent = nullptr);
    void set(int B1,int a, int b);
signals:
    void leyendo(QString);

protected:
    void run() override;
};

#endif // LECTOR_H
