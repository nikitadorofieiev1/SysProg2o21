
#include<iostream>
#include<string>
#include<map>
#include <fstream>

using namespace std;

int main(){
    map<char, int> mp;
    string s;
    ifstream f_input("FILE.txt");

    f_input >> s;
    for (auto i: s) mp[i]++;

    for (char i = 'a'; i<='z'; ++i) cout << i <<" "<< mp[i]<<"\n";
    for (char i = 'A'; i<='Z'; ++i) cout << i <<" "<< mp[i]<<"\n";
    fin.close();
}
