//2022.11.8
//B問題(50点)
//問題2(構造体の入れ子構造)
/*以下のように、2次元平面上の点を表すためにXY型の構造体と 
それを使って円を表すためのCIRCLE型構造体を宣言した。 
CIRCLE型構造体は中心点をXY型構造体， 
円周上の１点をXY型構造体、
半径をdouble型の変数で表現している。

この構造体を使用し、2次元平面上の円の中心点および円周上の１点の座標を入力し、
 円の周長と円の面積を求めるプログラムを作成しなさい。

ただし、データの入力処理については、以下のプロトタイプにあるように、 
値の受渡し方法が異なる2種類の関数を作成して用いることする。 
また、この関数内で半径の値を計算して、メンバ変数rにその値を代入すること。 
そして、実行例にあるように動作確認を行う。（必要に応じて関数を追加しても良い。）
(提出ファイル名 prog02.c)*/

#include <stdio.h>
#include <math.h>

typedef struct{
	double x; /* x座標 */
	double y; /* y座標 */
}XY; /* 平面上の点 */
 
typedef struct{
	XY center;//中心
	XY p;//円周上の一点
	double r;//半径
}CIRCLE; /* centerを中心点、pを円周上の点、rを半径とする円 */

CIRCLE input1(void);   /* データを読み込んだ構造体を戻す */
void input2(CIRCLE *); /* 構造体のポインタを渡し、そこにデータを読み込む */

int main()
{
    double length, area;
    double center_x, center_y, p_x, p_y;
    CIRCLE circle;
    XY center, p;


    printf("データの入力（構造体を返す関数）:\n");
    input1();
    length = circle.r * 2 * M_PI;
    area = circle.r * circle.r * M_PI;
    printf("rrrrrrr%fceeeee%f\n",circle.r,circle.p.y);
    printf("input1: length,area: %9.6f,%9.6f\n",length,area);

    printf("データの入力（構造体ポインタを使う関数）:\n");
    scanf("%lf%lf%lf%lf", &circle.center.x, &circle.center.y, &circle.p.x, &circle.p.y);
    circle.r = sqrt((circle.center.x - circle.p.x)*(circle.center.x - circle.p.x) + (circle.center.y - circle.p.y)*(circle.center.y - circle.p.y));
    input2(&circle);
    
    return 0;
}

CIRCLE input1(void)
{
    CIRCLE circle;

    scanf("%lf%lf%lf%lf", &circle.center.x, &circle.center.y, &circle.p.x, &circle.p.y);
    circle.r = sqrt((circle.center.x - circle.p.x)*(circle.center.x - circle.p.x) + (circle.center.y - circle.p.y)*(circle.center.y - circle.p.y));

    return circle;
}

void input2(CIRCLE *c)
{
    double length, area;
    length = c->r * 2 * M_PI;
    area = c->r * c->r * M_PI;
    printf("input2: length, area : %9.6f, %9.6f\n", length, area);
}


/*実行例：
% ./a.out
データの入力（構造体を返す関数）:
0.0 0.0 0.0 2.0
input1: length, area : 12.566371, 12.566371
データの入力（構造体ポインタを使う関数）:
0.0 0.0 0.0 2.0
input2: length, area : 12.566371, 12.566371
% ./a.out
データの入力（構造体を返す関数）:
-2.0 -2.0 -2.0 -3.0
input1: length, area : 6.283185, 3.141593
データの入力（構造体ポインタを使う関数）:
1.0 1.0 2.0 1.0
input2: length, area : 6.283185, 3.141593*/

/*本プログラムにおいて、math.hをインクルードすることで， 
円周率を表すM_PIを使用することができる。
また、math.hをインクルードすることで，平方根を計算するsqrtを使用できる。
math.hをインクルード場合，コンパイル時の-lmオプション指定を忘れないこと。*/