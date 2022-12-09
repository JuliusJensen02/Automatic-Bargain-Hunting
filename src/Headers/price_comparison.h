

#ifndef AUTOMATIC_BARGAIN_HUNTING_PRICE_COMPARISON_H
#define AUTOMATIC_BARGAIN_HUNTING_PRICE_COMPARISON_H

typedef struct{
    char store[20];
    double total;
} individual_stores;

void compare_prices(char **grocery_list, int number_of_list_items, items_data *item_data);
void printPrices_multiple_stores(int number_of_list_items);
double total_multiple_store_price (int number_of_list_items);

#endif //AUTOMATIC_BARGAIN_HUNTING_PRICE_COMPARISON_H
