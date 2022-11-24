#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* items;
    items = fopen("Data/Varer.txt","r");

    FILE* item_data;
    item_data = fopen("Data/Varedata.txt","r");

    if (items == NULL)
    {
        printf("Items not available");
        exit (EXIT_FAILURE);

    }

    if (item_data == NULL)
    {
        printf("Item data not available");
        exit (EXIT_FAILURE);

    }


    return 0;

}