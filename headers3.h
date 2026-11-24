#include <stdio.h>
#include "flats.h"
#ifndef header3_h
#define  header3_h
void write_to_file(struct Flat* flats){
    FILE *fpnt = fopen("File.txt","a");
    if(fpnt == NULL){
        printf("File wasn't created");
    }
        fprintf(fpnt," Flat number: %d ; Rooms: %d; Name: %s; Owner: %d; Booked: %c; Street: %s; Rent: %2.f;",flats->number,flats->rooms,flats->name,flats->owner,flats->booked,flats->street,flats->rent );
    fclose(fpnt);
    }

void read_from_file(struct Flat *flats){
    FILE *fpnt= fopen("file.txt","r");
   char line[100];
   int i=0;
   FILE *file = fopen("students.txt","r");
if (file!= NULL){
while (fgets(line, 100, fpnt))
        {
            char *token;
            token = strtok(line, ";");
            int flag=1;
            while( token != NULL )
            { 
                for(int i=0;i<1;i++){
                if(flag==1){
                    flats->number=atoi(token);}
                else if(flag==2){
                    flats->rooms=atoi(token);
                }
                else if(flag==3){
                    strcpy(flats->name,token);
                else if(flag==4){
                    strcpy(flats->owner,token);
                else if(flag==5){
                    flats->booked=atoi(token);
                else if(flag==6){
                    flats->street=atoi(token);
                else{
                    if(token[strlen(token)-1]=='\n')
                        token[strlen(token)-1]='\0';
                        flats->rent= atoi(token);
                }
                token = strtok(NULL, ";");
                flag++;
                }
        
 
            if(flag>3){
                flag=1;
            }
    }
       i++;
}
    fclose(fpnt);
}
}

#endif



