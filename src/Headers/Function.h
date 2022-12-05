
#ifndef AUTOMATIC_BARGAIN_HUNTING_FUNCTION_H
#define AUTOMATIC_BARGAIN_HUNTING_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEM_SIZE 4096

void user_input (char **grocery_list, int number_of_list_items);
void print_grocery_list(char **list, int number_of_list_items);
void exit_failure (char **array);


#endif //AUTOMATIC_BARGAIN_HUNTING_FUNCTION_H
