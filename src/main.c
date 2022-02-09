#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "parser.c"


#define WORD_SIZE 5 
#define TRIES 6 
#define MAX_INPUT 256 

void playGame(const char *word) { 
   char *guess = (char *)malloc(WORD_SIZE + 1); 
   size_t  len = 0; 

   for (int i=0; i < TRIES; ++i)  { 
      printf("Guess: "); 

      fgets(guess, MAX_INPUT, stdin); 
   
      if (strlen(guess) > 6) { 
         printf("Input Error\n");
         break; 
      }
   } 
} 

char *getRandomWord(char **bank, int bankSize) { 
   srand(time(0)); 
   return bank[rand() % bankSize]; 
} 


int main(int argc, char *argv[]) { 
   char *filePath = "/home/phil/Programs/c/cse421/wordle/bank.txt"; 
   char *buffer   = readFile(filePath); 
   int  bankSize  = getBankSize(buffer);   
   char **bank    = parse(buffer, bankSize);

   playGame(getRandomWord(bank, bankSize)); 
   return 0; 
} 
