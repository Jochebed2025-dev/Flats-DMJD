#include <stdio.h>
#include <string.h>
#include "flat.h"

void searchFlat(char name[], struct Flat *head)
{
    for (struct Flat *current = head; current != NULL; current->next)
    {
        if (strcmp(name, flats[i].name) == 0)
        {
            printf("You have flat has been found\n")
                printflats(current);
            return;
        }
    }
    printf("No flat found with the name %s\n", name);
}

void BookFlat(struct Flat *head)
{
    for (struct Flat *current = head; current != NULL; current = current->next)
    {
        if (!flats[i].booked)
        {
            flats[i].booked = true;

            printf("Flat booked successfully:\n");
            printf("  Number:  %d\n", flats[i].number);
            printf("  Name:    %s\n", flats[i].name);
            printf("  Rooms:   %d\n", flats[i].rooms);
            printf("  Owner:   %s\n", flats[i].owner);
            printf("  Street:  %s\n", flats[i].street);
            printf("  Rent:    %.2f\n", flats[i].rent);
            return;
        }
    }
    printf("Sorry, all flats are already booked.\n");
}

float CalculateRent(struct Flat *head, int month, int num)
{
    for (struct Flat *current = head; current != NULL; current = current->next)
    {
        if (flats[i].number == num)
        {
            return flats[i].rent * month;
        }
    }

    printf("The flat of number %d was not found!");
    return -1
}
