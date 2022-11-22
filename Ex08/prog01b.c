#include<stdio.h>

typedef struct{
	int id;           /* ID */
	char name[10];    /* 名前 */
	int grade;        /* 学年 */
	char subject[10]; /* 科目名 */
	char record;      /* 成績 */
}StudentInfo;

void PrintInfo1(StudentInfo);
void PrintInfo2(StudentInfo *);

int main()
{
    StudentInfo data[2] =  { { 1300091, "Yasako", 1, "prog1", 'A' },
                          { 1300107, "Andy", 1, "prog1", 'A' }};
 
    

    printf("構造体の値渡し\n");
    PrintInfo1( data[0] );
    PrintInfo1( data[1] );

    printf("構造体のアドレス渡し\n");
    PrintInfo2( &data[0] );
    PrintInfo2( &data[1] );

    return 0;
}

void PrintInfo1(StudentInfo stu)
{
    printf("%d %s %d %s %c\n", stu.id, stu.name, stu.grade, stu.subject, stu.record);
}

void PrintInfo2(StudentInfo *stu_p)
{
    printf("%d %s %d %s %c\n", (*stu_p).id, (*stu_p).name, (*stu_p).grade, (*stu_p).subject, (*stu_p).record);
}