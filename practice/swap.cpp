#include <iostream> /* File: for-continue.cpp */
using namespace std;
int main()
{
for (int j = 1; j <= 10; j++)
{
cout << "j = " << j << endl;
if (j == 3)
{
j = 10;
break; // What if it is replaced by break;
}
}
return 0;
}
