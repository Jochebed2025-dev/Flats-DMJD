#include <stdio.h>
#include <string.h>
#include "flat.h"

void searchFlat(char name[], struct Flat *flats, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(name, flats[i].name) == 0)
        {
            printf("The flat number is %d\n", flats[i].number);
            printf("Flat found:\n");
            printf("  Number:  %d\n", flats[i].number);
            printf("  Name:    %s\n", flats[i].name);
            printf("  Rooms:   %d\n", flats[i].rooms);
            printf("  Owner:   %s\n", flats[i].Owner);
            printf("  Street:  %s\n", flats[i].street);
            printf("  Rent:    %.2f\n", flats[i].Rent);
            printf("  Booked:  %s\n", flats[i].booked ? "Yes" : "No");
            return;
        }
    }
    printf("No flat found with the name %s\n", name);
}

void BookFlat(struct Flat *flats, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (!flats[i].booked)
        {
            flats[i].booked = true;

            printf("Flat booked successfully:\n");
            printf("  Number:  %d\n", flats[i].number);
            printf("  Name:    %s\n", flats[i].name);
            printf("  Rooms:   %d\n", flats[i].rooms);
            printf("  Owner:   %s\n", flats[i].Owner);
            printf("  Street:  %s\n", flats[i].street);
            printf("  Rent:    %.2f\n", flats[i].Rent);
            return;
        }
    }
    printf("Sorry, all flats are already booked.\n");
}

float CalculateRent(struct Flat *flats, int month, int num)
{
    for (int i = 0; i < MAX_FLATS; i++)
    {
        if (flats[i].number == num)
        {
            return flats[i].rent * month;
        }
    }

    printf("The flat of number %d was not found!");
    return -1
}