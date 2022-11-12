#include <iostream>
using namespace std;
const unsigned int MAX_FRUIT_NUM = 5;
const int MAX_LENGTH = 50;

struct Fruit
{
    char name[MAX_LENGTH];
    float unit_price;
    int total_count;
    int sold_count;
};

extern void stock_checking(const Fruit*, int);
extern void stock_updating(Fruit*, int, int);
extern float selling_amount_calculating(const Fruit*, int);
