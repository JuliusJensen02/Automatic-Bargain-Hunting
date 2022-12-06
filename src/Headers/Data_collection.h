
#ifndef AUTOMATIC_BARGAIN_HUNTING_DATA_COLLECTION_H
#define AUTOMATIC_BARGAIN_HUNTING_DATA_COLLECTION_H

#define NUMBER_OF_STORES 5
#define NUMBER_OF_ITEMS 25

typedef struct
{
    char item_name[20];
}items;

typedef struct
{
    char item_name[20];
    double item_price;
    char item_store[20];
}items_data;
void loadData(items *available_items, items_data *item_data_stores_prices);


#endif //AUTOMATIC_BARGAIN_HUNTING_DATA_COLLECTION_H
