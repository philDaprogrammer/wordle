#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "parser.c"

#define WORD_SIZE 5 
#define TRIES 6 
#define MAX_INPUT 256 

typedef struct words { 
   char **bank;
   int bankSize; 
} words; 


void playGame(const char *word) { 
   char *guess = (char *)malloc(WORD_SIZE + 1); 
   size_t  len = 0; 
   int i       = 0; 

   while (i < TRIES) { 
      printf("Guess: "); 
      fgets(guess, MAX_INPUT, stdin); 

      if (guess[strlen(guess)-1] == '\n') { 
         guess[strlen(guess)-1] = '\0'; 
      } 

      if (strlen(guess) > WORD_SIZE) { 
         printf("Guess is too long... Try again\n");
         continue; 
      }

      i++; 
   }

   printf("You loose\n"); 
} 


char *getRandomWord(char **bank, int bankSize) { 
   srand(time(0)); 
   return bank[rand() % bankSize]; 
} 


int main(int argc, char *argv[]) { 
   char *filePath         = "/home/phil/Programs/c/cse421/wordle/bank.txt"; 
   char *buffer           = readFile(filePath); 
   struct words *wordInfo = (struct words *)malloc(sizeof(words)); 
   wordInfo->bankSize     = getBankSize(buffer); 
   wordInfo->bank         = parse(buffer, wordInfo->bankSize);


   playGame(getRandomWord(wordInfo->bank, wordInfo->bankSize)); 
   return 0; 
} 
