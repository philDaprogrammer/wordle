#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "parser.c"


char *getRandomWord(char **bank, int bankSize) { 
   srand(time(0)); 
   return bank[rand() % bankSize]; 
} 


int main(int argc, char *argv[]) { 
   char *filePath = "/home/phil/Programs/c/cse421/wordle/bank.txt"; 
   char *buffer   = readFile(filePath); 
   int  bankSize  = getBankSize(buffer);   
   char **bank    = parse(buffer, bankSize);

   printf("Random word: %s\n", getRandomWord(bank, bankSize));   
   return 0; 
} 
