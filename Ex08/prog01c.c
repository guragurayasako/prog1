//2022.11.2
//A問題
#include<stdio.h>

#define N 20

typedef struct{
	int id;           /* ID */
	char name[10];    /* 名前 */
	int grade;        /* 学年 */
	char subject[10]; /* 科目名 */
	char record;      /* 成績 */
}StudentInfo;

int InputData(StudentInfo *);
void PrintInfo1(StudentInfo);
void PrintInfo2(StudentInfo *);

int main()
{
    StudentInfo data[N];
    int i=0, j=0;

    while(InputData(&data[i]) != EOF)
    {
            i++;
    }

    printf("構造体の値渡し\n");
    for( j=0 ; j<i ; j++ )
    {
        PrintInfo1( data[j] );
    }

    printf("構造体のアドレス渡し\n");
    for( j=0 ; j<i ; j++ )
    {
        PrintInfo2( &data[j] );
    }

    return 0;
}

int InputData(StudentInfo *stu_p)
{
    return scanf("%d %s %d %s %c", &stu_p->id, stu_p->name, &stu_p->grade, stu_p->subject, &stu_p->record);
}

void PrintInfo1(StudentInfo stu)
{
    printf("%d %s %d %s %c\n", stu.id, stu.name, stu.grade, stu.subject, stu.record);
}

void PrintInfo2(StudentInfo *stu_p)
{
    printf("%d %s %d %s %c\n", (*stu_p).id, (*stu_p).name, (*stu_p).grade, (*stu_p).subject, (*stu_p).record);
}
