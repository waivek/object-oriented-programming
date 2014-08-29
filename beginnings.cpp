using namespace std;
#include <iostream>        // This is a key C++ library
#include <cmath>           // The standard C library math.h
double a = 1800;
char str[100] = "Dragonriders born free to fly";
int main ()
{


   // int b;
   // cout << "Enter the value of b\n";
   // cin >> b;
   // {
   //     double b = 3.14;
   //     cout<<"local b is "<<b<<endl;
   // }
   // cout<<"international b is "<<b<<endl;
    // int i = 900;
    // for(int i = 0; i < 10; i++) {
    //     cout<<"The value of i is "<<i<<endl;
    // }
    // cout<<"The value of awesome i is "<<i<<endl;
    cout<<"Global variable a is:"<<::a<<endl;
    cout<<"Global string str is:"<<::str<<endl;
    
    return 0;
}


