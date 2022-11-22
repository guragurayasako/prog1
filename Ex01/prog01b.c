/*2022.10.13*/
/*A問題(50点)*/
/*演習問題１*/
/*prog01a.cで作ったプログラムを改良して、複数の文字のコードを出力できるようにする。 
実行例のように「複数文字＋改行」の入力で、
その文字のアスキーコード （１０進と１６進）を順にすべて表示するプログラムを作成せよ。 
なお、ハンドアウトLec01-18 (p85)のサンプルプログラムlec01-6a.cを参考に、
無限ループを使用し、複数文字に対応させること。
ただし、ループの脱出条件を「改行文字を読み込んだ場合」として、
改行の入力で終わる1行分のアスキーコード出力だけを行うこと
（サンプルプログラムでは終了条件が改行文字ではなくEOFとなっているので、
Control+Dを入力するまで何度でも処理を繰り返すようになっていることに注意）。
プログラム中での改行文字の表現についてはハンドアウトLec01-14 (p84) を参照すること。
 なお、改行文字のASCIIコードは出力不要とする。
(提出ファイル名: prog01b.c)

補足：標準入力（キーボードからの入力）は、1文字入力されるたびにすぐプログラムのscanf関数には引き渡されるわけではない。 
一旦バッファと呼ばれる領域に保存され、改行が入力されたところで初めてプログラムに渡され、処理が行われる。 
今回のようにscanf関数が %c で文字入力を受け付けている場合は、
バッファに保存された文字の並びの先頭から1文字づつscanf関数に渡され、 
ループが一つ回るごとに処理が進行する。4文字＋改行が入力された場合、 
ループは5回まわることになる（改行も一文字にカウントされる）。*/

#include<stdio.h>

#define MAX 20
int main()
{
    int str[MAX]; //入力された文字を文字配列に代入
    int i; //カウンタ
    int cnt=0; //文字数カウント
    printf("Input any characters: ");
    while(1)
    {
        scanf("%lc",&str[cnt]);
        if( str[cnt] == '\n' ) break;
        else cnt++;
    }

    for( i=0 ; i<cnt ; i++ )
    {
        printf("ASCII code of '%c' is %d(Ox%x).\n",str[i],str[i],str[i]);
    }
    
    return 0;
}

/*実行例
% ./a.out
Input any characters: char
ASCII code of 'c' is 99(0x63). 
ASCII code of 'h' is 104(0x68). 
ASCII code of 'a' is 97(0x61). 
ASCII code of 'r' is 114(0x72). 
% ./a.out
Input any characters: NULL
ASCII code of 'N' is 78(0x4e). 
ASCII code of 'U' is 85(0x55). 
ASCII code of 'L' is 76(0x4c). 
ASCII code of 'L' is 76(0x4c). 
%*/