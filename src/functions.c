#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEM_SIZE 4096

void user_input (char **grocery_list, int number_of_list_items);
void print_grocery_list(char **list, int number_of_list_items);
void exit_failure (char **array);
void assign_grocery_list (char **grocery_list, char **temp_list, int number_of_list_items);

/**
 * The main function to accept the users input. It also inputs the grocery items into a grocery list.
 */
void user_input (char **grocery_list, int number_of_list_items)
{
    char item[MAX_ITEM_SIZE];
    char **temp_grocery_list;

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
            temp_grocery_list[number_of_list_items] = malloc(strlen(item));
            exit_failure(temp_grocery_list);

            strcpy(temp_grocery_list[number_of_list_items], item);

            number_of_list_items += 1;
            printf("Number of items = %d\n",number_of_list_items);

            print_grocery_list(temp_grocery_list, number_of_list_items);

            printf("If end of grocery list, please write 'exit'. If not, write next item:");
        }
    }
    assign_grocery_list(grocery_list, temp_grocery_list, number_of_list_items);
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

void assign_grocery_list (char **grocery_list, char **temp_list, int number_of_list_items)
{
    grocery_list = malloc(sizeof(char*) * (number_of_list_items + 1));
    exit_failure(grocery_list);

    for (int i = 0; i < number_of_list_items; ++i)
    {
        grocery_list[i] = malloc(MAX_ITEM_SIZE);
        exit_failure(grocery_list);

        strcpy(grocery_list[i],temp_list[i]);
    }

    print_grocery_list(grocery_list, number_of_list_items);

    free(temp_list);
}