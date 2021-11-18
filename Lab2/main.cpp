
#include <iostream>
#include <ctime>
using namespace std; 

int main()
{
    srand( time(0) );
    cout <<"Enter the char(r,s,p): ";
    char ch;
    cin >> ch;
    int rnd = rand()%3;
    if (ch == 'r'){
        if (rnd == 0) cout <<"Draw!!!\n";
        else if (rnd == 1) cout <<"Winner!!!\n";
        else if (rnd == 2) cout <<"Loser!!!\n";
    }
    else if (ch == 's'){
        if (rnd == 0) cout <<"Loser!!!\n";
        else if (rnd == 1) cout <<"Draw!!!\n";
        else if (rnd == 2) cout <<"Winner!!!\n";
    }
    else if (ch == 'p'){
        if (rnd == 0) cout <<"Winner!!!\n";
        else if (rnd == 1) cout <<"Loser!!!\n";
        else if (rnd == 2) cout <<"Draw!!!\n";
    }
    else cout <<"Incorrect input!!!\n";
    return 0;
}
