/*2022.10.13*/
/*A問題(50点)*/
/*演習問題1*/
/*以下のプログラムは、ファイル in.txt を開き、
その内容を out.txt にコピーするものである。

また、stdlib.hをインクルードしてexit()を使用して、
エラー時にプログラムを強制終了するようにしている。
これを変更して、以下のようなプログラムを作成せよ。

ファイル input1.txt を読み込み用として開く。
output1-ans.txt を書き込み用ファイルとして開く。
input1.txt の内容を読み込み、文字配列（ハンドアウトLec03-19, 20参照）に格納する。
文字配列に格納された内容について、大文字があればその文字を小文字に変換し、 
それ以外の文字はそのまま output1-ans.txt に書き込む。
次に、改行を利用して1行空けてから、同じ文字配列の内容について、
今度は小文字を大文字に変換し、 それ以外はそのまま output1-ans.txt に追加書き込みする。
さらに、改行を利用して1行空けてから、同じ文字配列の内容について、
大文字は小文字に、 小文字は大文字に変換して output1-ans.txt に追加書き込みする。
結果として、output1-ans.txt には、 大文字、小文字が異なるだけの同じ文章が 3 セット書き込まれることになる。

注意
入力データの文字数は 500 文字より少ないものとして文字配列のサイズを決めること。
ファイルからの読み込みは何度も繰り返さず、1回だけ行うものとする。
3通りの書き込みの区切りに対して、改行を利用して1行空けて、内容を見やすくせよ（以下の output1.txt の内容を参照）。
大文字化、小文字化などは、自分で関数を作って使用することとするが、 過去の演習で作成した関数を修正して再利用してもよい（但し自分で作ったものに限る）。
入力データ末尾には改行文字がないことに注意をすること。
(提出ファイル名: prog01.c)*/

/*input1.txt の内容

C is an imperative, procedural language in the ALGOL tradition. It has a static type system. In C, all executable code is contained within subroutines (also called "functions", though not in the sense of functional programming). 
"C (programming language)" from Wikipedia (https://en.wikipedia.org/wiki/C_(programming_language)). (Access date: 2022/9/10)

output1.txtの内容

c is an imperative, procedural language in the algol tradition. it has a static type system. in c, all executable code is contained within subroutines (also called "functions", though not in the sense of functional programming). 
"c (programming language)" from wikipedia (https://en.wikipedia.org/wiki/c_(programming_language)). (access date: 2022/9/10)

C IS AN IMPERATIVE, PROCEDURAL LANGUAGE IN THE ALGOL TRADITION. IT HAS A STATIC TYPE SYSTEM. IN C, ALL EXECUTABLE CODE IS CONTAINED WITHIN SUBROUTINES (ALSO CALLED "FUNCTIONS", THOUGH NOT IN THE SENSE OF FUNCTIONAL PROGRAMMING). 
"C (PROGRAMMING LANGUAGE)" FROM WIKIPEDIA (HTTPS://EN.WIKIPEDIA.ORG/WIKI/C_(PROGRAMMING_LANGUAGE)). (ACCESS DATE: 2022/9/10)

c IS AN IMPERATIVE, PROCEDURAL LANGUAGE IN THE algol TRADITION. iT HAS A STATIC TYPE SYSTEM. iN c, ALL EXECUTABLE CODE IS CONTAINED WITHIN SUBROUTINES (ALSO CALLED "FUNCTIONS", THOUGH NOT IN THE SENSE OF FUNCTIONAL PROGRAMMING). 
"c (PROGRAMMING LANGUAGE)" FROM wIKIPEDIA (HTTPS://EN.WIKIPEDIA.ORG/WIKI/c_(PROGRAMMING_LANGUAGE)). (aCCESS DATE: 2022/9/10)

output1-ans.txt が指示通りになっているかを確認するために、 output1-ans.txtと、 サンプルファイル output1.txt を diff コマンドを用いて比較するとよい。
diff コマンドは2つのテキストファイルを行単位で比較し、 相違点があればその行を表示する。完全に一致していれば何も表示しない。 （下記を参照のこと）

% diff output1-ans.txt output1.txt
%
（ファイルが完全に一致した場合はこのように何も表示しない）

% diff output1-ans.txt output1.txt
8c8
< "c (PROGRAMMING LANGUAGE)" FROM wIKIPEDIA (HTTPS://EN.WIKIPEDIA.ORG/WIKI/c_(PROGRAMMING_LANGUAGE)). (aCCESS DATE: 2022/9/10
---
> "c (PROGRAMMING LANGUAGE)" FROM wIKIPEDIA (HTTPS://EN.WIKIPEDIA.ORG/WIKI/c_(PROGRAMMING_LANGUAGE)). (aCCESS DATE: 2022/9/10)

output1.txtの最後の文字 “)” がoutput1-ans.txtにはない場合、
diffコマンド実行結果冒頭の 8c8 は不一致の箇所を行番号で示している。
（コマンド diff ファイル1 ファイル2 として mcn と出力された場合、
ファイル1のm行目の内容が、ファイル2のn行目の内容に変更され、
不一致になっている事を意味する。）
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 500
 
 
 int main() {
    char c;
    int cnt=0;
    int i;
    char str[MAX];
    FILE *fpin, *fpout;
 
    /*
     * 読み込み専用でファイル input1.txt を開く．
     * ファイルオープンに失敗した場合はエラーを表示して終了する．
     */
    if((fpin = fopen("input1.txt", "r")) == NULL){
        printf("Failed to open: input1.txt\n");
        exit(1);
    }
 
    /*
     * 書き込み専用でファイル output1-ans.txt  を開く．
     * ファイルオープンに失敗した場合はエラーを表示して終了する．
     * その際，上で開いた入力ファイルを忘れずに閉じる．
     */
    if((fpout = fopen("output1-ans.txt ", "w")) == NULL){
        printf("Failed to open: out.txt\n");
        fclose(fpin);
        exit(2);
    }
 
    /*
     * fpin を介して入力ファイルから，1文字ずつ読み込み，
     * そのまま fpout を介して出力ファイルに書き込む
     * 入力ファイルを最後まで読み込んだら，ループを抜ける．

    while(fscanf(fpin, "%c", &c) != EOF){
        fprintf(fpout, "%c", c);
    }
    */
 
    /*input1.txtを読み込み、文字配列に一文字ずつ格納する*/
    while(fscanf(fpin,"%c",&c) != EOF)
    {
        str[cnt] = c;
        cnt++;
    }
    
    /*大文字を小文字に変換し出力*/
    for( i=0 ; i<=cnt ; i++ )
    {
        if( 'A'<=str[i] && str[i]<='Z' )
        {
            fprintf(fpout, "%c", str[i]+'a'-'A');
        }
        else
        {
            fprintf(fpout, "%c", str[i]);
        }

    }
    fprintf(fpout,"\n");
    /*小文字を大文字に変換し出力*/
    for( i=0 ; i<=cnt ; i++ )
    {
        if( 'a'<=str[i] && str[i]<='z' )
        {
            fprintf(fpout, "%c", str[i]-('a'-'A'));
        }
        else
        {
            fprintf(fpout, "%c", str[i]);
        }

    }
    fprintf(fpout,"\n");
    
    /*大文字は小文字に、小文字は大文字に変換し出力*/
    for( i=0 ; i<=cnt ; i++ )
    {
        if( 'A'<=str[i] && str[i]<='Z' )
        {
            fprintf(fpout, "%c", str[i]+'a'-'A');
        }
        else if( 'a'<=str[i] && str[i]<='z' )
        {
            fprintf(fpout, "%c", str[i]-('a'-'A'));
        }
        else
        {
            fprintf(fpout, "%c", str[i]);
        }

    }
    /* 開いた入出力ファイルをそれぞれ忘れずに閉じる． */
    fclose(fpout);
    fclose(fpin);
 
    /* 正常終了を表す値0を返して終了する． */
    return 0;
 
}