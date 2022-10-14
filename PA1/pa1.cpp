#include <iostream>
#include <ctime>
using namespace std;

/* -------------------------------------------------------------- */
/* This part serves as a pseudo random number generator for auto grade purpose only */
/* You are suggested not to refer to these codes in this assignment. */
/* You are not allowed to use global variables in this course. */
unsigned int next_num = 1; // Here we initiate an unsigned integer to be used in the following functions.

unsigned int pa1_rand() // This function is used to return a pseudo random number from 0 to 32767.
{
    next_num = next_num * 1103515245 + 2011;
    return static_cast<unsigned int>(next_num / 65536) % 32768;
}
void pa1_srand(unsigned int seed) // This function is used to set a seed of the pseudo random number generator.
{
    next_num = seed;
}
/* Everytime you call pa1_rand(), you will get a new pseudo random number. For the same seed, the sequence of pseudo
   random number is fixed. For example, when seed = 3, the sequence of pseudo random number is fixed to be [17746,
   30897, 9622, 18921, 4034, 17510, 24152, 14388, 23665, 31532, ...]. When seed = 5, the sequence of pseudo random
   number is fixed to be [18655, 32247, 9873, 9718, 26373, 27678, 5314, 22512, 31845, 22885, ...] */
/* -------------------------------------------------------------- */

const int MAX_BOXES = 1000; // This constant stores the largest length of boxes[]. You can use it in your code.

// This function is used to fill the 1D array with a random sequence of unique numbers from 1 to the user input for the number of prisoners
void placeSlips(int boxes[], int num_prisoners)
{
    for (int i = 0; i < num_prisoners; i++)
        boxes[i] = -1;
    int counter = 0;
    while (counter < num_prisoners)
    {
        int num = pa1_rand() % (num_prisoners);
        if (boxes[num] == -1)
        {
            boxes[num] = counter;
            counter++;
        }
    }
}

// TASK 1: Simulate an actual riddle room
bool simulateRoom(const int boxes[], int num_prisoners, int num_trials)
{
    /* Please replace this to your own code below */
    int find_box = 0;
    for (int k = 0; k < num_prisoners; k++)
    {
        int box_number = k;
        for (int j = 0; j < num_trials; j++)
        {
            if (boxes[box_number] != k)
            {
                box_number = boxes[box_number];
                continue;
            }
            else
            {
                find_box++;
                break;
            }
        }
    }
    if (find_box == num_prisoners)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// TASK 2: Display certain statistics for a given room
void statsRoom(const int boxes[], int num_prisoners, int num_trials)
{
    /* Here in this task, we provide some lines of code for your reference. Please write your code below and replace some of the given code */
    int num_loops = 0;
    int fake_boxes[MAX_BOXES] = {};
    int num_array[MAX_BOXES] = {};
    int count = -1;
    int prisoner_find_slips = 0;

    for (int i = 0; i < num_prisoners; i++)
    {
        fake_boxes[i] = boxes[i];
    } // construct fake boxes

    for (int j = 0; j < num_prisoners; j++)
    {
        if (fake_boxes[j] >= 0) // examine if the elements is larger than or equal to 0 or not
        {
            int boxnum = j;
            int num = 0;
            bool find = false;
            while (!find)
            {
                if (boxes[boxnum] != j)
                {
                    fake_boxes[boxnum] = count;
                    boxnum = boxes[boxnum];
                }
                else
                {
                    fake_boxes[boxnum] = count;
                    find = true;
                }
                num++;
            }

            num_array[-count - 1] = num;
            count--;
            if (num_trials >= num)
            {
                for (int s = 0; s < num; s++)
                {
                    prisoner_find_slips++;
                }
            } // finsh the number of prisoners who find their slips
        }
    }

    while (true)
    {
        if (num_array[num_loops] != 0)
        {
            num_loops++;
        }
        else
        {
            break;
        }
    }
    // until now, finish the number of loops

    int smallest_loop_len = MAX_BOXES + 1;
    int largest_loop_len = -1;
    int largest_loop[MAX_BOXES] = {};
    int largest_loop_ordered[MAX_BOXES] = {};
    int smallest_slip = MAX_BOXES;

    for (int p = 0; p < num_loops; p++)
    {
        if (num_array[p] > largest_loop_len)
        {

            largest_loop_len = num_array[p];
            for (int k = 0; k < largest_loop_len;)
            {
                for (int f = 0; f < num_prisoners; f++)
                {
                    if (fake_boxes[f] == (-p - 1))
                    {
                        largest_loop[k] = boxes[f];
                        k++;
                    }
                }
            } // finish largest loop (unordered)
        }
        else if (num_array[p] < smallest_loop_len)
        {
            smallest_loop_len = num_array[p];
        }
    }
    // finsh the length part

    for (int d = 0; d < largest_loop_len; d++)
    {
        if (largest_loop[d] < smallest_slip)
        {
            smallest_slip = largest_loop[d];
        }
    } // find the smallest slip
    largest_loop_ordered[0] = smallest_slip;

    int index = 0;
    int w = 0;
    for (w = 0; w < num_prisoners; w++)
    {
        if (boxes[w] == smallest_slip)
        {
            index = w;
        }
    } // find the smallest slip index

    cout << "The number of prisoners who find their slips: "
         << prisoner_find_slips << endl;
    cout << "Number of loops: "
         << num_loops << endl;
    cout << "Smallest loop length: "
         << smallest_loop_len << endl;
    cout << "Longest loop length: "
         << largest_loop_len << endl;
    cout << "Largest loop: ";
    for (int a = 0; a < largest_loop_len; a++)
    {
        // int box=boxes[smallest_slip];
        largest_loop_ordered[a] = boxes[index];
        index = boxes[index];
        cout << largest_loop_ordered[a] << " ";
    }

    cout << endl;
}

// TASK 3: Find the number of instances in 1000 rooms when the prisoners will all be able to escape
double successRooms(int boxes[], int num_prisoners, int num_trials) //  suceess rate of 1000 rooms basically repeating it a 1000 times
{
    int room_numbers = 1000;
    int success = 0;
    for (int i = 0; i < room_numbers; i++)
    {
        placeSlips(boxes, num_prisoners);
        if (simulateRoom(boxes, num_prisoners, num_trials) == true)
        {
            success++;
        }
    }
    return success;
}

// TASK 4: Nice guard will help the prisoners to successfully leave the room by breaking any loop which is greater than the number of trials
//         Return true if the intervention was applied, else return false
bool niceGuard(int boxes[], int num_prisoners, int num_trials)
{
    int fake_boxes[MAX_BOXES] = {};
    int num_array[MAX_BOXES] = {};
    int count = -1;

    for (int i = 0; i < num_prisoners; i++)
    {
        fake_boxes[i] = boxes[i];
    } // construct fake boxes

    for (int j = 0; j < num_prisoners; j++)
    {
        if (fake_boxes[j] >= 0) // examine if the elements is larger than or equal to 0 or not
        {
            int boxnum = j;
            int num = 0;
            bool find = false;
            while (!find)
            {
                if (boxes[boxnum] != j)
                {
                    fake_boxes[boxnum] = count;
                    boxnum = boxes[boxnum];
                }
                else
                {
                    fake_boxes[boxnum] = count;
                    find = true;
                }
                num++;
            }

            num_array[-count - 1] = num;
            count--;
        }
    }

    int num_loops = 0;
   

    while (true)
    {
        if (num_array[num_loops] != 0)
        {
            num_loops++;
        }
        else
        {
            break;
        }
    }

    for (int p = 0; p < num_loops; p++)
    {
        if (num_array[p] > num_trials)
        {
        
            int index_array[MAX_BOXES] = {};
            int loop_len = 0;
            loop_len = num_array[p];
            for (int k = 0; k < loop_len;)
            {
                for (int f = 0; f < num_prisoners; f++)
                {
                    if (fake_boxes[f] == (-p - 1))
                    {
                        index_array[k] = f;
                        k++;
                    }
                }
            } // finish generating index_array

            for (int t = 0; t < loop_len; t++)
            {
                int temp = 0;
                int success = 0;

                temp = boxes[index_array[t]];
                boxes[index_array[t]] = boxes[index_array[t + 1]];
                boxes[index_array[t + 1]] = temp; // change boxes

                for (int z = 0; z < num_prisoners; z++)
                {
                    int boxnum1 = z;
                    int num1 = 0;
                    bool find = false;

                    while (!find)
                    {
                        if (boxes[boxnum1] != z)
                        {
                            boxnum1 = boxes[boxnum1];
                        }
                        else
                        {
                            find = true;
                        }
                        num1++;
                    } // calculate the loop length again

                    if (num1 > num_trials)
                    {
                        success++;
                    }
                }
                if (success == 0)
                {
                    return true;
                }
            }
        }
    }


        return false;

}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED.

int main()
{

    int num_prisoners, num_trials, seed;
    // set boxes, priosoners

    cout << "Enter the number of prisoners (from 1 to 1000) :" << endl;
    cin >> num_prisoners;
    cout << "Enter the number of boxes each prisoner can open (from 1 to 1000) :" << endl;
    cin >> num_trials;
    cout << "Enter the seed for randomization else enter 0 and the system will randomize for you :" << endl;
    cin >> seed;

    if (seed == 0)
    {
        pa1_srand(time(NULL));
    }
    else
    {
        pa1_srand(seed);
    }

    int boxes[MAX_BOXES]; // array for the boxes
    for (int i = 0; i < MAX_BOXES; i++)
        boxes[i] = 0;

    int choice;
    cout << "Please choose an option:" << endl;
    cout << "0.Print the boxes" << endl;
    cout << "1.Simulate a room" << endl;
    cout << "2.Compute statistics of a room:" << endl;
    cout << "3.Compute success rate over 1000 rooms" << endl;
    cout << "4.Apply nice guard intervention in a room" << endl;
    cin >> choice;

    switch (choice)
    {
    case 0:
        placeSlips(boxes, num_prisoners);
        for (int i = 0; i < num_prisoners; i++)
            cout << boxes[i] << " ";
        cout << endl;
        break;
    case 1:
        placeSlips(boxes, num_prisoners);
        if (simulateRoom(boxes, num_prisoners, num_trials) == true)
        {
            cout << "Success! All prisoners found their slip." << endl;
        }
        else
        {
            cout << "Failure! Not all prisoners were able to find their slip." << endl;
        }
        break;
    case 2:
        placeSlips(boxes, num_prisoners);
        statsRoom(boxes, num_prisoners, num_trials);
        break;
    case 3:
    {

        double prisoners_left = successRooms(boxes, num_prisoners, num_trials);
        cout << "All prisoners were able to leave " << prisoners_left << "/1000 of the rooms." << endl;
    }
    break;
    case 4:
    {
        placeSlips(boxes, num_prisoners);
        int copy_arr[MAX_BOXES];
        for (int i = 0; i < num_prisoners; i++)
        {
            copy_arr[i] = boxes[i]; // copying the array for checking if no more than 2 swaps are made
        }

        bool nice_guard_val = niceGuard(boxes, num_prisoners, num_trials);

        int swap_count = 0;
        for (int j = 0; j < num_prisoners; j++)
        {
            if (copy_arr[j] != boxes[j])
            {
                swap_count++;
            }
        }
        if (swap_count > 2)
        {
            cout << "Illegal intervention as you have more than 1 swap " << endl;
        }
        else
        {
            if (nice_guard_val == false)
                cout << "No intervention needed." << endl;
            else
            {
                cout << "Intervention applied." << endl;
                // validity function
                bool prisoners_left = simulateRoom(boxes, num_prisoners, num_trials);
                // should return true
                if (prisoners_left == true)
                    cout << "All the prisoners were able to escape" << endl;
                else
                {
                    cout << "All the prisoners were not able to escape" << endl;
                }
            }
        }
    }
    break;
    }

    return 0;
}