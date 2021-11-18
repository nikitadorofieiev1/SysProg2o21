#include<iostream>
#include<vector>
#include<algorithm>
#include <fstream>

using namespace std;

int main(){
    char ch;
    vector<char> table;
    while(1){
        cin >> ch;
        if ((ch>='a' && ch <='z') || (ch>='A' && ch <='Z') ) table.push_back(ch);
        else break;
    }
    sort(table.begin(), table.end());

    ofstream f_output("FILE.txt");



    for (auto i: table)
        f_output << i;
    f_output.close();
}
