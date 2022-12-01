#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_STORES 5

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

items scan_item (FILE* items_file);
items_data scan_item_data (FILE* item_data_file);


int main()
{
    FILE* items_file;
    items_file = fopen("Data/Varer.txt","r");

    FILE* item_data_file;
    item_data_file = fopen("Data/Varedata.txt","r");

    if (items_file == NULL)
    {
        printf("Items not available");
        exit (EXIT_FAILURE);

     }

    if (item_data_file == NULL)
    {
        printf("Item data not available");
        exit (EXIT_FAILURE);

    }

    int count = 1;
    for (int c = getc(items_file); c != EOF; c = getc(items_file)) //counts items from file
    {
        if (c == '\n')
        {
            count = count + 1;
        }
    }
    items item[count]; // sets size of struct array
    items_data item_data[count*NUMBER_OF_STORES]; // sets size of struct array

    rewind(items_file); //resets file reader to start of file
    printf("Eksisterende varer:\n");;
    for (int i = 0; i < count ; ++i) //loops through different products and prints them.
    {
       item[i]= scan_item(items_file);
       printf("%s\n",item[i].item_name);
    }
    for (int i = 0; i < count * NUMBER_OF_STORES ; ++i) //loops through all products and scans product data
    {
        item_data[i] = scan_item_data(item_data_file);
        //printf("%s %lf %s\n",item_data[i].item_name, item_data[i].item_price, item_data[i].item_store);
    }
printf("hey ;)");
    return 0;

}

items scan_item (FILE* items_file)
{
    items new_item;
    fscanf(items_file, "%s",new_item.item_name);
    return new_item;
}

items_data scan_item_data(FILE* item_data_file)
{
    items_data new_item_data;
    fscanf(item_data_file,"%s , %lf , %s", new_item_data.item_name,
           &new_item_data.item_price,new_item_data.item_store);
    return new_item_data;
}