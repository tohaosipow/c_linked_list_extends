#include <malloc.h>
#include <stdio.h>
#include <mem.h>
#include "list.h"
#include "transport.h"
const char * const ItemTypeName[] =
        { "(unknown)", "Passanger Car", "Minibus", "Bus", "Truck", "Special"};

// Factories
ItemCar * factoryItemCar(enum ItemType type){
    switch (type){
        case itNone:{
            return NULL;
        }
        case itPassCar: return (ItemCar *) factoryItemPassCar();
        case itMiniBus:return (ItemCar *) factoryItemMiniBus();
        case itBus:return (ItemCar *) factoryItemBus();
        case itTruck: return (ItemCar *) factoryItemTruck();
        case itSpecial: return (ItemCar *) factoryItemSpecial();
    }
}


ItemPassCar * factoryItemPassCar(){
    ItemPassCar* itemCar = malloc(sizeof(ItemPassCar));
    itemCar->prev = NULL;
    itemCar->next = NULL;
    strcpy(itemCar->brand, "");
    strcpy(itemCar->gov_number, "");
    strcpy(itemCar->owner, "");
    strcpy(itemCar->model, "");
    strcpy(itemCar->color, "");
    itemCar->type = itPassCar;
    itemCar->bodyType = NULL;
    itemCar->engineType = NULL;
    itemCar->driveType = NULL;
    return itemCar;
}


ItemMiniBus * factoryItemMiniBus(){
    ItemMiniBus* itemCar = malloc(sizeof(ItemMiniBus));
    itemCar->prev = NULL;
    itemCar->next = NULL;
    strcpy(itemCar->brand, "");
    strcpy(itemCar->gov_number, "");
    strcpy(itemCar->owner, "");
    strcpy(itemCar->model, "");
    strcpy(itemCar->color, "");
    itemCar->type = itMiniBus;

    itemCar->numSeats = NULL;
    itemCar->engineType = NULL;
    return itemCar;

}

ItemBus * factoryItemBus(){
    ItemBus* itemCar = malloc(sizeof(ItemBus));
    itemCar->prev = NULL;
    itemCar->next = NULL;
    strcpy(itemCar->brand, "");
    strcpy(itemCar->gov_number, "");
    strcpy(itemCar->owner, "");
    strcpy(itemCar->model, "");
    strcpy(itemCar->color, "");
    itemCar->type = itBus;

    itemCar->numSeats = NULL;
    itemCar->engineType = NULL;
    itemCar->cargoCapacity = NULL;
    return itemCar;

}

ItemTruck * factoryItemTruck(){
    ItemTruck* itemCar = malloc(sizeof(ItemTruck));
    itemCar->prev = NULL;
    itemCar->next = NULL;
    strcpy(itemCar->brand, "");
    strcpy(itemCar->gov_number, "");
    strcpy(itemCar->owner, "");
    strcpy(itemCar->model, "");
    strcpy(itemCar->color, "");
    itemCar->type = itTruck;

    itemCar->engineType = NULL;
    itemCar->cargoCapacity = NULL;
    return itemCar;

}

ItemSpecialCar * factoryItemSpecial(){
    ItemSpecialCar* itemCar = malloc(sizeof(ItemSpecialCar));
    itemCar->prev = NULL;
    itemCar->next = NULL;
    strcpy(itemCar->brand, "");
    strcpy(itemCar->gov_number, "");
    strcpy(itemCar->owner, "");
    strcpy(itemCar->model, "");
    strcpy(itemCar->color, "");
    itemCar->type = itSpecial;

    strcpy(itemCar->describe, "");
    return itemCar;
}

void printBaseCarData(ItemCar* car){
    printf("GovNumber: %s\tOwner:%s\tBrand:%s\tModel:%s\tColor:%s\tType:%s\n", car->gov_number, car->owner, car->brand, car->model, car->color, ItemTypeName[(car->type>0 && car->type<=5)?car->type:0]);
}


void printItemPassCar(ItemPassCar* car){
    printBaseCarData((ItemCar *) car);
    printf("Params:\tEngineType:%d\tBodyType:%d\tDriveType:%d\n", car->engineType, car->bodyType, car->driveType);
}

void printItemMiniBus(ItemMiniBus* car){
    printBaseCarData((ItemCar *) car);
    printf("Params:\tEngineType:%d\tNumber of seats:%d\n", car->engineType, car->numSeats);
}

void printItemBus(ItemBus* car){
    printBaseCarData((ItemCar *) car);
    printf("Params:\tEngineType:%d\tNumber of seats:%d\tCargo capacity:%d\n", car->engineType, car->numSeats, car->cargoCapacity);
}

void printItemTruck(ItemTruck* car){
    printBaseCarData((ItemCar *) car);
    printf("Params:\tEngine Type:%d\tCargo capacity:%d\\n", car->engineType, car->cargoCapacity);
}

void printItemSpecial(ItemSpecialCar* car){
    printBaseCarData((ItemCar *) car);
    printf("Params:\tDescribe:%s\n", car->describe);
}

void printItemCar(ItemCar* car){
    printf("\n%p==================%p==================%p\n", car->prev, car, car->next);
    switch(car->type){
        case itNone: printf("Undefined car type\n"); break;
        case itPassCar: printItemPassCar((ItemPassCar *)car); break;
        case itMiniBus:printItemMiniBus((ItemMiniBus *)car); break;
        case itBus:printItemBus((ItemBus *)car); break;
        case itTruck:printItemTruck((ItemTruck *)car); break;
        case itSpecial:printItemSpecial((ItemSpecialCar *)car); break;
    }
    printf("\n========================================================\n");
}


enum ItemType inputItemType(){
    enum ItemType type = itNone;
    int i = 1;
    while(type <= 0 || type > 5) {
        for (i = 1; i <= 5; i++) {
            printf("[%d] %s\n", i, ItemTypeName[i]);
        }
        printf("Select car type:\n");
        fflush(stdout); scanf("%d", &type);
    }
    return type;

}

void inputBaseCarData(ItemCar * car){
    printf("Enter car gov number:\n");
    fflush(stdout); scanf("%s", car->gov_number);
    printf("\nEnter car owner:\n");
    fflush(stdout); scanf("%s", car->owner);
    printf("\nEnter car brand:\n");
    fflush(stdout); scanf("%s", car->brand);
    printf("\nEnter car model:\n");
    fflush(stdout); scanf("%s", car->model);
    printf("\nEnter car color:\n");
    fflush(stdout); scanf("%s", car->color);
}

void inputItemPassCar(ItemPassCar* car){
    inputBaseCarData((ItemCar *) car);
    printf("\nEnter params:\n");
    printf("Engine type, BodyType, DriveType: ");
    fflush(stdout); scanf("%d %d %d", &car->engineType, &car->bodyType, &car->driveType);
}

void inputItemMiniBus(ItemMiniBus* car){
    inputBaseCarData((ItemCar *) car);
    printf("\nEnter params:\n");
    printf("Engine type, Num seats: ");
    fflush(stdout); scanf("%d %d", &car->engineType, &car->numSeats);
}

void inputItemBus(ItemBus* car){
    inputBaseCarData((ItemCar *) car);
    printf("\nEnter params:\n");
    printf("Engine type, Num seats, Cargo capacity: ");
    fflush(stdout); scanf("%d %d %d", &car->engineType, &car->numSeats, &car->cargoCapacity);
}

void inputItemTruck(ItemTruck* car){
    inputBaseCarData((ItemCar *) car);
    printf("\nEnter params:\n");
    printf("Engine type, Cargo capacity: ");
    fflush(stdout); scanf("%d %d", &car->engineType, &car->cargoCapacity);
}

void inputItemSpecialCar(ItemSpecialCar* car){
    inputBaseCarData((ItemCar *) car);
    printf("\nEnter params:\n");
    printf("Description:\n");
    fflush(stdout); scanf("%s", &car->describe);
}

ItemCar* inputItemCar(){
    ItemCar* car = factoryItemCar(inputItemType());
    switch(car->type){

        case itNone:break;
        case itPassCar: inputItemPassCar((ItemPassCar *) car); break;
        case itMiniBus:inputItemMiniBus((ItemMiniBus *) car); break;
        case itBus:inputItemBus((ItemBus *) car); break;
        case itTruck:inputItemTruck((ItemTruck *) car); break;
        case itSpecial:inputItemSpecialCar((ItemSpecialCar*) car); break;
    }
    return car;
}

ItemCar* copyCar(ItemCar* item){
    int size = 0;
    if(item->type==itBus) size = sizeof(ItemBus);
    if(item->type==itMiniBus) size = sizeof(ItemMiniBus);
    if(item->type==itTruck) size = sizeof(ItemTruck);
    if(item->type==itSpecial) size = sizeof(ItemSpecialCar);
    if(item->type==itPassCar) size = sizeof(ItemPassCar);
    ItemCar* itemC = (ItemCar*) malloc((size_t) size);
    memcpy(itemC, item, (size_t) size);
    return itemC;
}

struct List* searchByGovNumber(char* number, struct List* list){
    ItemCar *item;
    ItemCar *buf = NULL;

    struct List* newlist = factoryList();
    for(item= (ItemCar *) list->head; item != NULL; item = (ItemCar *) item->next)
    {
        if(!strcmp(number, item->gov_number)){
            buf = copyCar(item);
            Add((struct Item *) buf, newlist);
        }
    }
    return newlist;
}

struct List* searchByColor(char* color, struct List* list){
    ItemCar *buf = NULL;
    ItemCar *item;
    struct List* newlist = factoryList();
    for(item= (ItemCar *) list->head; item != NULL; item = (ItemCar *) item->next)
    {
        if(!strcmp(color, item->color)){
            buf = copyCar(item);
            Add((struct Item *) buf, newlist);
        }
    }
    return newlist;
}

struct List* searchByOwner(char* owner, struct List* list){
    ItemCar *buf = NULL;
    ItemCar *item;
    struct List* newlist = factoryList();
    for(item= (ItemCar *) list->head; item != NULL; item = (ItemCar *) item->next)
    {
        if(!strcmp(owner, item->owner)){
            buf = copyCar(item);
            Add((struct Item *) buf, newlist);
        }
    }
    return newlist;
}


struct List* sortByNumSeats(struct List* list){
    struct List* mylist = factoryList();
    ItemCar *item;
    for(item= (ItemCar *) list->head; item != NULL; item = (ItemCar *) item->next)
    {
        int size = 0;
        if(item->type==itBus) size = sizeof(ItemBus);
        if(item->type==itMiniBus) size = sizeof(ItemMiniBus);
        ItemCar *itemC = malloc((size_t) size);
        memcpy(itemC, item, (size_t) size);
        if(item->type == itBus || item->type == itMiniBus) Add((struct Item *) itemC, mylist);
    }
    int noSwap;
    for (int i = Count(mylist) - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (((ItemBus*)Get(j, mylist))->numSeats > ((ItemBus*)Get(j+1, mylist))->numSeats)
            {
                SwaipItem(j, j+1, mylist);
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }
    return mylist;
}