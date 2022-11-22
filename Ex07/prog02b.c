#include <stdio.h>
#include "prog01.h"

Record input(void);
void output (Record);
int getAge(Record);

int main () 
{
    Record data1,data2;
    printf("--------データ入力--------\n");
    printf("1人目の データを入力して下さい\n");
    data1 = input();
    printf("2人目の データを入力して下さい\n");
    data2 = input();
    printf("--------データ出力--------\n");
    printf("年齢基準日: 2022/10/1\n");
    printf("1人目のデータ:\n");
    output(data1);
    printf("2人目のデータ:\n");
    output(data2);
}

Record input(void) 
{
    Record data;

    printf("苗字 -&gt;");
    scanf("%s", data.familyname);
    
    printf("名前 -&gt;");
    scanf("%s", data.firstname);
    
    printf("生まれた年（西暦） -&gt;");
    scanf("%d", &amp;data.birthday[0]);
    
    printf("生まれた月 -&gt;");
    scanf("%d", &amp;data.birthday[1]);
    
    printf("生まれた日 -&gt;");
    scanf("%d", &amp;data.birthday[2]);
    printf("\n");
    return data;
}

void output(Record data)
{
    int Age;
    printf("苗字: %s\n",data.familyname);
    printf("名前: %s\n",data.firstname);
    Age = getAge(data);
    printf("生年月日 %d/%d/%d 年齢: %d\n",data.birthday[0], data.birthday[1], data.birthday[2],Age);
}

int getAge(Record data)
{
    int age;
    age = 2022 - data.birthday[0];
    if (data.birthday[1] &gt;= 10) {
        age--;
    }
    return age;
}