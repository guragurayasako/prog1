// 2022.11.7
// A問題(50点)
//演習問題１（リストの実装練習）
/*プログラム /home/course/prog1/public_html/2022/ex/ex09/prog00.c、
ヘッダファイル /home/course/prog1/public_html/2022/ex/ex09/prog00.h は、
ハンドアウトLec09-19〜22 (p129-130) に出てきた、リストの基本操作を行うプログラムである。
これを各自prog00.c, prog00.h)として自分のディレクトリにコピーし、
 ハンドアウトLec09-23 (p130) 通りの動作を行う事を確認せよ。（これらのファイルは提出しない）

さて、ハンドアウトでは、リストのデータとして int型の構造体メンバ key を考えたが、 もう少し実用的なデータを扱うプログラムに変更する。
(提出ファイル名: prog01.c, stulist01.h)

手順は以下の通り：
prog00.h を stulist01.h という名前でコピーし、以下の変更を加える
node の宣言の前に次の宣言を追加する。これは学生のID番号、姓 (Surname)、名 (Given name)、クラスを格納するRecord型構造体の宣言である:
typedef struct {
  int id;
  char surname[12];
  char givenname[12];
  char class[3];
} Record;
node構造体の宣言を以下のように変更することで、 Record型の構造体変数 data をデータとするリストを扱えるようにする。
typedef struct node *NodePointer;
struct node {
  Record      data;
  NodePointer next;
};
必要に応じてヘッダ中の関数プロトタイプ宣言（戻り値、引数の型）を修正する（下記の関数説明参照）。

プログラム prog00.c を prog01.c という名前にコピーし、その各部を次のように修正する：
#include "prog00.h" を #include "stulist01.h"に書き換える
関数 insert() の引数は Record型とし、関数の中身もそれに応じて変更する。
これに伴い、関数 make_1node() の１つ目の引数もRecord型になる。
prog00.c と同様に、finditem() 関数を用いてデータのID番号が重複するノードがリスト中にあるか調べ、 重複している場合は挿入を行わず NULL を返す。
関数 finditem() は int型の引数をとり、構造体変数 data のメンバ id に同じ値があるかリストを検索する。
見つかった場合はその一つ手前のノードを指すポインタが戻り値となり、 見つからなかった場合は NULL を戻り値とする。
関数 listprint() は、構造体変数 data 内のデータを（クラス, ID番号, 姓, 名）の順で順次出力する。
書式は実行例を参考にすること（厳密に一致させる必要はない。書式指定については下の注記も参照のこと）。
main() ではループを用いたノードの自動生成をやめ、空のリスト（headのみ）を作成後に、 キーボードから入力されるデータ（クラス, ID番号, 姓, 名）に基づいて、関数 insert() を用いて順次新しいノードを リストに挿入する。関数 insert() が NULL を返した場合はメッセージを表示する。 その後毎回関数 listprint() でリスト全体を出力する。
キーボードから Ctrl-D が入力されたらプログラムを終了する。*/

#include <stdio.h>
#include <stdlib.h>
#include "stulist01.h"

int main()
{
  int i, num;
  Record newdatas;

  printf("[Initial]\n");

  head = make_1node(newdatas, NULL);
  listprint();
  
//情報入力ループ
  while (1)
  {
    printf("Insert new data: (class ID name) ->\n");
    if (scanf("%s%d%s%s", newdatas.class, &newdatas.id, newdatas.surname, newdatas.givenname) != 4)
      break;
    if (insert(newdatas) == NULL)
      printf("ID %d is already on the list\n", newdatas.id);
    listprint();
  }
  return 0;
}

NodePointer insert(Record datas) //入力したデータをぶち込む
{
  NodePointer newnode;
  
  if (finditem(datas.id) == NULL)
  {
    newnode = make_1node(datas, head->next);
    head->next = newnode;
    return newnode;
  }
  else
    return NULL;
}

void listprint(void) //データ出力
{
  NodePointer n;

  printf("Head -\n");
  for (n = head->next; n != NULL; n = n->next)
  {
    printf(" - %s %d %12s%-12s\n", n->data.class, n->data.id, n->data.surname, n->data.givenname);
  }
  printf("\n");
}

NodePointer finditem(int keydata) //学籍番号で検索
{
  NodePointer n;

  for (n = head; n->next != NULL; n = n->next)
  {
    if (n->next->data.id == keydata)
      return n;
  }
  return NULL;
}

NodePointer make_1node(Record datas, NodePointer p) //node作成
{
  NodePointer n;

  if ((n = (NodePointer)malloc(sizeof(struct node))) == NULL)
  {
    printf("Error in memory allocation\n");
    exit(8);
  }

  n->data = datas;
  n->next = p;
  return n;
}

/*実行例
% ./a.out
Head -

Insert new data: (class ID name) -> C1 1301001 AIZU Taro
Head -
   C1 1301001 AIZU         Taro

Insert new data: (class ID name) -> C2 1301022 BANDAI Hanako
Head -
   C2 1301022 BANDAI       Hanako
   C1 1301001 AIZU         Taro

Insert new data: (class ID name) -> C4 1301033 TSURUGA Shirou
Head -
   C4 1301033 TSURUGA      Shirou
   C2 1301022 BANDAI       Hanako
   C1 1301001 AIZU         Taro

Insert new data: (class ID name) -> C1 1301001 AIZU Jiro
ID 1301001 is already on the list!
Head -
   C4 1301033 TSURUGA      Shirou
   C2 1301022 BANDAI       Hanako
   C1 1301001 AIZU         Taro

Insert new data: (class ID name) -> Ctrl-D
% */

/*[文字列表示の書式指定について]
実行例の氏名表示の部分のように文字列の長さの上限が決まっていて、その範囲で表示すべき文字数に変化がある場合、
 %12s のように%sに対する桁数指定を行うと、指定分の桁数の表示幅が確保されて、その桁数内での右詰めの表示になる。
 また、%-12s のように桁数指定値に負号を付けると左詰めとなる（表示例ではこの方法を用いている）。
 printf関数の桁数に関する書式指定についてはハンドアウトp16のLec03-14で説明されている
 %dについての内容が%sに対しても適用できる。*/