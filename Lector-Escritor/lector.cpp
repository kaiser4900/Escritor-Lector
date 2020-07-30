#include "lector.h"
#include <QMutex>

lector::lector(QObject *parent)
    :QThread (parent)
{

}

void lector::set(int B1,int a, int b){
    BaseDatos = &B1;
    n_l = &a;
    n_e = &b;
}

void lector:: run()
{
    int input;
    while(true)
    {
        QMutex m;
        m.lock();
        *n_l+=1;
        if(*n_e == 0)
        {
            input = rand()%51;
            emit leyendo("Leyendo\n");
            std::this_thread::sleep_for (std::chrono::milliseconds(input));
            *n_l-=1;
        }
        else
            std::this_thread::sleep_for (std::chrono::milliseconds(input));
        m.unlock();

    }
}
