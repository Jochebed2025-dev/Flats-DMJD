#ifndef HEADER_2
#define HEADER_2
#include <stdio.h>
#include <string.h>
#include "flat.h"
#include "header_1.h"

void searchFlat(char name[], struct Flat *head)
{
    for (struct Flat *current = head; current != NULL; current = current->next)
    {
        if (strstr(current->name, name) != NULL)
        {
            printf("\nYour flat has been found!\n");
            printflats(current);
            return;
        }
    }
    printf("No flat found with the name %s\n", name);
}

void BookFlat(struct Flat *head, int number)
{
    for (struct Flat *current = head; current != NULL; current = current->next)
    {
        if (current->number == number)
        {
            if (current->booked == true)
            {
                printf("Unfortunately, this flat is already booked!\n");
                return;
            }
            current->booked = true;
            printf("\nYour flat has been booked, Thank You!\n");
            printf("Flat number: %d\n", current->number);
            printf("Flat name: %s\n", current->name);
            printf("Monthly rent: %.2f\n", current->rent);
            return;
        }
    }
    printf("Sorry, flat %d was not found!\n", number);
}

float CalculateRent(struct Flat *head, int month, int number)
{
    for (struct Flat *current = head; current != NULL; current = current->next)
    {
        if (current->number == number)
        {
            printf("\nFlat selected: %s\n", current->name);
            printf("Monthly rent: %.2f\n", current->rent);
            return current->rent * month;
        }
    }
    printf("No flats with %d were found!\n", number);
    return -1;
}
#endif
