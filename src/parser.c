/**
 * Functions to parse bank.txt and construct a linked list of words 
 **/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readFile(char *filePath) {
   FILE *fp; 
   char *buffer = NULL; 

   if ((fp = fopen(filePath, "r")) != NULL) {
      fseek(fp, 0, SEEK_END); 
      long bytes = ftell(fp) + 1;  
      fseek(fp, 0, SEEK_SET); 
      buffer = (char *)malloc(bytes); 
      fread(buffer, 1, bytes, fp); 
      fclose(fp); 
   } else {
      printf("Error opening file for parsing"); 
   }  

   return buffer; 
}

int getBankSize(char *buffer) { 
   int count = 0; 

   for (; *buffer != '\0'; buffer++) { 
      if (*buffer == '\n') { count++; }
   } 

   return count; 
}  

char **parse(char *buffer, int bankSize) { 
   char **bank  = (char**)calloc(bankSize, sizeof(char *)); 

   for (int i=0; i < bankSize; ++i) { 
      char *word = (char *)malloc(6); 
      int j      = 0; 

      for(; *buffer != '\n';  buffer++) {  
          word[j] = *buffer;  
          j++; 
      }  

      bank[i] = word; 
      buffer++; 
   }  

   return bank;  
} 
