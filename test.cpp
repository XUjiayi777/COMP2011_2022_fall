#include <iostream>
using namespace std;

int main()
{
    const char* FRUIT_NAME[5] = {"Apple", "Banana", "Strawberry", "Peach", "Watermelon"};

    char x = 'a';
    char *y = &x;

    cout << y;
}