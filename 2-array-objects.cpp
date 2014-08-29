#include <iostream>
using namespace std;
class Programming {
    int x, y;
public:
    void input(){
        cout <<"Input two integers\n";
        cin >> x >> y;
    }
    void output() {
        cout << "Result = " << x + y << endl;
    }
    void power_four() {
        int z = 0;
        cout<<"Input number to be raised to the power 4\n";
        cin>>z;
        int power_two(int base) {
            return base * base;
        }
        cout<<"Input to the power 4 is "<<power_two(power_two(z))<< endl;
};
int main(){
        Programming ob;
        ob.power_four();
        return 0;
}
