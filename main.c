#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define correct_ans 4
#define wrong_ans -1
#define no_of_qns 4 //count the number of questions in the question bank (qb.txt)

void enterDetails(char name[], char srn[]);

struct info 
{
	char q[200], a[50], b[50], c[50], d[50];
	int an;
};

void main() 
{
	char name[40], srn[13];

	printf("Enter your SRN: ");
	scanf("%s", &srn);

	int score = 0, choice;

	struct info e[no_of_qns];

	FILE* fq = fopen("qb.txt", "r");
	char line[450], *item;
	int i = 0;
	while(fgets(line, 450, fq)) 
	{
		item = strtok(line, ",");
		strcpy(e[i].q, item);

		item = strtok(NULL, ",");
		strcpy(e[i].a, item);

		item = strtok(NULL, ",");
		strcpy(e[i].b, item);

		item = strtok(NULL, ",");
		strcpy(e[i].c, item);

		item = strtok(NULL, ",");
		strcpy(e[i].d, item);

		item = strtok(NULL, ",");
		e[i].an = atoi(item);

		i++;
	}
	fclose(fq);

	for(i = 0; i < no_of_qns; i++) 
	{
		printf("\n%s\n%s\t%s\t%s\t%s\n", e[i].q, e[i].a, e[i].b, e[i].c, e[i].d);
		printf("Enter your choice (1, 2, 3 or 4): ");
		scanf("%d", &choice);

		if(choice == e[i].an) 
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

	printf("\nYour score is: %d", score);

	FILE* fr = fopen("results.txt", "a");
	fprintf(fr, "SRN: %s, Score: %d\n", srn, score);
	fclose(fr);
}
