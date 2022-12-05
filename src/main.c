#include <stdio.h>
#include "Headers/Data_collection.h"
#include "Headers/Function.h"
#include "Headers/Comparison.h"

items           available_items[NUMBER_OF_ITEMS]; // sets size of struct array
items_data      item_data_stores_prices[NUMBER_OF_ITEMS*NUMBER_OF_STORES]; // sets size of struct array
int             number_of_list_items = 0;
char            **grocery_list;

int main(void)
{

    loadData(available_items, item_data_stores_prices);
    user_input(grocery_list, number_of_list_items);

    printf("Final Grocery List:\n");

    print_grocery_list(grocery_list, number_of_list_items);

    compare_prices(grocery_list, number_of_list_items, item_data_stores_prices);


    free(grocery_list);

    return 0;
}

