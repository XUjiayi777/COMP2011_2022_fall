#include "stock_management.h"

void stock_checking(const Fruit fruits[], int max_fruit_num)
{   
    //todo: print (name, total_count) pairs of each kind of fruit.
    //For example the last printed line should be watermelon: 10
    for(int i=0;i<max_fruit_num;i++){
        cout<<fruits[i].name<<": "<<fruits[i].total_count<<endl;
    }
    return;
}

void stock_updating(Fruit fruits[], int fruit_id_to_sell, int number_to_sell){
    //todo: update total_count of the sold fruit
    for(int i=0;i<MAX_FRUIT_NUM;i++){
        if (i==fruit_id_to_sell){
            fruits[i].total_count-=number_to_sell;
            fruits[i].sold_count=number_to_sell;
        }
    }
    return;
}

float selling_amount_calculating(const Fruit fruits[], int max_fruit_num){
    float selling_amount = 0;
    // todo: calculate selling amount of all fruits; for each fruit this number should be the multiplication of unit price and sold count
    for(int i=0;i<max_fruit_num;i++){
        if (fruits[i].sold_count!=0){
            selling_amount += fruits[i].sold_count*fruits[i].unit_price;
        }   
    }
    return selling_amount;
}
