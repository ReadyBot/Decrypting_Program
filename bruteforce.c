#include "bruteforce.h"
#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>
#include <time.h>


char allowedChars[80] = "abcdefghikjlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+\"#&/()=?!@$[]|{}";
int n=sizeof(allowedChars)-1;


int validate(char c)
{ 
	int k;
	

	if(c == '\0')
	{ 
		k=0;
		return k;
	}
	for(int j=0;j<n;j++)
	{ 
		if(allowedChars[j]==c)
		{
			k=j+1;
			return k;
		}
		
	}
	return 0;
}



int check(char* array, int maxLen)
{
int a;

	for(int j=1;j<=maxLen; j++)
	{	
		if(array[j] == '}') 
		{
			strncpy(array+j, &allowedChars[0], 1);
			j++;	
		}
		
		if(array[j] != '}'){
			a=j;
			return a;
		}
			
	}
	return 0;
}



void brute(int maxLen, char* Hash, char* salt)
{
	char *array = calloc(maxLen, sizeof(char));
	char* encrypted;
	char c;
	int a, k;
	int j = sizeof(allowedChars);
	int h = 0;
	clock_t start, end, total;
	
	start  = clock();

	for(int i=0;i<j;i++)
	{	
		
		if(i==n)
		{		
			a = check(array, maxLen);
			c = array[a];
			k = validate(c);
			strncpy(array+a, &allowedChars[k], 1);
			i=0;		
		}
		if(a==maxLen){
			printf("\nNo passwords found within the max length of %d\n", maxLen);
			break;
		}
		
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		h++;
		strncpy(array, &allowedChars[i], 1);
		encrypted=crypt(array, salt);
		if(strcmp(Hash, encrypted)==0)
		{
			printf("\nAttempted combinations: ...	%d\nFor Hash:	%s\nPassword = 	%s\n", h, Hash, array);
			
			break;		
		}
		if(total>1)
		{
		start = clock();
		printf("\rAttempted combinations: ...	%d", h);
		fflush(stdout);
		}			
	}
	free(array);
	free(encrypted);	
}
