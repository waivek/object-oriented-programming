#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::cout;
int main() 
{
    // ofstream fo("abc.txt");
    // fo << "Hi I'm Carl";
    // getchar();
    return 1;
    ifstream fi("abc.txt");
    char buffer[100];
    while(fi) {
        cout << "VIVEK BOSE\n";
        fi.getline(buffer, 100);
        cout << "\t" << buffer;
    }
}
