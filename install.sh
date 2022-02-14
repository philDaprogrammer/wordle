#!/bin/bash 

#### 
# - Script to install wordle executable and any file dependencies 
#
####  


if [ "$UID" != "0" ]; then 
   echo 'Must be root to place executable in $PATH' 
   exit -1 
fi 

# - create config directory, bank.txt will be stored there
if [ ! -f "~/.wordle" ]; then 
   mkdir ~/.wordle 
fi 

mv bank.txt ~/.wordle     &&  
gcc -o wordle src/main.c  && 
mv wordle /usr/bin/wordle && 
rm installs.sh Makefile README.md 
rm -rdf src/

exit 0
