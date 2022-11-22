//2022.10.17
/*A問題（50点）*/
/*演習問題2（確認II・ポインタによる参照）

下記のプログラムは、初期値で設定した2つの変数 a, b の値とアドレス、 
さらにそれらの値の積（product）と商（quotient）を表示するプログラムである。 
プログラム中で宣言された２つのポインタ変数p, qを用いて、
 printfによる表示で変数a, bを使わずに同じ出力になるように書き換えよ。

(提出ファイル名: prog02.c)*/

#include <stdio.h>
 
int main(){
  double a = 7.0, b = 3.5;
  double *p, *q;
  
  /*
   * ここでポインタ変数p, qに適切な代入を行う
   * さらに以下の4行を変数 a, b を使わない形に書き換える
   */
  p = &a;
  q = &b;

  printf("Value of a: %.1f, Address of a: %p\n", *p, p);
  printf("Value of b: %.1f, Address of b: %p\n", *q, q);
  printf("Product: %.1f\n", (*p) * (*q));
  printf("Quotient: %.1f\n", (*p) / (*q));
  return 0;
}

/*実行例: （アドレスの値が違うことがある）
% ./a.out 
Value of a: 7.0, Address of a: 0x7ff7b13f9890
Value of b: 3.5, Address of b: 0x7ff7b13f9888
Product: 24.5
Quotient: 2.0*/

/*補足: アドレスの表示は16 進数での表示であることに注意せよ。 
また、状況（計算機・コンパイラ・実行環境等）によって変数のアドレスの割り当ては変化し得るので、
 表示されるアドレスがいつも同じとは限らないことに注意すること。*/
