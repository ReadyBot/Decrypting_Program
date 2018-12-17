#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include <time.h>
#include "bruteforce.h"
#include "dictionaryattack.h"


int main(int argc, char** argv)
{
	if(argc!=2)	return -1;
	char* Hash=argv[1];
	int maxLen;
	char salt[13];
	strncpy(salt, Hash, 13);
	
	printf("\n\nWELCOME TO:\n\n");
	printf(" 888888  8888	  88    888888  88  88 88888 8888 	\n");
	printf("88    88 88 88   8888  88    88 88 88  88    88 88	\n");
	printf("8 	 8888   88  88 8        8888   8888  8888	\n");
	printf("88    88 88 88	888888 88    88 88 88  88    88 88	\n");
	printf(" 888888	 88  88 88  88  888888  88  88 88888 88  88	\n");

	printf("\nStarting Dictionary Attack code:\n\nTesting the 10.000 most common English words, with and w/o capital start:\n");
	dictionary_quick(Hash, salt);
	
	printf("\nNo Matches found.\n\nTesting the most used Passwords used:\n");
	dictionary(Hash, salt);
	
	printf("\nNo Matches found.\n\nStarting Bruteforce Attack code:\n");
	printf("Please input the max length of the password you want to break...\n");
	scanf("%d", &maxLen);
	brute(maxLen, Hash, salt);
	
	printf("End of program. \n\n");
}
                                        
