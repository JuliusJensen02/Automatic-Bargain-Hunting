#include <stdio.h>
#include "Headers/Data_collection.h"
#include "Headers/Function.h"
//#include "Headers/Comparison.h"
//#include "Headers/Composition.h"

int main(void){

    loadData();
    user_input();


    printf("Final Grocery List:\n");

    print_grocery_list(grocery_list);

    free(grocery_list);

    return 0;
}
