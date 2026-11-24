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
    printf("2. Display all flats according number of rooms booked");
    printf("3.Search flat by name \n");
    printf("4. Book a flat \n");
    printf("5. Calculate rent\n");
    printf("6. Save to a file\n");
    printf("7. Load from a file\n");
    printf("8. Exit\n");
}

void printflats(const struct Flat *f) {
    printf("#%d | %s | %s | %d rooms | %.2f | %s | %s\n", f->number, f->name, f->street, f->rooms, f->rent,f->owner, f->booked ? "booked" : "free");
}
// kindly include
void displayflats(struct Flat *flats,int num, int rooms) {
    int found =0;
    for(int i=0;i<num;i++) {
        if (flats[i].number == rooms) {
            printflats(flats[i]);
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
        printflats(flats[i]);
    }
}
#endif //HEADER_1