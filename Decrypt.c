#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

void Decrypt(char file[],int shf)
{
	FILE *fptr2;
	FILE *fptr3;
	fptr3=fopen("output.txt","w");					//Opening output file to write the Encrypted code
	fptr2=fopen(file,"r");						//Opening input file to Decrypt the code
	if(fptr2==NULL || fptr3==NULL)
	{
		printf("\nUnable to open the file\n");
		exit(-1);
	}
	char str1,str2;							//str1 for taking each character of input file
	int ch;								//ch to check whether the character is in the range of a-z or A-Z
	str1 = fgetc(fptr2);
	while (str1 != EOF)
	{
		ch=(int)str1;
		if((ch>=65 && ch<=90)||(ch>=97 && ch<=122))		//Decryption being done to alphabets whose ASCII ranges are checked
		{
			if((ch-shf<65) || (ch>=97 && ch-shf<97))	//To check if by shifting,the character is a/A and to restart shifting from z/Z 
				ch=ch-shf+26;
			else
				ch-=shf;				//Normal reverse shifting
		}
		str2=(char)ch;
		fputc(str2,fptr3);
		str1 = fgetc(fptr2);
	}
	fclose(fptr2);
	fclose(fptr3);
}

