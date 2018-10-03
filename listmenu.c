#include <stdio.h>
#include "list.h"
#include "transport.h"
#include "listmenu.h"



void printMenu(MenuItems *menuitems, struct List* list){
    printf("MAIN MENU\tC:%d\tH:%p\tT:%p\n", Count(list), list->head, list->tail);
    int i = 0;
    for(i; i < menuitems->count; i++){
        printf("[%d]\t%s\n", i, menuitems->items[i].name);
    }
    printf("\n\nEnter number of menu list and press ENTER, ENTER -1 for escape\n");
}

void MenuItemAll(struct List* list){
    PrintList(list);
}

void PrintList(struct List* list){
    struct Item *item;
    printf("HEAD %p\t TAIL %p\n", list->head, list->tail);
    for(item=list->head; item != NULL; item = item->next)
    {
        printItemCar((ItemCar *) item);
    }
    printf("COUNT: %d\n",Count(list));
}

void MenuItemAdd(struct List* list){
    Add((struct Item *) inputItemCar(), list);
}

void MenuItemRem(struct List* list){
    int pos = 0;
    printf("Enter pos which you want remove\n");
    fflush(stdout); scanf("%d", &pos);
    RemoveItem(pos, list);
}

void MenuItemDel(struct List* list){
    int pos = 0;
    printf("Enter pos which you want delete\n");
    fflush(stdout); scanf("%d", &pos);
    DelItem(pos, list);
}

void MenuItemIns(struct List* list){
    int pos;
    printf("Enter pos which you want insert to list\n");
    fflush(stdout); scanf("%d", &pos);
    printf("Enter data which you want insert to list\n");
    Insert(pos, (struct Item *) inputItemCar(), list);
}

void MenuItemCount(struct List* list){
    printf("COUNT: %d\n", Count(list));
}


void MenuItemGet(struct List* list){
    int pos = 0;
    printf("Enter pos which you want get\n");
    fflush(stdout); scanf("%d", &pos);
    printItemCar((ItemCar *) Get(pos, list));
}


void MenuItemClear(struct List* list){
    Clear(list);
    printf("List cleared!\n");
}

void MenuItemGetIndex(struct List* list){
    struct Item* item;
    printf("Enter address item\n");
    fflush(stdout); scanf("%p", &item);
    printf("INDEX OF %p : %d", item, GetIndex(item, list));
}

void MenuItemSortByNumSeats(struct List* list){
    struct List* newlist = sortByNumSeats(list);
    PrintList(newlist);
}

void MenuItemSearchByGovNumber(struct List* list){
    char name[25];
    printf("Enter gov number for search\n");
    fflush(stdout); scanf("%s", &name);
    struct List* list1 = searchByGovNumber(name, list);
    PrintList(list1);
}

void MenuItemSearchByColor(struct List* list){
    char name[25];
    printf("Enter color for search\n");
    fflush(stdout); scanf("%s", &name);
    struct List* list1 = searchByColor(name, list);
    PrintList(list1);
}


void MenuItemSearchByOwner(struct List* list){
    char name[25];
    printf("Enter owner for search\n");
    fflush(stdout); scanf("%s", &name);
    struct List* list1 = searchByOwner(name, list);
    PrintList(list1);
}