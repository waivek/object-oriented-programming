using namespace std;
#include <iostream>        // This is a key C++ library
#include <cmath>           // The standard C library math.h

int main ()
{


   int b;
   cout << "Enter the value of b\n";
   cin >> b;
   {
       double b = 3.14;
       cout<<"local b is "<<b<<endl;
   }
   cout<<"international b is "<<b<<endl;

   return 0;
}


