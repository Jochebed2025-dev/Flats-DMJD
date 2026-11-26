
//
// Created by Dylan Jilloh on 11/24/2026.

#ifndef HEADER_1
#define HEADER_1
#include <stdio.h>
#include"flat.h"

void menu() {
    printf("-----=====FLAT MENU=====-----\n");
    printf("--Kindly enter your choice--\n");
    printf("1. Display all flats \n");
    printf("2. Display all flats according number of rooms booked\n");
    printf("3. Search flat by name \n");
    printf("4. Book a flat \n");
    printf("5. Calculate rent\n");
    printf("6. Save to a file\n");
    printf("7. Load from a file\n");
    printf("8. Exit\n");
}
void printflats(const struct Flat *f)
{
    printf("FLAT INFORMATION:\n");
    printf("\nFlat number: %d\n", f->number);
    printf("Name:   %s\n", f->name);
    printf("Rooms:   %d\n", f->rooms);
    printf("Owner:   %s\n", f->owner);
    printf("Street:   %s\n", f->street);
    printf("Rent:     %.2f\n", f->rent);
    printf("Status:   %s\n", f->booked ? "Booked" : "Free");
    printf("\n\n");
}
void displayflats(struct Flat *flats,int num, int rooms) {
    int found =0;
    for(int i=0;i<num;i++) {
        if (flats[i].rooms == rooms) {
            printflats(&flats[i]);
            found++;
        }
    }
    if (found == 0) {
        printf("No flats found\n");
    }
}
void displaysAll(struct Flat *flats,int num) {
    if (num==0) {
        printf("No flats found\n");
        return;
    }
    for(int i=0;i<num;i++) {
        printflats(&flats[i]);
    }
}
int displayFreeFlats(struct Flat *flats, int num)
{
    int found = 0;
    for (int i = 0; i < num; i++)
    {
        if (!flats[i].booked)
        {
            printflats(&flats[i]);
            found++;
        }
    }
    if (found == 0)
    {
        printf("Sorry, there are no available flats.\n");
    }
    return found;
}
#endif //HEADER_1
