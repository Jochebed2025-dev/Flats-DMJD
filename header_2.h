#include <stdio.h>
#include <string.h>
#include "flat.h"
#include "header_1.h"

void searchFlat(char name[], struct Flat *flats, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strstr( flats[i].name,name) != NULL)
        {
            printf("\nYour flat has been found!\n");
            printflats(&flats[i]);
            return;
        }
    }
    printf("No flat found with the name %s\n", name);
}
void BookFlat(struct Flat *flats, int number, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (flats[i].number == number)
        {
            if (flats[i].booked == true)
            {
                printf("Unfortunately, this flat is already booked!\n");
                return;
            }
            flats[i].booked = true;
            printf("\nYour flat has been booked, Thank You!\n");
            printf("Flat number: %d\n", flats[i].number);
            printf("Flat name: %s\n", flats[i].name);
            printf("Monthly rent: %.2f\n", flats[i].rent);
            return;
        }
    }
    printf("Sorry, flat %d was not found!\n", number);
}
float CalculateRent(struct Flat *flats, int month, int number, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (flats[i].number == number)
        {
            printf("\nFlat selected: %s\n", flats[i].name);
            printf("Monthly rent: %.2f\n", flats[i].rent);
            return flats[i].rent * month;
        }
    }
    printf("No flats with %d were found!", number);
    return -1;
}
