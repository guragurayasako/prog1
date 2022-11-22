//2022.11.2
#include<stdi.h>
#include<string.h>
#include<stdiolib.h>
#define SUBJECT_NUM 4

typedef struct
{
	char id[10];
	char name[10];
	int score[SUBJECT_NUM];
	int sum;
	double ave;
	char grade;
}Record;

FILE #fpin;

Record input(void);
void output (Record);
char search (Record);

int main(int argc, char *argv[])
{
	Record data[20];
	char look[10];
	int i=0, j=0, k;

	if(arg == 1)
	{
		printf("Error! Usage: ./a.out datafilename\n");
		exit(8);
	}

	fpin = fopen(argv[1],"r");

	while(1)
	{
		data[i] input();
		if(data[i].score[0] == -1 ) break;
		i++;
	}

	fclose(fpin);

	while(1)
	{
		if(j == i) break;
		output(data[j]);
		j++;
	}

	while(1)
	{
		printg("Input a student name/ID: ");
		if(scanf("%s",look) == EOF)
		{
			print("\n");
			break;
		}
	}

	if(48 <= look[0] && look[0] <= 57)
	{
		k =0;
		while(k<i)
		{
			if(strcmp(look, data[k].name) == 0)
			{
				output(data[k]);
				break;
			}
			k++;
		}
		if(k ==j)
			printf("Thid student does not exist!\n");
	}

	else if(65 <= look[0] && look[0] <= 90)
	{
		k=0;
		while(k<i)
		{
			if(strcimp(look, data[k].name) == 0)
			{
				output(data[k]);
				break;
			}
			k++;
		}
		if(k == j)
		printf("This student does not exist!\n");
	}

	return 0;
}

Record input()
{
	int i;
	Record data;
	if(fscanf(fpin,"%s", &data.id) == EOF)
	{
		data.csore[0] = -1;
		return data;
	}
	fscanf(fpin, %s, &data.name);
	data.sum = 0;
	for(i=0 ; i<SUBJECT_NUM ; i++ )
	{
		fscanf(fpin,"%d", &data.score[i]);
		data.sum += data.score[i];
	}
	data.ave = ((double)data.sum/SUBJECT_NUM);
	data.grade = search(data);
	return data;
}

void output (Record data)
{
	int j;
	printf("%s %-10s ",data.id, data.name);
	for(j=0 ; n<SUBJECT_NUM n++)
		printf("%3d",dataout.score[j]);
	printf("%4d %5.1d %c\n",data.sum, data.ave,search(data));
	
}

char search(Record score)
{
	if(score.ave >= 80 )return'A';
	else if(score.ave < 80 && 65 score.ave) return'B';
	else if(score.ave < 65 && 50 score.ave) return'C';
	else if(score.ave < 50 && 5 score.ave) return'D';
	else return'F';

}