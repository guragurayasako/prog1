/*演習問題3

以下のプログラムは、ファイル in.txt を開き、 
すべての文字を一旦バッファにためた後に out.txt に書き出すものである。

このプログラムでは、入出力のファイル名 in.txt と out.txt をそれぞれ文字配列 in_filename[] と out_filename[] に格納している。

第3回での講義範囲内では、文字配列の各要素を一つづつ指定することで初期化を行なっているが、 
実際にはプログラム中のコメントにある通り、 次回の講義で紹介するLec04-13,14,15で示すように、
文字の並び（文字列）で一度に初期化することができる。 
このプログラムではこの方法を先取りする形で用いている。

このプログラムを修正し、ファイル input1.txt から読み込んだ文字列を逆順にして output3-ans.txt に書き出すようにせよ。
(提出ファイル名: prog03a.c)
解答例 (output3.txt) と自分の作成した出力結果 (output3-ans.txt) をプログラム中で開き、 
先頭から 1 文字ずつ比較して、2つのファイルの内容が一致するかどうかを調べて結果を表示するプログラムを作成せよ。 
一致していない場合、先頭から何文字目で違っているかを出力すること（詳細は下記の実行例を参照）。
(提出ファイル名: prog03b.c)*/

/*output3.txt の内容

)01/9/2202 :etad sseccA( .))egaugnal_gnimmargorp(_C/ikiw/gro.aidepikiw.ne//:sptth( aidepikiW morf ")egaugnal gnimmargorp( C"
 .)gnimmargorp lanoitcnuf fo esnes eht ni ton hguoht ,"snoitcnuf" dellac osla( senituorbus nihtiw deniatnoc si edoc elbatucexe lla ,C nI .metsys epyt citats a sah tI .noitidart LOGLA eht ni egaugnal larudecorp ,evitarepmi na si C
prog03b.cでの実行例（prog03a.cが正しく動作している場合）

% ./a.out 
Two files are identical.
（output3.txtとoutput3-ans.txtが一致した場合）
prog03a.cが正しく動作していると、ファイル不一致の場合の動作確認ができないので、
あえて不一致がわかっているファイル（例えば、output3.txtとinput1.txt)との比較も試すこと。
output3.txtとinput1.txtとの比較を行う場合、1文字目から違うため、以下の結果となる。

% ./a.out
Two files are different at 1 byte.
（ファイル不一致の場合は、どこで相違が見つかったのかを表示する。
output3.txtとinput1.txtとの比較では、
1バイト目（1文字=1バイトなので、1文字目に相当）で相違が見つかった。）*/

#include <stdio.h>
#include <stdlib.h>
 
/* 文字列バッファのサイズ */
#define MAX 1000
 
int main(){
	char in_filename[] = "in.txt";
	char out_filename[] = "out.txt";
	FILE *fpin, *fpout;
	
	char buf[MAX]; /* 文字列バッファ */
	int c;         /* ファイルからの1文字取得用バッファ */
	int n;         /* 読み込んだ文字数 */
	int i;
	
	/* 入力ファイルを開く */
	if((fpin = fopen(in_filename, "r")) == NULL){
		printf("Failed to open: %s\n", in_filename);
		exit(1);
	}
	
	/* 出力ファイルを開く */
	if((fpout = fopen(output3-ans.txt, "w")) == NULL){
		printf("Failed to open: %s\n", output3-ans.txt);
		fclose(fpin);
		exit(2);
	}
	
	/* バッファの最大数までデータを読み込む */
	for(n = 0; n < MAX; n++){
		if((c = fgetc(fpin)) == EOF)
			break;
		buf[n] = (char)c; /* char へのキャストを忘れない */
	}
	
	/* 
	 * バッファが最大数まで到達してもなおEOFにならない場合，
	 * バッファあふれとしてエラー処理する．
	 */
	if(n == MAX){
		printf("Buffer overflow !\n");
		exit(3);
	}
	 
	/* バッファの内容を出力する */
	for(i = n; i >= 0 ; i--){
		fputc(buf[i], fpout);
	}
	
	/* 開いた入出力ファイルをそれぞれ忘れずに閉じる */
	fclose(fpout);
	fclose(fpin);
		
	return 0;
}

