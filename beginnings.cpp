using namespace std;
#include <iostream>        // This is a key C++ library
#include <cmath>           // The standard C library math.h
double a = 1800;
char str[100] = "Dragonriders born free to fly";
void change(double &r, double s) {
    r = 100;
    s = 200;
}
double &biggest (double &r, double &s) {
    if ( r > s ) return r;
    else         return s;
}
double *silly_function() {
    static double r = 342;
    return &r;
}
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
    // cout<<"Global variable a is:"<<::a<<endl;
    // cout<<"Global string str is:"<<::str<<endl;
    // double a = 3.14;
    // double &b = a;
    // 
    // b = 100;
    // cout << "The value of a is " << a << endl;
    // cout << "Enter something here please ";
    // int x;
    // cin >> x;
    // double k, m;
    // k = 3;
    // m = 4;
    // change(k, m);
    // cout << "k " << k << endl;
    // cout << "m " << m << endl;
//    double k = 3;
//    double m = 7;
//    cout << "k " << k << endl;
//    cout << "m " << m << endl;
//    cout << endl;
//
//    biggest(k, m) = 10;
//    
//    cout << "k " << k << endl;
//    cout << "m " << m << endl;
//    cout << endl;
//
//    biggest(k, m) ++;
//    
//    cout << "k " << k << endl;
//    cout << "m " << m << endl;
//    cout << endl;
//    double *a;
//    
//    a = silly_function();
//
//    double &b = *a;
//
//    b+= 1;
//    b = b * b;
//    b += 4;
//
//    cout << "*a " << *a << endl;
//    cout << "b " << b << endl;
    return 0;
}


