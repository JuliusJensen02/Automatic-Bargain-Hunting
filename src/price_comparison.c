#include "Headers/Data_collection.h"
#include "Headers/Function.h"

void compare_prices(void);

/*
int main(){
    loadData();
    user_input();
    compare_prices();
}*/

void compare_prices(void){
    for (int i = 0; i < number_of_items; ++i) {

        for(int j = 0; j < NUMBER_OF_ITEMS*NUMBER_OF_STORES; ++j) {
            if(strcmp(grocery_list[i], item_data[j].item_name) == 0){
                printf("'%s' '%s'", item_data[j].item_name, item_data[j].item_store);
            }
        }

    }

}
