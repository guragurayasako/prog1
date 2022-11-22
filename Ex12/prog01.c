//2022.11.17
//A問題(50点)
//問題１（マクロ関数）
/*
下記のマクロ関数を使ったプログラムは、引数の与え方によって正しく動作しない場合がある。

#include <stdio.h>

#define func(x)  x*x-4*x+4

int main()
{
  int a = 2;
  double b = 1.5;

  printf("a=%d, b=%f\n", a, b);
  printf("func(a) = %d\n", func(a));
  printf("func(a+2) = %d\n", func(a + 2));
  printf("func(a)*4 = %d\n", func(a) * 4);
  printf("func(b) = %f\n", func(b));
  printf("func(b+2.5) = %f\n", func(b + 2.5));

  return 0;

  実行結果（一部の結果は正しくない）
% ./a.out
a=2, b=1.500000
func(a) = 0
func(a+2) = 6　　　　　←???
func(a)*4 = 12　　　　←???
func(b) = 0.250000
func(b+2.5) = 8.250000　　　　　←???
}


1.
上記のプログラムでは、func(a) は a*a-4*a+4 に置き換えられる。 
では、func(a+2) や func(a)*4 がどんな式に置き換えられるか考えて、 
正しくない実行結果が出力される理由を prog01.txt に記述しなさい。
例：
元のプログラムでは、
func(a+2)は、"どのような式に置き換えられ、どのような答えが得られるのか？"
正しい結果を得るためには、"func(x)をどのようにすればいいのか？"
そうすれば、func(a+2)は、"どのような式に置き換えられ、どのような答えが得られるのか？"
となるから、正しい結果を得られるはずである。
2.
プログラムが正しく動作するように、マクロの定義のみを修正し、 prog01.c というファイル名で保存しなさい。 
ただし、引数に自己の値を変更するような式（インクリメント、デクリメント、i=i+2のような式） 
は含まれないと仮定してよい。
(提出ファイル名：prog01.txt, prog01.c)*/

#include <stdio.h>

#define func(x)  x*x-4*x+4

int main()
{
  int a = 2;
  double b = 1.5;

  printf("a=%d, b=%f\n", a, b);
  printf("func(a) = %d\n", func(a));
  printf("func(a+2) = %d\n", func((a+2)));
  printf("func(a)*4 = %d\n", (func(a)) * 4);
  printf("func(b) = %f\n", func(b));
  printf("func(b+2.5) = %f\n", func((b + 2.5)));

  return 0;
}


/*正しい実行例
%./a.out
a=2, b=1.500000
func(a) = 0
func(a+2) = 4
func(a)*4 = 0
func(b) = 0.250000
func(b+2.5) = 4.000000*/