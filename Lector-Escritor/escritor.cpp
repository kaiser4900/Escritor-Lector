#include "escritor.h"

escritor::escritor(QObject *parent)
    :QThread (parent)
{

}


void escritor::set(int B1,int a, int b){
    BaseDatos = &B1;
    n_l = &a;
    n_e = &b;
}


void escritor::run()
{
    int input;
    input = rand()%51;
    while(true)
    {
        std::this_thread::sleep_for (std::chrono::milliseconds(input));
        *n_e+=1;
        if(*n_e == 1)
        {
            emit escribir("Escribiendo\n");
            *BaseDatos+=1;
            *n_e-=1;
        }
    }
}
