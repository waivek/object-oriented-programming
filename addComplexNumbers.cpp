// Add two complex numbers
// Help understand how to return objects
#include <iostream>
using namespace std;
class Complex {
    public:
        double real;
        double imag;
    public:
        void set(double x, double y);
        void print();
        Complex(double x, double y);
};
Complex::Complex(double x, double y){
    real = x;
    imag = y;
    print();
}
void Complex::print(){
    cout << real << " + " << imag << "i\n";
}
void Complex::set(double x, double y) {
    real = x;
    imag = y;
}
Complex add(Complex z1, Complex z2) {
    return Complex(z1.real + z2.real, z1.imag + z2.imag);
}
int main(){
    Complex a(7.28, 2.91);
    Complex b(9.13, 8.20);
    Complex c = add(a, b);
    cout << "Sum is ";
    c.print();

}
