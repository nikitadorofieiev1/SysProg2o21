#include <iostream>
#include <ctime>

using namespace std;

int main()
{
   time_t sec = time(NULL);
   cout<<asctime(localtime(&sec));
   return 0;
}
