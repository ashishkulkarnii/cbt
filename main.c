#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

#define correct_ans 4 //positive marking
#define wrong_ans -1 //negative marking
#define no_of_qns 4 //number of question in qb.txt

void enterDetails(char name[], char srn[]);

struct info //to store all the info about each question: the question, options and the correct option
{
	char q[200], a[50], b[50], c[50], d[50];
	int an;
};

void main() 
{

	system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|        COMPUTER BASED TEST SIMULATOR          |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              BROUGHT TO YOU BY                |\n");
	printf("\t\t|          |Ashish, Anush and Azhar|            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	char name[40], srn[13];

	printf("Enter your SRN: ");
	scanf("%s", &srn); //taking srn as input from the user

	int score = 0, choice;

	struct info e[no_of_qns]; //creating an array of the "info" structure

	FILE* fq = fopen("qb.txt", "r");
	char line[450], *item;
	int i = 0;
	while(fgets(line, 450, fq)) 
	{

//storing question in the "info" structure

		item = strtok(line, ",");
		strcpy(e[i].q, item);

//storing options in the "info" structure

		item = strtok(NULL, ",");
		strcpy(e[i].a, item);

		item = strtok(NULL, ",");
		strcpy(e[i].b, item);

		item = strtok(NULL, ",");
		strcpy(e[i].c, item);

		item = strtok(NULL, ",");
		strcpy(e[i].d, item);

//storing correct option number in the "info" structure

		item = strtok(NULL, ",");
		e[i].an = atoi(item);

		i++;
	}
	fclose(fq);

//randomizing order of questions

	int n[100], temp;

	for(i = 0; i < no_of_qns; i++) 
		n[i] = i;

	for(i = 0; i < no_of_qns; i++) 
	{
		srand(time(0));
		for(i = 1; i < no_of_qns; i++)
		{
			if(rand() % 2 == 0)
			{
				temp = n[0];
				n[0] = n[i];
				n[i] = temp;
			}
		}
	}

	for(i = 0; i < no_of_qns; i++) 
	{
		printf("%d\t", n[i]);
	}
	
//presenting the user with the question and the options, and asking them to make their choice

	for(i = 0; i < no_of_qns; i++) 
	{
		printf("\n%s\n%s\t%s\t%s\t%s\n", e[n[i]].q, e[n[i]].a, e[n[i]].b, e[n[i]].c, e[n[i]].d);
		printf("Enter your choice (1, 2, 3 or 4): ");
		scanf("%d", &choice);

//comparing the user's choice with the correct option, and incrementing or decrementing their score

		if(choice == e[n[i]].an) 
		{
			score += correct_ans;
			printf("Your answer is correct!\n");
		}

		else 
		{
			score += wrong_ans;
			printf("Your answer is incorrect.\n");
		}
	}

//displaying the student's score

	printf("\nYour score is: %d\n", score);

//adding the student's SRN and score to the results.txt file

	FILE* fr = fopen("results.txt", "a");
	fprintf(fr, "SRN: %s, Score: %d\n", srn, score);
	fclose(fr);

//keeping the screen open

	getch();
}
