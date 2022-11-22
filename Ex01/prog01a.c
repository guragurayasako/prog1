//2022.10.13
//A問題
//演習問題１
/*ハンドアウトLec01-17 (p85)にあるサンプルプログラムlec01-5.cを参考にして、
 実行例のように「１文字＋改行」の入力で、その文字のアスキーコード （１０進と１６進）を表示して終了するプログラムを作成せよ。
(提出ファイル名: prog01a.c)*/

#include<stdio.h>

int main()
{
    int a;
    printf("Input a character: ");
    scanf("%lc",&a);
    printf("ASCII code of '%c' is %d(Ox%x)\n",a,a,a);
    return 0;
}
/*実行例
% ./a.out
Input a character: X
ASCII code of 'X' is 88(0x58). 
% ./a.out
Input a character: x
ASCII code of 'x' is 120(0x78). 
% ./a.out
Input a character: .
ASCII code of '.' is 46(0x2e).
%*/