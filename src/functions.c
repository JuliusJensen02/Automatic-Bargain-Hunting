#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEM_SIZE 4096


void user_input ();
void print_grocery_list(char **list);
void exit_failure (char **array);

int number_of_items = 0;
char **grocery_list;

int main()
{
    user_input();

    printf("Final Grocery List:\n");

    print_grocery_list(grocery_list);

    free(grocery_list);

    return 0;
}

void user_input ()
{
    char item[MAX_ITEM_SIZE];
    char **temp_grocery_list;
    int k = 0;

    printf("Please write the items you want to find one by one:");

    temp_grocery_list = malloc(sizeof(char*) * 100);

    exit_failure(temp_grocery_list);

    while (strcmp(item, "exit") != 0)
    {

        fgets(item,MAX_ITEM_SIZE, stdin);
        item[strlen(item)- 1] = '\0';

        printf("item = %s\n", item);

        if(strcmp(item, "exit") != 0)
        {
            temp_grocery_list[k] = malloc(strlen(item));
            exit_failure(temp_grocery_list);

            number_of_items = number_of_items + 1;
            printf("Number of items = %d\n",number_of_items);


            strcpy(temp_grocery_list[k], item);

            k++;
            print_grocery_list(temp_grocery_list);

            printf("If end of grocery list, please write 'exit'. If not, write next item:");
        }
    }

    grocery_list = malloc(sizeof(char*) * (number_of_items + 1));
    exit_failure(grocery_list);


    for (int i = 0; i < number_of_items; ++i)
    {
        grocery_list[i] = malloc(20);
        exit_failure(grocery_list);

        strcpy(grocery_list[i],temp_grocery_list[i]);
    }

    free(temp_grocery_list);
}

void print_grocery_list(char **list)
{
    for (int i = 0; i < number_of_items; ++i)
    {
        printf("%s",list[i]);
        printf("\n");;
    }
}
void exit_failure (char **array)
{
    if (array == NULL)
    {
        printf("Malloc failed");
        exit(EXIT_FAILURE);
    }
}