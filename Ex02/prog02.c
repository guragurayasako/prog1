/*2022.9.11*/
/*B問題(50点)*/
/*演習問題２*/
/*与えられた 2 次元配列の要素の中から、
入力された数値と一致するものを リニアサーチにより探し出すプログラムを作成する。
一致は複数回ある可能性も考慮し、サーチ終了後に一致の回数も表示されるようにすること。
(提出ファイル名: prog02.c)*/

#include <stdio.h>
#define ROW 3
#define COL 4
 
int main()
{
  int array[ROW][COL] = {
    { 2,  3, 12,  3},
    { 4, 10,  5,  6},
    { 8,  9,  0,  7},
  };
  int n; //探す数字を入力
  int i,j;
  int cnt=0;
 
  printf("数値を入力してください: ");
  scanf("%d", &n);
  for(i=0 ; i<3 ; i++)
  {
    for(j=0 ; j<4 ; j++)
    {
        if( array[i][j]==n )
        {
            printf("array[%d][%d]が%dです\n",i,j,array[i][j]);
            cnt++;
        }
        else continue;
    }
  }

  if(cnt==0) printf("2次元配列 array の要素に %d はありません\n",n);
  else printf("2次元配列 array の要素に %d は %d 個ありました\n",n,cnt);
}

/*実行例
% ./a.out
数値を入力してください: 2
array[0][0] が 2 です
2次元配列 array の要素に 2 は 1 個ありました
% ./a.out
数値を入力してください: 3
array[0][1] が 3 です
array[0][3] が 3 です
2次元配列 array の要素に 3 は 2 個ありました
% ./a.out
数値を入力してください: 27
2次元配列 array の要素に 27 はありません
%*/