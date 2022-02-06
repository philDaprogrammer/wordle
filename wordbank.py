#!/usr/bin/env python3

######  
# Script to construct the 5 letter word bank by filtering 
# words from "/usr/share/dict/words"
# 
##### 

from os.path import exists 
import sys 

def main(): 
    wordPath = "/usr/share/dict/words"

    if exists("bank.txt"):
        sys.exit(0)

    if not exists(wordPath): 
        print("Could not find words file")
        sys.exit(-1) 

    bank = open("bank.txt", "w") 
    with open(wordPath) as f: 
        for line in f: 
            line = line.rstrip()
            
            if not line.__contains__("'") and not line.__contains__("é") and len(line) == 5: 
                bank.write(line + "\n")

    bank.close()
    return


if __name__ == "__main__":
    main()
