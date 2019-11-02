#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
 
int main()
{
    int num;
   FILE *fptr;
 
   if ((fptr = fopen("C:\\program.txt","r")) == NULL){
       printf("Error! opening file");
 
       // Program exits if the file pointer returns NULL.
       
   }
 
   fscanf(fptr,"%d", &num);
 
   printf("Value of n=%d", num);
   fclose(fptr); 
  
   return 0;
}