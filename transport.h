enum ItemType { itNone, itPassCar, itMiniBus, itBus, itTruck, itSpecial};
typedef struct ItemCar
{
    struct Item* next;
    struct Item* prev;
    char gov_number[64];
    char owner[25];
    char brand[25];
    char model[25];
    char color[25];
    enum ItemType type;
} ItemCar;

typedef struct ItemPassCar
{
    struct Item* next;
    struct Item* prev;
    char gov_number[64];
    char owner[25];
    char brand[25];
    char model[25];
    char color[25];
    enum ItemType type;
    //Extends
    int engineType;
    int bodyType;
    int driveType;
} ItemPassCar;


typedef struct ItemMiniBus
{
    struct Item* next;
    struct Item* prev;
    char gov_number[64];
    char owner[25];
    char brand[25];
    char model[25];
    char color[25];
    enum ItemType type;
    //Extends
    int engineType;
    int numSeats;
} ItemMiniBus;


typedef struct ItemBus
{
    struct Item* next;
    struct Item* prev;
    char gov_number[64];
    char owner[25];
    char brand[25];
    char model[25];
    char color[25];
    enum ItemType type;
    //Extends
    int engineType;
    int numSeats;
    int cargoCapacity;


} ItemBus;

typedef struct ItemTruck
{
    struct Item* next;
    struct Item* prev;
    char gov_number[64];
    char owner[25];
    char brand[25];
    char model[25];
    char color[25];
    enum ItemType type;
    //Extends
    int engineType;
    int cargoCapacity;


} ItemTruck;


typedef struct ItemSpecialCar
{
    struct Item* next;
    struct Item* prev;
    char gov_number[64];
    char owner[25];
    char brand[25];
    char model[25];
    char color[25];
    enum ItemType type;
    //Extends
    char describe[128];


} ItemSpecialCar;



ItemPassCar * factoryItemPassCar();

ItemBus * factoryItemBus();

ItemMiniBus * factoryItemMiniBus();

ItemTruck * factoryItemTruck();

ItemSpecialCar * factoryItemSpecial();

ItemCar* inputItemCar();
void printItemCar(ItemCar* car);
struct List* sortByNumSeats(struct List* list);
struct List* searchByGovNumber(char* number, struct List* list);
struct List* searchByColor(char* color, struct List* list);
struct List* searchByOwner(char* owner, struct List* list);