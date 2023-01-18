#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Headers/Data_collection.h"
#define MAX_ITEM_SIZE 4096
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
void user_input (int *number_of_list_items, items *available_items);
void print_grocery_list(char **list, int number_of_list_items);
void exit_failure (char **array);
void assign_grocery_list (char **grocery_list, int number_of_list_items);
int item_check (items *available_items, char item[MAX_ITEM_SIZE], char **temp, int number_of_list_items);
int levenshtein(char *s1, char *s2);
int minimum_number(const int *arr);
int already_exist_item(char item[MAX_ITEM_SIZE], char **temp, int number_of_list_items);

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
        do{
            fgets(item, MAX_ITEM_SIZE, stdin);
            item[strlen(item) - 1] = '\0'; //replaces the '\n' with '\0'
        }
        while(item[0] == '\0');
        if(strcmp(item, "exit") != 0){
            int valid_item = item_check(available_items, item,
                                        temp_grocery_list,
                                        *number_of_list_items);
            if(valid_item >= 0){
                temp_grocery_list[*number_of_list_items] = malloc(strlen(item));
                exit_failure(temp_grocery_list);
                strcpy(temp_grocery_list[*number_of_list_items], available_items[valid_item].item_name);
                *number_of_list_items += 1;
                printf("Number of items = %d\n",*number_of_list_items);
                print_grocery_list(temp_grocery_list, *number_of_list_items);
            }
            printf("If end of grocery list, please write 'exit'. If not, write next item:\n");
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
void assign_grocery_list (char **grocery_list, int number_of_list_items){
    for (int i = 0; i < number_of_list_items; ++i){
        grocery_list[i] = malloc(MAX_ITEM_SIZE);
        exit_failure(grocery_list);
        strcpy(grocery_list[i],temp_grocery_list[i]);
    }
    printf("Final Grocery List:\n");
    print_grocery_list(grocery_list, number_of_list_items);
    free(temp_grocery_list);
}

/**
 * This function makes sure the user inputs an available item from the datafile and if the item inputted is a duplicate.
 * @param available_items is the input of all the available items.
 * @param item the inputted item
 * @return
 */
int item_check(items *available_items, char item[MAX_ITEM_SIZE], char **temp, int number_of_list_items){
    int distances[NUMBER_OF_ITEMS];
    //Finds the distances between the input and all products
    int i;
    char *itemFiltered = item;
    for (int j = 0; j < strlen(item); ++j) {
        itemFiltered[j] = tolower(item[j]);
    }
    for(i = 0; i < NUMBER_OF_ITEMS; ++i){
        char *product;
        strcpy(product, available_items[i].item_name);
        product[0] = tolower(product[0]);
        distances[i] = levenshtein(item, product);
        if(distances[i] == 0){
            break;
        }
    }
    int auto_correct_index = minimum_number(distances); //Finds index of the smallest distance
    char firstCharProduct = tolower(available_items[auto_correct_index].item_name[0]);
    if(already_exist_item(available_items[auto_correct_index].item_name, temp, number_of_list_items)){
        printf("This item is already in the grocery list.\n");
        return -1;
    }
    if(itemFiltered[0] == firstCharProduct && distances[auto_correct_index] < 3){
        printf("I could not find '%s', is it ok that I correct it to %s? Yes(y) No (n)\n", item, available_items[auto_correct_index].item_name);
        char check;
        scanf("%c", &check);
        //Accept autocorrect
        if(check == 'y' || check == 'Y'){
            return auto_correct_index;
        }
        else{
            return -1;
        }
    }
    else{
        printf("I couldn't find that item\n");
        return -1;
    }
}

int already_exist_item(char *item, char **temp, int number_of_list_items){
    for (int i = 0; i < number_of_list_items; ++i){
        if (strcmp(temp[i], item) == 0){
            return 1;
        }
    }
    return 0;
}

int minimum_number(const int *arr){
    int index = 0, min = 1000;
    for (int i = 0; i < NUMBER_OF_ITEMS; ++i) {
        if(arr[i] < min){
            index = i;
            min = arr[i];
        }
    }
    return index;
}


int levenshtein(char *s1, char *s2) {
    unsigned int s1len, s2len, x, y, lastdiag, olddiag;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int column[s1len + 1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x - 1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y - 1] + 1, lastdiag + (s1[y-1] == s2[x - 1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
    return column[s1len];
}