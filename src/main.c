#include <stdio.h>
#include "Headers/data_collection.h"
#include "Headers/user_input.h"
#include "Headers/price_comparison.h"

items_data      item_data_stores_prices[NUMBER_OF_ITEMS*NUMBER_OF_STORES]; // sets size of struct array
int             number_of_list_items = 0;
char            **grocery_list;

int main(void)
{

    loadData(item_data_stores_prices);
    user_input(&number_of_list_items, item_data_stores_prices);

    grocery_list = malloc(sizeof(char*) * (number_of_list_items + 1));
    exit_failure(grocery_list);
    grocery_list[0] = "first";

    assign_grocery_list(grocery_list, number_of_list_items);

    if (strcmp(grocery_list[0], "first") != 0)
    {
        compare_prices(grocery_list, number_of_list_items, item_data_stores_prices);
    }

    free(grocery_list);

    return 0;
}

