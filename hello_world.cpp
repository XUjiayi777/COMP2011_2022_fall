#include <iostream>
using namespace std;
int main()
{
    int x = 100, y = 100;
    int a = 10, b = 10, c = 10, d = 10;
    b = a + (x++) + ++y;
    cout << ++x << "\t";
    cout << "x=" << x << endl;
    cout << y++ << "\t";
    cout << "y=" << y << endl;

    a = ++b;
    cout << "a=" << a << "\t"
         << "b=" << b << endl;
    c = d++;
    cout << "c = " << c << "\t"
         << "d = " << d << endl;

int oo = 9;
cout<<oo++++++;

}