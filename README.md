# Automatic-Bargain-Hunting
This is a program written in c which aims to automate bargain hunting by letting the user input a list of items and then finding the cheapest options for buying these items.

## Guide for using the program

### Setup phase
Before using the program you will have to set up your compiler. Assume you will be using CLion to run the code, you will have to set the "working directory" under the tab "edit configurations" to the "src" folder.
This is needed because when CLion compiles the code, the code is transferred to another folder, but not the file containing product data, and as a result the code would not be able to find the file.

### Run phase
When running the program you will be presented with a list of available items. These are the items you can choose from.
When you have inserted the desired items, you will need to enter 'exit'.
Afterwards the program will print the stores where the items are cheapest along with a sorted list of prices with associated stores.
