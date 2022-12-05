

#include "Data_collection.c"
#include "functions.c"


void composition ()
{
    grocery_list;
    item;

    for (int i = 0; i < number_of_items; ++i)
    {
        for (int j = 0; j < NUMBER_OF_ITEMS; ++j)
        {
            if (strcmp(grocery_list[i], item[j].item_name) == 0)
            {
                break;
            }
        }
        printf("Item:\t%s is not found",grocery_list[i]);
    }

}