#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void user_input ();
void print_grocery_list(char **list);

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
    char item[20];
    char **temp_grocery_list;
    int k = 0;


    printf("Please write the items you want to find one by one>");

    while (strcmp(item, "exit") != 0)
    {
        temp_grocery_list = malloc(sizeof(char) * (number_of_items + 1));

        scanf(" %s", item);
        printf("item = %s\n",item);

        if(strcmp(item, "exit") != 0)
        {
            number_of_items += 1;
            printf("Number of items = %d\n",number_of_items);



            strcpy(temp_grocery_list[k], item);
            //printf("Temp grocery list = %s\n",temp_grocery_list[k]);


            print_grocery_list(temp_grocery_list);
            k++;
            printf("If end of grocery list, please write 'exit'. If not write next item>");
        }
    }
    grocery_list = malloc(sizeof(char) * number_of_items);

    for (int i = 0; i < number_of_items; ++i)
    {
        strcpy(grocery_list[i],temp_grocery_list[i]);
    }
    free(temp_grocery_list);
}

void print_grocery_list(char **list)
{
    for (int i = 0; i < number_of_items; ++i)
    {
        printf("%s\n",list[i]);
    }
}
