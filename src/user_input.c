#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Headers/data_collection.h"
#define MAX_INPUT_SIZE 4096

void user_input (int *number_of_list_items, items_data *available_items);
void print_grocery_list(char **list, int number_of_list_items);
void exit_failure (char **array);
void assign_grocery_list (char **grocery_list, int number_of_list_items);
int item_check (items_data *available_items, char item[MAX_INPUT_SIZE], int number_of_list_items);

char **temp_grocery_list;

/**
 * The main function to accept the users input. It also inputs the grocery items into a grocery list.
 */
void user_input (int *number_of_list_items, items_data *available_items)
{
    char item[MAX_INPUT_SIZE];
    printf("Please write the items you want to find one by one:");

    temp_grocery_list = malloc(sizeof(char*) * 100);
    exit_failure(temp_grocery_list);

    while (strcmp(item, "exit") != 0)
    {
        //fgets is the way the program accepts an input from the user
        fgets(item,MAX_INPUT_SIZE, stdin);
        item[strlen(item)- 1] = '\0'; //replaces the '\n' with '\0'

        for (int i = 0; i < strlen(item); ++i)
        {
            item[i] = tolower(item[i]);
        }

        if(strcmp(item, "exit") != 0){
            int valid_item = item_check(available_items,
                                        item,
                                        *number_of_list_items);
            if (valid_item == 1){
                temp_grocery_list[*number_of_list_items] = malloc(strlen(item));
                exit_failure(temp_grocery_list);

                strcpy(temp_grocery_list[*number_of_list_items], item);

                *number_of_list_items += 1;

                print_grocery_list(temp_grocery_list, *number_of_list_items);

                printf("If end of grocery list, please write 'exit'. If not, write next item:");
            }
            else if (valid_item == 0){
                printf("This item does not exist in the program.\nPlease enter a new item:\n");
            }
            else{
                printf("This item is already in the grocery list:\n");
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
    printf("___________________________________________________________");
    printf("\nGrocery list:\n");
    for (int i = 0; i < number_of_list_items; ++i)
    {
        list[i][0] = toupper(list[i][0]);
        printf("   %d. %s\n", i+1, list[i]);
        list[i][0] = tolower(list[i][0]);
    }
    printf("___________________________________________________________\n");
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
        grocery_list[i] = malloc(strlen(temp_grocery_list[i]));
        exit_failure(grocery_list);

        strcpy(grocery_list[i],temp_grocery_list[i]);
    }

    if (strcmp(grocery_list[0], "first") != 0)
    {
        print_grocery_list(grocery_list, number_of_list_items);
    }
    else
    {
        printf("No items in grocery list");
    }

    free(temp_grocery_list);
}

/**
 * This function makes sure the user inputs an available item from the datafile and if the item inputted is a duplicate.
 * @param available_items is the input of all the available items.
 * @param item the inputted item
 * @return
 */
int item_check (items_data *available_items, char item[MAX_INPUT_SIZE], int number_of_list_items)
{
    for (int i = 0; i < number_of_list_items; ++i)
    {
        if (strcmp(temp_grocery_list[i], item) == 0)
        {
            return 2;
        }

    }
    for (int i = 0; i < NUMBER_OF_ITEMS; ++i)
    {
        if (strcmp(available_items[i].item_name, item) == 0)
        {
            return 1;
        }
    }
    return 0;
}