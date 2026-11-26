#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flat.h"

struct Flat *createFlat(int number, int rooms, const char name[], const char owner[],
                        bool booked, const char street[], float rent)
{
    struct Flat *newFlat = (struct Flat *)malloc(sizeof(struct Flat));
    if (newFlat == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newFlat->number = number;
    newFlat->rooms = rooms;
    strcpy(newFlat->name, name);
    strcpy(newFlat->owner, owner);
    newFlat->booked = booked;
    strcpy(newFlat->street, street);
    newFlat->rent = rent;
    newFlat->next = NULL;
    return newFlat;
}

void addFlat(struct Flat **head, struct Flat *newFlat)
{
    if (newFlat == NULL)
        return;

    if (*head == NULL)
    {
        *head = newFlat;
        return;
    }
    struct Flat *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = newFlat;
}

int countFlats(struct Flat *head)
{
    int count = 0;
    for (struct Flat *current = head; current != NULL; current = current->next)
        count++;
    return count;
}

void freeList(struct Flat **head)
{
    struct Flat *current = *head;
    while (current != NULL)
    {
        struct Flat *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

#endif
