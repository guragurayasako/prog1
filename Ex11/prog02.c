//2022.11.17
//B問題(50点)
//演習問題２
/*問１と同様な関数を、さらに２つ作成する。 
プログラムは prog01.c を prog02.c にコピーしたものをベースにして作成するとよい。 (提出ファイル名: prog02.c)

２つの関数の説明とプロトタイプは以下の通り。 
ここでも、第１引数は回転角（ラジアン単位）である。
3.
二つの点を Point型構造体の配列（２個の要素をもち、 要素０が中心、要素１が回転させる点）として受け取り、
回転後の点を返す関数
Point rotate3(double, Point *);
4.
二つの点を Point型構造体の配列（３個の要素をもち、 要素０が中心、要素１が回転させる点）として受け取り、
回転後の点を その配列の要素２に代入する関数
void rotate4(double, Point *);
これらの関数を使用するために、main側では Point型構造体の配列二つ（一つは要素数２、もう一つは要素数３） を宣言し、
それぞれ rotate3関数と rotate4関数への座標値の受け渡しに用いること。 
また、rotate3関数の戻り値を受け取るための Point型構造体の変数も宣言する必要がある。*/

#include<stdio.h>
#include<math.h>

typedef struct 
{
    double  x; /* x座標 */
    double  y; /* y座標 */
} Point;

Point rotate3(double, Point *);
void rotate4(double, Point *);

int main()
{
    double rad, deg;
    Point c = {1.0, 0.0}, a = {3.0, 2.0}; /* 中心と回転対象の点 */
    Point p;
    Point point3[2]; //要素０が中心、要素１が回転させる点
    Point point4[3]; //要素０が中心、要素１が回転させる点,開店あとのその配列の要素２に代入する関数

    point3[0] = c;
    point4[0] = c;
    point3[1] = a;
    point4[1] = a;

    printf("回転角 [度] を入力してください\n");
    scanf("%lf", &deg);
    rad = deg*M_PI/180;
    printf("回転角 %f [deg] (%f [rad])\n", deg, rad);
  
    p = rotate3(rad, point3);
    rotate4(rad, point4);

    printf("Center  : %f %f\n", c.x, c.y);
    printf("Point A : %f %f\n", a.x, a.y);
    printf("rotate1 : %f %f\n", p.x, p.y);   /* 関数１の結果を出力 */
    printf("rotate2 : %f %f\n", point4[2].x, point4[2].y);   /* 関数２の結果を出力 */
    return 0;
}

Point rotate3(double theta, Point *point)//自動変数を使う
{
    Point temp;

    temp.x = (point[1].x-point[0].x) * cos(theta) - (point[1].y-point[0].y) * sin(theta) + point[0].x;
    temp.y = (point[1].x-point[0].x) * sin(theta) + (point[1].y-point[0].y) * cos(theta) + point[0].y;

    return temp;
}

void rotate2(double theta, Point *point)//ポインタの中身を上書き
{
    Point temp;

    temp = point[1];
    point[1].x = (temp.x-point[0].x) * cos(theta) - (temp.y-point[0].y) * sin(theta) + point[0].x;
    point[1].y = (temp.x-point[0].x) * sin(theta) + (temp.y-point[0].y) * cos(theta) + point[0].y;
}


/*実行例
% ./a.out
回転角 [度] を入力してください
90
回転角 90.000000 [deg] (1.570796 [rad])
Center  : 1.000000 0.000000
Point A : 3.000000 2.000000
rotate3 : -1.000000 2.000000
rotate4 : -1.000000 2.000000
% ./a.out
回転角 [度] を入力してください
225
回転角 225.000000 [deg] (3.926991 [rad])
Center  : 1.000000 0.000000
Point A : 3.000000 2.000000
rotate3 : 1.000000 -2.828427
rotate4 : 1.000000 -2.828427
%*/