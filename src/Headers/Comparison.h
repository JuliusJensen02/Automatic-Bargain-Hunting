

#ifndef AUTOMATIC_BARGAIN_HUNTING_COMPARISON_H
#define AUTOMATIC_BARGAIN_HUNTING_COMPARISON_H


typedef struct{
    char store[20];
    double total;
}individual_stores;

void compare_prices(void);
void calculate_prices(int);
void transfer_stores(int);
void printPrices(void);

individual_stores individual_store_total[NUMBER_OF_STORES]; // sets size of struct array

void compare_prices(void){
    for (int i = 0; i < number_of_items; i++) {
        for(int j = 0; j < NUMBER_OF_ITEMS*NUMBER_OF_STORES; j++) {
            if(strcmp(grocery_list[i], item_data[j].item_name) == 0){
                transfer_stores(j);
                calculate_prices(j);
            }
        }
    }
    printPrices();
}

void transfer_stores(int j){
    for (int k = 0; k < NUMBER_OF_STORES; k++) {
        if (strcmp(individual_store_total[k].store, "") == 0) {
            strcpy(individual_store_total[k].store, item_data[j].item_store);
            break;
        }
    }
}

void calculate_prices(int j){
    for (int l = 0; l < NUMBER_OF_STORES; l++) {
        if(strcmp(item_data[j].item_store, individual_store_total[l].store) == 0){
            individual_store_total[l].total += item_data[j].item_price;
        }
    }
}

void printPrices(void){
    for (int i = 0; i < NUMBER_OF_STORES; i++) {
        printf("%s: %lf\n", individual_store_total[i].store, individual_store_total[i].total);
    }
}
#endif //AUTOMATIC_BARGAIN_HUNTING_COMPARISON_H
