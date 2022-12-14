#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_OF_STORES 5
#define NUMBER_OF_ITEMS 25

typedef struct
{
    char item_name[20];
    double item_price;
    char item_store[20];
}items_data;

items_data scan_item_data (FILE* item_data_file);
void checkFile(FILE*);
void loadData(items_data *item_data_stores_prices);



void loadData(items_data *item_data_stores_prices)
{
    FILE* item_data_file;
    item_data_file = fopen("Data/Varedata.txt","r");
    checkFile(item_data_file);

    //loops through all products and scans product data
    for (int i = 0; i < NUMBER_OF_ITEMS*NUMBER_OF_STORES ; ++i)
    {
        item_data_stores_prices[i] = scan_item_data(item_data_file);
    }

    printf("Available items:\n");
    for (int i = 0; i < NUMBER_OF_ITEMS ; ++i)
    {
        item_data_stores_prices[i].item_name[0] = toupper(item_data_stores_prices[i].item_name[0]);
        printf("%s\n", item_data_stores_prices[i].item_name);
        item_data_stores_prices[i].item_name[0] = tolower(item_data_stores_prices[i].item_name[0]);
    }
}

void checkFile(FILE* file){
    if (file == NULL){
        printf("File not available");
        exit (EXIT_FAILURE);
    }
}

items_data scan_item_data(FILE* item_data_file)
{
    items_data new_item_data;

    char temp_str[100]; 
    fgets(temp_str, 100, item_data_file);

    temp_str[strlen(temp_str)- 1] = '\0'; //replaces the '\n' with '\0'

    char *p = strtok (temp_str, ",");
    int i = 0; //used in while loop for array
    char *array[3];

    while (p != NULL) //loops through data points until null
    {
        array[i++] = p;
        p = strtok (NULL, ",");
    }

    for (i = 0; i < 3; ++i) //copys data from array into struct
    {
        if(i == 0)
        {
            strcpy(new_item_data.item_name, array[i]);
        }
        else if (i == 1)
        {
            sscanf(array[i], "%lf", &new_item_data.item_price);
        }
        else
        {
            strcpy(new_item_data.item_store, array[i]);
        }
    }
    return new_item_data;
}