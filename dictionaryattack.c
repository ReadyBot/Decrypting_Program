#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include <time.h>
#include "dictionaryattack.h"


void dictionary(char* Hash, char* salt)
{
	int h = 0;
	clock_t start, end, total;
	char eachPassword[100];
	char* encrypted;
	FILE* fPointer = fopen("./dictionary.txt", "r");

	if(fPointer == NULL)
	  	{
	    	printf("error - no file\n");
	    	exit(1);
	  	}

	start  = clock();
	
	while(fscanf(fPointer, "%s", eachPassword) != EOF)
	{
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		h++;
		
		encrypted=crypt(eachPassword,salt);
		if(total>1)
		{
		start = clock();
		printf("\rAttempted words: ...	%d", h);
		fflush(stdout);
		}
		if(strcmp(Hash, encrypted)==0)
		{
			printf("\nFor Hash:	%s\nPassword = 	%s\n", Hash, eachPassword);
			free(encrypted);
			fclose(fPointer);
			exit(0);		
		}			
	}
	printf("\rAttempted words: ...	%d", h);
	fclose(fPointer);
}


void dictionary_quick(char* Hash, char* salt)
{
	int h = 0;
	clock_t start, end, total;
	char eachPassword[100];
	char* encrypted;
	FILE* fPointer = fopen("./10000-english.txt", "r");

	if(fPointer == NULL)
	  	{
	    	printf("error - no file\n");
	    	exit(1);
	  	}

	start  = clock();
	
	while(fscanf(fPointer, "%s", eachPassword) != EOF)
	{
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		h++;
		
		encrypted=crypt(eachPassword,salt);
		if(total>1)
		{
		start = clock();
		printf("\rAttempted words: ...	%d", h);
		fflush(stdout);
		}
		if(strcmp(Hash, encrypted)==0)
		{
			printf("\nFor Hash:	%s\nPassword = 	%s\n", Hash, eachPassword);
			free(encrypted);
			fclose(fPointer);
			exit(0);		
		}			
	}
	printf("\rAttempted words: ...	%d", h);
	fclose(fPointer);
}
