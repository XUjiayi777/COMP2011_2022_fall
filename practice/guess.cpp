#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int target = rand() % 100 + 1;
    int guess = 0, // initialize it to a value outside lower & upper
        lower = 1, upper = 100;
    // int type
    int player = 1;
    // char type
    // char player = 'A';

    while (target != guess)
    {
        // do{
        do
        {
            cout << "Please enter a number between "
                 << lower << " and " << upper << ":";
            cin >> guess;
        } while ((guess < lower) || (guess > upper));

        if (guess == target)
            cout << "You win!" << endl;
        else if (guess < target)
        {
            cout << "The number should be larger" << endl;
            lower = guess + 1;
        }
        else
        {
            cout << "The number should be smaller" << endl;
            upper = guess - 1;
        }
        // for int player
        player = player % 2 + 1;
        // for char type
        // player = (player =='A')?'B':'A'
        // if (player=='A')
        //     player = 'B';
        // else
        //     player='A';
    }
    //} while (target!= guess);
    return 0;
}