
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <chrono>
using namespace std;

int main()
{
    cout << "           malloc calloc alloca\n";

    for (long long x = 0; x<=64; ++x){
        cout << "x: "<< x<<"| time: ";
        {
            auto start_time = std::chrono::steady_clock::now();
            char *test1 = (char*)malloc(sizeof(char) * (1LL << x));
            char *test2 = (char*)malloc(sizeof(char) * (1LL << (x + 1)));
            auto end_time = std::chrono::steady_clock::now();
            free(test1);
            free(test2);
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        cout << elapsed_ms.count()<<"       ";
        }
        {

            auto start_time = std::chrono::steady_clock::now();
            char *test1 = (char*)calloc((1LL << x), sizeof(char));
            char *test2 = (char*)calloc((1LL << (x + 1)), sizeof(char));
            auto end_time = std::chrono::steady_clock::now();
            free(test1);
            free(test2);
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        cout << elapsed_ms.count()<<"       \n";

        }

       /* {
            auto start_time = std::chrono::steady_clock::now();

            char *test1 = (char*)alloca((1LL << x));

            char *test2 = (char*)alloca((1LL << (x + 1)));


            auto end_time = std::chrono::steady_clock::now();

            auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
            cout << elapsed_ms.count()<<"\n";
        }*/

    }


}
