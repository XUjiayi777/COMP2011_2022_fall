#include <iostream>
using namespace std;

int main(){
    cout<<"Enter the size: ";
    int size=0;
    cin >> size;

    char symbol = '*';
    int j=0;
    while (j<size)
    {
        cout<<symbol;
        j++;
    }
    return 0;
}