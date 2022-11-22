#include <stdio.h>
#include "prog01.h" 
#define N 20

Record input(void);
void output (Record);
int getAge(Record);

int main () {
    Record data[N];
    int i,j;
    for (i = 0; i < N; i++) {
        data[i] = input();
        if(data[i].birthday[0] = -1) break;
    }
    printf("--------データ出力--------\n");
    printf("年齢基準日: 2022/10/1\n");
    for (j = 0; j < i ; j++) {
        printf("%3d人目のデータ: ",j + 1);
        output(data[j]);
    }
}

Record input(void) {
    Record data;
    int dstate;
    dstate = scanf("%s",data.familyname);
    if (dstate == EOF) data.birthday[0] = -1;
    scanf("%s", data.firstname);
    scanf("%d", &data.birthday[0]);
    scanf("%d", &data.birthday[1]);
    scanf("%d", &data.birthday[2]);
    return data;
}

void output(Record data) {
    int Age,i = 0;
    Age = getAge(data);
    printf("氏名: %s\t%s\t, 生年月日: %d/ %d/%d, 年齢: %d\n",data.familyname,data.firstname,data.birthday[0], data.birthday[1], data.birthday[2],Age);    
}

int getAge(Record data) {
    int age;
    age = 2022 - data.birthday[0];
    if (data.birthday[1] >= 10) {
        age--;
    }
    return age;
}