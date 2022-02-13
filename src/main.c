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


int isWord(const char *guess, words *wordInfo) { 
   for (int i=0; i < wordInfo->bankSize; ++i) {
        if (strcmp(guess, wordInfo->bank[i]) == 0) { 
           return 1; 
        }
   } 

   return 0; 
}   


int charPresent(char c, const char *word) { 
   for (int i=0; i < WORD_SIZE; ++i) { 
      if (c == word[i]) {return 1;}
   }

   return 0;  
}  


int *getCharacterOccurrence(const char *word) { 
   int offset   = 0x60;
   int *letters = (int *)calloc(26, sizeof(int));  

   for (int i=0; i < WORD_SIZE; ++i) {
      letters[word[i] - offset] += 1; 
   } 

   return letters; 
} 


void displayGuess(const char *word, const char *guess) { 
   int *letters = getCharacterOccurrence(word); 
   int offset   = 0x60; 

   for (int i=0; i < WORD_SIZE; ++i) { 
      printf("%c ", guess[i]); 
   }
   putchar('\n'); 

   for (int i=0; i < WORD_SIZE; ++i) { 
      if (word[i] == guess[i]) { 
         printf("O "); 
      } else if ((charPresent(guess[i], word)) && (letters[word[i] - offset] > 0)) { 
         printf("_ ");  
         letters[word[i] - offset] -= 1;
      } else { 
         printf("X "); 
      } 
   } 

   printf("\n\n") ; 
}  


void playGame(const char *word, words *wordInfo) { 
   char *guess = (char *)malloc(WORD_SIZE + 1); 
   size_t  len = 0; 
   int i       = 0; 

   while (i < TRIES) { 
      printf("Guess: "); 
      fgets(guess, MAX_INPUT, stdin); 

      if (guess[strlen(guess)-1] == '\n') { 
         guess[strlen(guess)-1] = '\0'; 
      } 

      if ((strlen(guess) > WORD_SIZE) || (!isWord(guess, wordInfo))) { 
         printf("Invalid guess... Try again\n\n");
         continue; 
      }

      if (strcmp(word, guess) == 0) { 
         printf("You Win!\n"); 
         return; 
      } 

      displayGuess(word, guess); 
      i++; 
   }

   printf("The word was: %s\n", word); 
} 


char *getRandomWord(char **bank, int bankSize) { 
   srand(time(0)); 
   return bank[rand() % bankSize]; 
} 


int main(int argc, char *argv[]) { 
   char *filePath         = "/home/phil/Programs/c/cse421/wordle/bank.txt"; 
   char *buffer           = readFile(filePath); 
   words *wordInfo        = (words *)malloc(sizeof(words)); 
   wordInfo->bankSize     = getBankSize(buffer); 
   wordInfo->bank         = parse(buffer, wordInfo->bankSize);
   char *randomWord       = getRandomWord(wordInfo->bank, wordInfo->bankSize); 


   playGame(randomWord, wordInfo); 
   return 0; 
} 
