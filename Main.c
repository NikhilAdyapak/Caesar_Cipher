#include<stdio.h>
#include<stdlib.h>
#include "functions.h"								    

int main(void)
{
	printf("\n----------CAESER CYPHER----------\n");
	printf("\n\nEnter-\n1.Enter sentences\n2.To choose a text file\n3.Exit\n");
	int choice1;                                                                 //To Encrypt or Decrypt files or sentences
	scanf("%d",&choice1);
	char file[500]="input.txt";						     //Default file to write the sentences
	FILE *fptr1;
	int n,i;
	char str[1000];

	switch(choice1)
	{
		case 1:									//To Enter sentences
			printf("\n\nInput the number of lines to be written:\n");
			scanf("%d",&n);
			printf("Enter the sentences.\n");
			fptr1 = fopen (file,"w");
			for(i=0;i<n+1;i++)
			{
				fgets(str, sizeof str, stdin);
				fputs(str, fptr1);
			}
			fclose(fptr1);	
			break;
	
		case 2:									//To Enter file name
			printf("\n\nEnter the text file you want to choose\n");
			scanf("%s",file);
			break;

		case 3:									//To Exit
			exit(0);
			break;

		default:
			printf("\nInvalid choice\n");
			exit(0);
	}

	printf("\nEnter the number of shifts\n");				//Number of shifts as per users choice
	int shf;
	scanf("%d",&shf);
	shf=shf%26;								//The remainder of the shifts/26 is taken if shifts>26
	printf("\nYour choices are-\n");
	printf("1.Encrypt\n2.Decrypt\n3.Exit\n");				//Encrypt, Decrypt the file or the sentences
	printf("Enter your choice\n");
	int choice2;
	scanf("%d",&choice2);		

	switch(choice2)
	{
		case 1:								//Encrypting given sentences or file
			Encrypt(file,shf);
			printf("\n\nEncrypted Code\n");
			break;

		case 2:								//Decrypting given sentences or file
			Decrypt(file,shf);
			printf("\n\nDecrypted Code\n");
			break;

		case 3:								//Exit
			exit(0);
			break;

		default:
			printf("Invalid choice\n");
	}
	
	FILE *fptr;								//Displaying output either Encrypted or Decrypted code
	fptr=fopen("output.txt","r");
	char ch;
	ch = fgetc(fptr);
	while (ch != EOF)
	{
		printf ("%c", ch);
		ch = fgetc(fptr);
	}
	fclose(fptr);
	printf("\n");
	return 0;
}




