#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include <chrono>


using namespace std;

vector<int>BaseDatos;
int n_l = 0;
int n_e = 0;

void escritor()
{
    int input;
    input = rand()%51;
    while(true)
    {
        std::this_thread::sleep_for (std::chrono::milliseconds(input));
        n_e++;
        if(n_e == 1)
        {
            cout<<"Escribiendo"<<endl;
            BaseDatos.push_back(n_l);
            n_e--;
        }
    }
}

void lector()
{
    int input;
    while(true)
    {
        mutex m;
        m.lock();
        n_l++;
        if(n_e == 0)
        {
            input = rand()%51;
            cout<<"Leyendo"<<endl;
            cout<<"\n\n";
            for(int i = 0; i < BaseDatos.size(); i++)
            {
                cout<<BaseDatos[i]<<" ";
            }
            cout<<"\n\n";
            std::this_thread::sleep_for (std::chrono::milliseconds(input));
            n_l--;
        }
        else
            std::this_thread::sleep_for (std::chrono::milliseconds(input));
        m.unlock();

    }
}
int main()
{
    std::thread thread_1(escritor);
    std::thread thread_2(lector);

    thread_1.join();
    thread_2.join();

    return 0;
}
