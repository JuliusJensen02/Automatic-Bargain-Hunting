
#ifndef AUTOMATIC_BARGAIN_HUNTING_FUNCTION_H
#define AUTOMATIC_BARGAIN_HUNTING_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEM_SIZE 4096

void user_input (int *number_of_list_items, items_data *available_items);
void print_grocery_list(char **list, int number_of_list_items);
void exit_failure (char **array);
void assign_grocery_list (char **grocery_list, int number_of_list_items);
int item_check (items_data *available_items, char item[MAX_ITEM_SIZE], char **temp, int number_of_list_items);


#endif //AUTOMATIC_BARGAIN_HUNTING_FUNCTION_H
