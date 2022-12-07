#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Headers/Data_collection.h"
#define MAX_ITEM_SIZE 4096

void user_input (int *number_of_list_items, items *available_items);
void print_grocery_list(char **list, int number_of_list_items);
void exit_failure (char **array);
void assign_grocery_list (char **grocery_list, int number_of_list_items);
int item_check (items *available_items, char item[MAX_ITEM_SIZE]);

char **temp_grocery_list;

/**
 * The main function to accept the users input. It also inputs the grocery items into a grocery list.
 */
void user_input (int *number_of_list_items, items *available_items)
{
    char item[MAX_ITEM_SIZE];


    printf("Please write the items you want to find one by one:");

    temp_grocery_list = malloc(sizeof(char*) * 100);

    exit_failure(temp_grocery_list);

    while (strcmp(item, "exit") != 0)
    {

        //fgets is the way the program accepts an input from the user
        fgets(item,MAX_ITEM_SIZE, stdin);

        item[strlen(item)- 1] = '\0'; //replaces the '\n' with '\0'

        if(strcmp(item, "exit") != 0)
        {
            if (item_check(available_items, item))
            {
                temp_grocery_list[*number_of_list_items] = malloc(strlen(item));
                exit_failure(temp_grocery_list);

                strcpy(temp_grocery_list[*number_of_list_items], item);

                *number_of_list_items += 1;
                printf("Number of items = %d\n",*number_of_list_items);

                print_grocery_list(temp_grocery_list, *number_of_list_items);

                printf("If end of grocery list, please write 'exit'. If not, write next item:\n");
            }
            else
            {
                printf("This item does not exist in the program, please enter a new item:\n");
            }
        }
    }
}

/**
 * A function that prints an array of strings.
 * @param uses an array as input.
 */
void print_grocery_list(char **list, int number_of_list_items)
{
    for (int i = 0; i < number_of_list_items; ++i)
    {
        printf("%s\n",list[i]);
    }
    printf("\n");
}

/**
 * A function that checks if memory is allocated correctly for the inputted array
 * @param uses an array as input.
 */
void exit_failure (char **array)
{
    if (array == NULL)
    {
        printf("Malloc failed");
        exit(EXIT_FAILURE);
    }
}

/**
 * This function takes the temp_grocery_list and puts it in the grocery_list and prints said list.
 * @param grocery_list
 * @param number_of_list_items
 */
void assign_grocery_list (char **grocery_list, int number_of_list_items)
{

    for (int i = 0; i < number_of_list_items; ++i)
    {
        grocery_list[i] = malloc(MAX_ITEM_SIZE);
        exit_failure(grocery_list);

        strcpy(grocery_list[i],temp_grocery_list[i]);
    }

    printf("Final Grocery List:\n");
    print_grocery_list(grocery_list, number_of_list_items);

    free(temp_grocery_list);
}

/**
 * This function makes sure the user inputs an available item from the datafile.
 * @param available_items is the input of all the available items.
 * @param item the inputted item
 * @return
 */
int item_check (items *available_items, char item[MAX_ITEM_SIZE])
{
    for (int i = 0; i < NUMBER_OF_ITEMS; ++i)
    {
        if (strcmp(available_items[i].item_name, item) == 0)
        {
            return 1;
        }
    }
    return 0;
}