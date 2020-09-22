Welcome to Cracker! v1.0

WHAT IS CRACKER?
This program will crack passwords hashed by "crypt 3", with salt and
MD5. It tries to crack/decrypt hashed passwords by using a dictionary attack 
and a bruteforce attack. 

In this program, the user can uncrypt hash inputs by activating the program
in a terminal after running the makefile by:
./cracker 'HASH-INPUT' 
or ie: 
./cracker '$1$aTWHXMtg$akUOXns69Uzn44CGTLQ7S0'.

The program will then start a two part dictionary attack, first search through
the 10.000 most used words in the englih language, first small letters then 
with a capital letter at the start. The second part of the dictionary attack
will then try the ~1mill most used passwords, a file provided in the exam.

Finally, if the passwords was not found, the program will start a bruteforce 
attack, where the user can input the max length of the attempted password. 

I've chosed to do two dictionary attacks before the bruteforce, as the latter
will take very long, and I found more success with a combination. The cracked
hashed passwords have been written down respectivly in the hash file.


INSTALL:
A makefile is included, so in the terminal; locate the directory where you have
place these files and write 'make' into the terminal. 


FILES INCLUDED:
-textfile containing 10.000 most used english words 
-textfile containing ~1mill most used passwords
-makefile
-cracker.c
-dictionaryattack.c
-dictionaryattack.h
-bruteforce.c
-bruteforce.h
-textfile with example hashes to test the program.
-crypto.c
