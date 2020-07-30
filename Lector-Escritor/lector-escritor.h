#ifndef LECTORESCRITOR_H
#define LECTORESCRITOR_H
#include "ui_mainwindow.h"
#include<QThread>
#include <QMutex>
#include <vector>

std::vector<int>BaseDatos;
int n_l = 0;
int n_e = 0;




void lector(QTextBrowser *a)
{
    int input;
    while(true)
    {
        QMutex m;
        m.lock();
        n_l++;
        if(n_e == 0)
        {
            input = rand()%51;
            a->append("Leyendo\n");
            a->append("\n\n");
            for(int i = 0; i < BaseDatos.size(); i++)
            {
                a->append(BaseDatos[i]+" ");
            }
            a->append("\n\n");
            std::this_thread::sleep_for (std::chrono::milliseconds(input));
            n_l--;
        }
        else
            std::this_thread::sleep_for (std::chrono::milliseconds(input));
        m.unlock();

    }
}



#endif // LECTORESCRITOR_H
