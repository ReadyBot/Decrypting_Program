Welcome to Cracker! v1.0

WHAT IS CRACKER?
This program is written as part of the exam evaluation in pg3400 - programming 
in C. This program will crack passwords hashed by "crypt 3", with salt and
MD5. The assignment asked for a code to decrypt by using a dictionary attack 
and a bruteforce attack. 

In this program, the user can uncrypt hash inputs by activating the program
in a terminal after running the makefile by:
./cracker 'HASH-INPUT' or
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
A makefile is included, so in the terminal find the directory where you have
place these files and simply write 'make' into the terminal. 


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


MEMORY LEAKS:
I used Valgrind to test for memory leaks I had not closed and found some issues 
while I had early matches with my dictionary attack, but manually closed those. 
Bellow is my last result on the hash for 'oi', provided in the exam and show no leaks. 

==5008== HEAP SUMMARY:
==5008==     in use at exit: 0 bytes in 0 blocks
==5008==   total heap usage: 6 allocs, 6 frees, 10,364 bytes allocated
==5008== 
==5008== All heap blocks were freed -- no leaks are possible



CREDIT:
The exam provided hash examples and the crypto.c program as basis on how to 
understand how the hash/salt work together. The hashfile, dictionary file was
provided in the exam.