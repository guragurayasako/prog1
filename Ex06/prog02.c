// B問題(50点)
//演習問題２
// 2022.10.30
/*コマンドライン引数として得点（評点）をいくつか与えると、
実行例のようにその評価 （A/B/C/D/F）を出力するプログラムを作成しなさい。
（得点と評価の対応は、 A: 80～100点, B: 65～79点, C: 50～64点, D: 35～49点, F: 35点未満）

なお、得点から評価への変換には、 演習第１回問題３ で作成した関数を流用してもよい。
\また、コマンドライン引数には得点をいくつ書いても良いこととし、引数が無い場合は何もせずに終了する。
なお、得点として0から100までの整数以外が入力された場合の処理は考えなくてよい。
 (提出ファイル名: prog02.c)*/

#include <stdio.h>
#include <stdlib.h>

char hyouka(int);

int main(int argc, char *argv[])
{
    int i;
    //関数を使って成績評価

    for (i = 1; i < argc; i++)
    {
        printf("Score:%3s Grade: %c\n", argv[i], hyouka(atoi(argv[i]))); 
        //Scoreの値は文字配列として表示、Gradeは、atoi関数でint型に変換したデータを使って成績を評価
    }

    return 0;
}

char hyouka(int x)
{
    if (80 <= x && x <= 100)
        return 'A';
    else if (65 <= x)
        return 'B';
    else if (50 <= x)
        return 'C';
    else if (35 <= x)
        return 'D';
    else
        return 'F';
}

/*実行例:
% ./a.out  100  79  64  34  48
Score:100  Grade: A
Score: 79  Grade: B
Score: 64  Grade: C
Score: 34  Grade: F
Score: 48  Grade: D
% ./a.out
%*/

/*コマンドライン引数はあくまで文字列なので、
それを得点としての整数型の値に変換する必要がある。
変換を行うには、Lec06-14（p112）で紹介された関数 atoi() を用いると良い。
関数 atoi の引数は文字ポインタ、戻り値は int型である。
 なお、この関数を使用するには、 stdlib.h をプログラムの最初でインクルードしておく必要がある。*/
