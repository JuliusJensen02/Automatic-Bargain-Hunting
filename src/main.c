#include <stdio.h>
#include "Data_collection.c"
#include "functions.c"
#include "price_comparison.c"

int main(void){

    loadData();
    user_input();


    printf("Final Grocery List:\n");

    print_grocery_list(grocery_list);

    free(grocery_list);

    return 0;
}
