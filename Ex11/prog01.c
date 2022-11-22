//2022.11.14
//A問題(50点)/
//演習問題１
/*２次元座標を表す Point型の構造体変数 c と a に２次元平面上の座標が格納されているとき、
 点 c を中心に、点 a を反時計まわりに指定された角度だけ回転させた点 b の座標を求めたい。

角度はキーボードから「度」単位で入力するものとする。 下記の２通りの関数を使ってそれぞれ点 b の座標を求めるプログラム を作成せよ。
(提出ファイル名: prog01.c)

２通りの関数の説明は以下の通り。なお、どちらも第１引数には 回転する角度をラジアン単位（double型）で与える。
1.
回転角度、点 c（中心）、点 a（回転させる点）を引数として受け取り、 回転後の点 b を返す関数
Point rotate1(double, Point, Point);
2.
回転角度、点 c（中心）へのポインタ、回転させる点へのポインタを受け取り、
回転後の点をそのポインタの指すアドレスに上書きする関数

void rotate2(double, Point *, Point *);
main側では、各関数の計算結果がそれぞれ Point型構造体 b1, b2 に入るようにして、
 これらをプログラムの最後で出力する。（当然 b1、b2 は同じ値になるはず）。 
 なお点 c, a の内容は変更せず、rotate2関数を呼ぶ前に点 a を b2 にコピーしておき、 
 この b2 を rotate2関数内で書き換えること。*/
 /*平面座標上で、ある点を原点の回りに回転させた時に点がどこに移るかの計算は、 
 ハンドアウトLec11-10,11 (p134)が参考になる。
  ただし、今回の問題では回転の中心が原点ではない指定された点 c であるため、 
  少し工夫が必要である。
角度は、「度*π／180」でラジアン単位に変換できる。 
円周率 π は math.h 内でマクロ M_PI として定義されているので、本プログラムではこれを使っている。
 また、この問題では数学関数を使うので、コンパイル時に -lm オプションをつけること。*/
/*参考：
座標平面上の点P(𝑎, 𝑏) を点R(𝑐, 𝑑) のまわりに 𝜃 だけ回転させた点をQ(𝑋, 𝑌) とする。
求める点Qの座標は
Q((𝑎−𝑐)cos𝜃−(𝑏−𝑑)sin𝜃+𝑐, (𝑎−𝑐)sin𝜃+(𝑏−𝑑)cos𝜃+𝑑)　となる。*/

#include<stdio.h>
#include<math.h>

typedef struct 
{
    double  x; /* x座標 */
    double  y; /* y座標 */
} Point;

Point rotate1(double, Point, Point); //回転角度、点 c（中心）、点 a（回転させる点）を引数として受け取り、 回転後の点 b を返す関数
void  rotate2(double, Point *, Point *); //回転角度、点 c（中心）へのポインタ、回転させる点へのポインタを受け取り、回転後の点をそのポインタの指すアドレスに上書きする関数


int main()
{
    double rad, deg;
    Point c = {1.0, 0.0}, a = {3.0, 2.0}; /* 中心と回転対象の点 */
    Point b1, b2;         /* 結果を入れる構造体 */

    printf("回転角 [度] を入力してください\n");
    scanf("%lf", &deg);
    rad = deg*M_PI/180;
    printf("回転角 %f [deg] (%f [rad])\n", deg, rad);
  
    b1 = rotate1(rad, c, a);
    b2 = a;
    rotate2(rad, &c, &b2);

    printf("Center  : %f %f\n", c.x, c.y);
    printf("Point A : %f %f\n", a.x, a.y);
    printf("rotate1 : %f %f\n", b1.x, b1.y);   /* 関数１の結果を出力 */
    printf("rotate2 : %f %f\n", b2.x, b2.y);   /* 関数２の結果を出力 */
    return 0;
}

Point rotate1(double theta, Point r, Point p)//自動変数を使う
{
    Point temp;

    temp.x = (p.x-r.x) * cos(theta) - (p.y-r.y) * sin(theta) + r.x;
    temp.y = (p.x-r.x) * sin(theta) + (p.y-r.y) * cos(theta) + r.y;
 
    return temp;
}

void rotate2(double theta, Point *r, Point *p)//ポインタの中身を上書き
{
    Point temp;

    temp = *p;
    p->x = (temp.x-r->x) * cos(theta) - (temp.y-r->y) * sin(theta) + r->x;
    p->y = (temp.x-r->x) * sin(theta) + (temp.y-r->y) * cos(theta) + r->y;
}


/*実行例
% gcc prog01.c -lm      （注：数学関数を使うので、-lm オプションを付けること）
% ./a.out
回転角 [度] を入力してください
90
回転角 90.000000 [deg] (1.570796 [rad])
Center  : 1.000000 0.000000
Point A : 3.000000 2.000000
rotate1 : -1.000000 2.000000
rotate2 : -1.000000 2.000000
% ./a.out
回転角 [度] を入力してください
45
回転角 45.000000 [deg] (0.785398 [rad])
Center  : 1.000000 0.000000
Point A : 3.000000 2.000000
rotate1 : 1.000000 2.828427
rotate2 : 1.000000 2.828427
%*/
