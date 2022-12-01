#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void user_input ();
void print_grocery_list(char **list);
void exit_failure (char **array);
void free_memory (char **array);

int number_of_items = 0;
char **grocery_list;

int main()
{
    user_input();

    //Fejl opstår i overførslen af strengene fra user_input til main. Et nogenlunde tilfældig antal af strengene bliver garbage.
    printf("\n");
    for (int i = 0; i < number_of_items; ++i)
    {
        printf("test string value 3: %s\n",grocery_list[i]);
    }

    printf("Final Grocery List:\n");

    print_grocery_list(grocery_list);

    free_memory(grocery_list);

    return 0;
}

void user_input ()
{
    char item[20];
    char **temp_grocery_list;
    int k = 0;
    int p1;

    printf("Please write the items you want to find one by one:");


    //Laver antallet af elementer i temp til at være noget fast, da det egentlig er meningen med at det bare er en temp og størrelsen derfor er ligegyldig.
    temp_grocery_list = malloc(sizeof(char*) * 100);

    //lavet funktion der tjekker om der faktisk er blevet allokeret memory, i stedet for at skrive det x antal gange.
    exit_failure(temp_grocery_list);

    while (strcmp(item, "exit") != 0)
    {
         /* Der kom fejl i debugger hver gang temp skulle reallokeres. Aka den strikede out på exit_failure
          *
          * p1 = sizeof(char) * (number_of_items + 1);

        temp_grocery_list = realloc(temp_grocery_list,p1);
        exit_failure(temp_grocery_list);
          */

        scanf(" %s", item);
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

    //grocery list som er vores endelig liste allokeres til den passende størrelse
    grocery_list = malloc(sizeof(char*) * (number_of_items + 1));
    exit_failure(grocery_list);


    for (int i = 0; i < number_of_items; ++i)
    {
        grocery_list[i] = malloc(20);
        exit_failure(grocery_list);

        strcpy(grocery_list[i],temp_grocery_list[i]);
        printf("test string value: %s\n",grocery_list[i]); //Den overfører strengene fra temp til grocery list korrekt nu (uanset antal af elementer)
    }

    //free_memory(temp_grocery_list);
    /*for (int i = 0; i < 100; ++i)
    {
        free(temp_grocery_list[i]);
    }*/
    free(temp_grocery_list);

    for (int i = 0; i < number_of_items; ++i)
    {
        printf("test string value 2: %s\n",grocery_list[i]);
    }
}

void print_grocery_list(char **list)
{
    for (int i = 0; i < number_of_items; ++i)
    {
        printf("%s\n",list[i]);
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
void free_memory (char **array)
{
    for (int i = 0; i < number_of_items; ++i)
    {
        free(array[i]);
    }
}