#include <iostream>
#include <fstream>
#include "lab7.h"

using namespace std;

// TODO1: Reorder the linked list so that VIP customers come first
// Your would need to reorder the entries in the given array, with VIP customers comes first
//      Both the VIP customers and the normal customers would be then ordered by their ID repectively
//      Example: ID0_VIP, ID1_Non_VIP, ID2_VIP => ID0_VIP, ID2_VIP, ID1_Non_VIP
void reorder_customer(Customer *queue[], int num_customer)
{
    int index_of_VIP = -1;
    int num = 0;
    for (int i = 0; i < num_customer; i++)
    {
        if (queue[i]->vip)
        {
            Customer *temp=queue[index_of_VIP + 1];
            queue[index_of_VIP + 1] = queue[i];
            queue[i] = temp;
            index_of_VIP++;
            num++;
        }
    }
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (queue[j]->id > queue[j + 1]->id)
            {
                Customer *temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
    for (int i = num; i < num_customer - 1; i++)
    {
        for (int j = num; j < num_customer - i - 1+num; j++)
        {
            if (queue[j]->id > queue[j + 1]->id)
            {
                Customer *temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    return;
}

// TODO2: Let customers check out from the store, and get the money
// Customers comes in the ordered of the array
// For each of the customers' needs, if the store can satisfy it, sell the corresponding amount and get the paid money, otherwise skip this need (sell nothing and earn nothing)
//      Example: If a customer need 5 Apples and 5 Bananas and the store have 10 Apples and 2 Bananas left, then sell 5 Apples (and 0 Bananas) to the customer
// You don't need to delete the pointers to customers in this TODO
int check_out(Fruit fruits[], const Customer *const queue[], int num_fruit, int num_customer)
{
    int money=0;
    for (int i = 0; i < num_customer; i++)
    {
        for (int j = 0; j < num_fruit; j++)
        {
            if (queue[i]->need[j] <= (fruits[j].total_count - fruits[j].sold_count))
            {
                fruits[j].sold_count += queue[i]->need[j];
                money += queue[i]->need[j] * fruits[j].unit_price;
            }
        }
    }
    return money;
}