#include "Headers/Data_collection.h"
#include "Headers/Function.h"

typedef struct{
    char store[20];
    double total;
}individual_stores;

typedef struct{
    char cheapest_store[20];
    char cheapest_item[20];
    double total;
}multiple_stores;

void compare_prices(char **grocery_list, int number_of_list_items, items_data *item_data);
void calculate_prices(int j, items_data *item_data);
void transfer_stores(int j, items_data *item_data);
void printPrices(void);
void printPrices_multiple_stores(void);
void transfer_items_multiple_stores(int j, items_data *item_data);

individual_stores individual_store_total[NUMBER_OF_STORES]; // sets size of struct array
multiple_stores multiple_stores_total[NUMBER_OF_ITEMS*NUMBER_OF_STORES]; // sets size of struct array

void compare_prices(char **grocery_list, int number_of_list_items, items_data *item_data){
    for (int i = 0; i < number_of_list_items; i++) {
        for(int j = 0; j < NUMBER_OF_ITEMS*NUMBER_OF_STORES; j++) {
            if(strcmp(grocery_list[i], item_data[j].item_name) == 0){
                transfer_stores(j, item_data);
                calculate_prices(j, item_data);
                transfer_items_multiple_stores(j, item_data);
            }
        }
    }
    printPrices_multiple_stores();
    printPrices();
}

void transfer_stores(int j, items_data *item_data){
    for (int k = 0; k < NUMBER_OF_STORES; k++) {
        if (strcmp(individual_store_total[k].store, "") == 0) {
            strcpy(individual_store_total[k].store, item_data[j].item_store);
            break;
        }
    }
}

void calculate_prices(int j, items_data *item_data){
    for (int l = 0; l < NUMBER_OF_STORES; l++) {
        if(strcmp(item_data[j].item_store, individual_store_total[l].store) == 0){
            individual_store_total[l].total += item_data[j].item_price;
        }
    }
}

void transfer_items_multiple_stores(int j, items_data *item_data){
    for (int k = 0; k < NUMBER_OF_ITEMS*NUMBER_OF_STORES; k++) {
        if (strcmp(multiple_stores_total[k].cheapest_item, item_data[j].item_name) == 0) {
            if (multiple_stores_total[k].total > item_data[j].item_price)
            {
                multiple_stores_total[k].total = item_data[j].item_price;
                strcpy(multiple_stores_total[k].cheapest_store, item_data[j].item_store);

                break;
            }

        }
        if (strcmp(multiple_stores_total[k].cheapest_item, "") == 0) {
            strcpy(multiple_stores_total[k].cheapest_item, item_data[j].item_name);
            multiple_stores_total[k].total = item_data[j].item_price;
            strcpy(multiple_stores_total[k].cheapest_store, item_data[j].item_store);
            break;
        }
    }
}

void printPrices(void){
    for (int i = 0; i < NUMBER_OF_STORES; i++) {
        printf("%-15s\t:\t%.2lf kr.\n", individual_store_total[i].store, individual_store_total[i].total);
    }
}

void printPrices_multiple_stores(void){
    for (int i = 0; i < NUMBER_OF_ITEMS; i++) {
        printf("%-15s\t:\t%.2lf kr.\t%s\n", multiple_stores_total[i].cheapest_store,
               multiple_stores_total[i].total, multiple_stores_total[i].cheapest_item);
    }
}