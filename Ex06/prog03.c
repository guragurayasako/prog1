//B問題（50点）
//演習問題３
//2022.10.30

/*２つの数の間を等間隔に分割して、数値の列を作る事を考える。
 例えば、0.0 から 2.0 まで等間隔に並ぶ5つの数値を作るとすると、
  0 から 2 の間を（両端にも数値があるので）5-1 = 4つの区間に 等分することになるので、
  0.5 おきに数値を並べて、 0.0, 0.5, 1.0, 1.5, 2.0 となる。

それでは、最初の数値、最後の数値、作る値の個数、を入力すると、
 「最初の数値」～「最後の数値」まで等間隔に並ぶ値が格納された配列を 動的メモリ割り当てによって作成し、
 格納された値すべてを表示し、 さらに各々の値の２乗も表示する（小数点以下３桁まで；実行例参照）プログラムを作成しなさい。

なお、「最初の数値」と「最後の数値」は浮動小数点数、
「作る値の個数」は2以上の整数とする （エラーチェックはしなくてよい）。 
動的メモリ割り当てで確保するメモリは「作る値の個数」に応じた必要最小限とすること。 
(提出ファイル名: prog03.c)*/

#include <stdio.h>
#include ________

int main()
{
  int num, i;
  double f_value, l_value;
  double *x;

  /* 最初の値、最後の値、数値の個数を入力 */
  printf("Input First value, Last value, Total number: ");
  scanf("%lf%lf%d", &f_value, &l_value, &num);

  /* これ以降を作成すること */

  /* メモリ確保 */

 /* 格納する値の決定。
    端の値のぶんを考慮して分割数を決める事と、整数除算しないように注意 */

  /* 結果の表示 */

  /* メモリ確保したので後処理をする */
  
  return 0;
}

/*実行例:
% ./a.out
Input First value, Last value, Total number: 0.0  2.0  5
Values of x
0.000 0.500 1.000 1.500 2.000
Values of x^2
0.000 0.250 1.000 2.250 4.000
% ./a.out
Input First value, Last value, Total number: 1.0  3.0  11
Values of x
1.000 1.200 1.400 1.600 1.800 2.000 2.200 2.400 2.600 2.800 3.000
Values of x^2
1.000 1.440 1.960 2.560 3.240 4.000 4.840 5.760 6.760 7.840 9.000
%*/