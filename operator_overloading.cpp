/*
 * Demonstrate operator overloading
 * Utilizes friend and member function
 */
#include <iostream>
using namespace std;
class Complex {
    public:
        double real;
        double imag;
    public:
        void set(double x, double y);
        void print();
        // Complex operator+(Complex& b);
        Complex(double x, double y);
        friend Complex operator-(const Complex b);
        Complex operator+(const Complex b) {
            return Complex(this->real + b.real, this->imag + b.imag);
        }
};

Complex operator-(const Complex b) {
    return Complex(real - b.real, imag - b.imag);
}

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
// Complex Complex::operator+(const Complex& b) {
//     Complex sum;
//     set(this->real + b.real, this->imag + b.imag);
//     return sum;
// }
// Complex add(Complex z1, Complex z2) {
//     return Complex(z1.real + z2.real, z1.imag + z2.imag);
// }
int main(){
    Complex a(7.28, 2.91);
    Complex b(9.13, 8.20);
    //Complex c = add(a, b);
    Complex c = a - b;
    cout << "Sum is ";
    c.print();

}
