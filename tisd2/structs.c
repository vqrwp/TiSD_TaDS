/*адрес, общую площадь,
        количество комнат, стоимость квадратного метра, первичное
        жилье или нет (первичное – с отделкой или без нее; вторичное –
время постройки, количество предыдущих собственников,
        количество последних жильцов, были ли животные). */

#define CHAR_SIZE 30
#define M_SIZE 100

typedef struct
{
    int finished_or_not;
} primary;

typedef struct
{
    int date;
    int owners;
    int tenants;
    int animals;
} secondary;

typedef union
{
    primary primary1;
    secondary secondary1;
} inverse_type;

typedef struct
{
    char address[CHAR_SIZE];
    int area;
    int rooms;
    int price_for_meter;
    char housing[CHAR_SIZE];
    inverse_type type;
} flats;

typedef struct
{
    int index;
    int price_for_meter;
} key;