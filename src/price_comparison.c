#include "Headers/data_collection.h"
#include "Headers/user_input.h"
#include <ctype.h>

typedef struct{
    char store[20];
    double total;
}individual_stores;

typedef struct{
    char cheapest_store[20];
    char cheapest_item[20];
    double price;
}multiple_stores;

void compare_prices(char **grocery_list, int number_of_list_items, items_data *item_data);
void calculate_prices(int j, items_data *item_data);
void transfer_stores(int j, items_data *item_data);
void printPrices(void);
void printPrices_multiple_stores(int number_of_list_items);
void transfer_items_multiple_stores(int j, items_data *item_data);
int cmp_fnc(const void* a, const void* b);
double total_multiple_store_price (int number_of_list_items);

individual_stores individual_store_total[NUMBER_OF_STORES]; // sets size of struct array
multiple_stores multiple_stores_total[NUMBER_OF_ITEMS*NUMBER_OF_STORES]; // sets size of struct array

/**
 * Main function for comparing prices.
 */
void compare_prices(char **grocery_list,
                    int number_of_list_items,
                    items_data *item_data)
                    {
    for (int i = 0; i < number_of_list_items; i++)
    {
        for(int j = 0; j < NUMBER_OF_ITEMS*NUMBER_OF_STORES; j++)
        {
            if(strcmp(grocery_list[i], item_data[j].item_name) == 0)
            {
                transfer_stores(j, item_data);
                calculate_prices(j, item_data);
                transfer_items_multiple_stores(j, item_data);
            }
        }
    }
    printPrices_multiple_stores(number_of_list_items);
    qsort(individual_store_total,
          NUMBER_OF_STORES,
          sizeof(individual_stores),
          cmp_fnc);
    printPrices();
}

/**
 * Function that saves stores for the individual store type.
 */
void transfer_stores(int j, items_data *item_data){
    for (int k = 0; k < NUMBER_OF_STORES; k++) {
        if (strcmp(individual_store_total[k].store, "") == 0) {
            strcpy(individual_store_total[k].store, item_data[j].item_store);
            break;
        }
    }
}

/**
 * Calculates prices for the individual stores.
 */
void calculate_prices(int j, items_data *item_data){
    for (int l = 0; l < NUMBER_OF_STORES; l++) {
        if(strcmp(item_data[j].item_store, individual_store_total[l].store) == 0){
            individual_store_total[l].total += item_data[j].item_price;
        }
    }
}

/**
 * Inputs the cheapest available option to the multiple_stores_total struct array, if no item is registred an item is inputted
 * Compares current value with new option from a different store and strcpy if new option is better
 * @param j
 * @param item_data
 */
void transfer_items_multiple_stores(int j, items_data *item_data){
    for (int k = 0; k < NUMBER_OF_ITEMS*NUMBER_OF_STORES; k++) {
        if (strcmp(multiple_stores_total[k].cheapest_item, item_data[j].item_name) == 0) {
            if (multiple_stores_total[k].price > item_data[j].item_price)
            {
                multiple_stores_total[k].price = item_data[j].item_price;
                strcpy(multiple_stores_total[k].cheapest_store, item_data[j].item_store);
            }
            break;
        }
        if (strcmp(multiple_stores_total[k].cheapest_item, "") == 0) {
            strcpy(multiple_stores_total[k].cheapest_item, item_data[j].item_name);
            multiple_stores_total[k].price = item_data[j].item_price;
            strcpy(multiple_stores_total[k].cheapest_store, item_data[j].item_store);
            break;
        }
    }
}

void printPrices(void){

    printf("Total cheapest store is:\n\n");
    for (int i = 0; i < NUMBER_OF_STORES; i++) {
        printf("%-15s\t:\t%.2lf kr.\n", individual_store_total[i].store, individual_store_total[i].total);
    }
    printf("___________________________________________________________\n");
}

void printPrices_multiple_stores(int number_of_list_items){

    printf("These items are cheapest in the following stores:\n\n");
    for (int i = 0; i < number_of_list_items; i++) {
        multiple_stores_total[i].cheapest_item[0] = toupper(multiple_stores_total[i].cheapest_item[0]);
        printf("%-15s\t:\t%.2lf kr.\t%s\n", multiple_stores_total[i].cheapest_store,
               multiple_stores_total[i].price, multiple_stores_total[i].cheapest_item);
    }
    printf("___________________________________________________________\n");
}

/**
 * Function that loops through the items from the different stores and calculates prices.
 */
double total_multiple_store_price (int number_of_list_items)
{
    double total = 0;
    for (int i = 0; i < number_of_list_items; ++i)
    {
        total += multiple_stores_total[i].price;
    }
    return total;
}

/**
 * Compare function used for qsort
 * @param a
 * @param b
 * @return
 */
int cmp_fnc(const void* a, const void* b)
{
    individual_stores *store1 = (individual_stores*) a;
    individual_stores *store2 = (individual_stores*) b;


    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;

}
