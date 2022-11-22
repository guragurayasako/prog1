//2022.11.2
/*演習問題1-2（prog01b.c）を 以下の3つの関数に分割したプログラムを作成せよ
（提出ファイル名 prog02a.c）。
 前問で作成したヘッダファイル prog01.h はそのまま使用すること。
Record input(void) : 標準入力（キーボード）から構造体への入力
void output(Record) : 構造体内容の標準出力への出力（ディスプレイへの表示）
int main() : 構造体変数 data を定義する。
 input と output をそれぞれ１回ずつよぶ*/

#include <stdio.h>
#include "prog01.h"

Record input(void);
void output (Record);

int main () {
    Record data;
    printf("データを入力してください");
    data = input();
    output(data);
}

Record input(void) {
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

void output(Record data) {
    printf("苗字: %s\n",data.familyname);
    printf("名前: %s\n",data.firstname);
    printf("生年月日 %d/%d/%d\n",data.birthday[0], data.birthday[1], data.birthday[2]);
}