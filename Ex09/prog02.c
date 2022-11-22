//2022.11.13
//B問題(50点)
//演習問題２（リストの拡張）
/*prog01.c を修正して、以下のような機能を追加したプログラムにせよ。
ファイルからのデータ読み取り機能
起動時に/home/course/prog1/public_html/2022/ex/ex09/Student.datからデータを読み取り、
リストに順次挿入する。ファイルの最後まで終わったら関数listprint() で一度リスト全体を表示する。
ファイルからのデータ入力と表示の終了後は、prog01.cと同じくキーボードからのデータとリストへの追加が行えるようにすること。
ID番号が重複していた場合の動作も元のまま残すこと。
ノード挿入位置の変更
関数 insert()を修正して、新しいノードをリストの先頭（head の次）ではなくリストの最後に挿入するようにする。
具体的には以下の通りである。
関数 insert() では、入力されたID番号が既にリスト中にあるか finditem 関数を使ってチェックし、
 有った場合は前と同様に挿入を行わず NULL を返す。無ければ、ノードを最後までたどってリストの最後に挿入し、
  挿入したノードへのポインタを返す。
ノード数のカウント
関数 listprint()を修正して、ノード内容の一覧表示の後にノードの数（Headは含まない）を表示するようにする。
なお、finditem関数には手を加えない。また外部変数も追加しないこととする。
prog01.c を prog02.c に、stulist01.h を stulist02.h にコピーしてから、prog02.cを適宜修正して作成する。
stulist02.h は元のstulist01.h が問題1で完成していればコピーしたものをそのまま用いてよく、変更する必要はない。

ヒント：ファイルからのデータ読み取り機能とノード挿入位置の変更の両者を一括して 解決しようとすると、
エラーがあった場合、どちらに問題があるのか切り分けが難しくなるので、一方の処理が完成してから、
もう一方の処理を加えるようにすると良い。
(提出ファイル名: prog02.c, stulist02.h)*/

#include<stdio.h>
#include<stdlib.h>
#include"stulist02.h"

int main()
{
  FILE *fp;
  Record data;
  int i;
  
  if((fp = fopen("Student.dat","r")) == NULL) exit(1);

  head = make_1node(data, NULL);

  while(fscanf(fp,"%s", data.class) != EOF)
  {
    fscanf(fp, "%d %s %s",&data.id, data.surname, data.givenname);
    insert(data);
  }
  listprint();
  while(1)
  {
    printf("Inset new data: (class ID name) ->");
    if(scanf("%s", data.class) == EOF)
    {
      printf("\n");
      break;
    }
    scanf("%d %s %s", &data.id, data.surname, data.givenname);

    if(insert(data) == NULL) printf("ID %d is already on the list!\n", data.id);
    listprint();
  }
  fclose(fp);
  return 0;
}

NodePointer insert(Record datas) //入力したデータをぶち込む
{
  NodePointer newnode, n;
  
  if (finditem(datas.id) == NULL)
  {
    for(n = head ; n->next != NULL ; n = n->next);
    newnode = make_1node(datas, n->next);
    n->next = newnode;
    return newnode;
  }
  else return NULL;
}

void listprint(void) //データ出力
{
  NodePointer n;
  int cnt=0;

  printf("Head -\n");
  for (n = head->next; n != NULL; n = n->next)
  {
    printf(" - %s %d %12s%-12s\n", n->data.class, n->data.id, n->data.surname, n->data.givenname);
    cnt++;
  }
  printf("%d nodes exist in the list.\n", cnt);
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

/*% 
./a.out
Head - 
   C1 1301001 AIZU         Taro        
   C2 1301022 BANDAI       Hanako      
   C4 1301033 TSURUGA      Shirou      
    .....（中略）
   C5 1301150 KITAKATA     Testuo      
   C5 1301164 SUKAGAWA     Yoshiko     
   C6 1301200 ASHINOMAKI   Masaru      
14 nodes exist in the list.

Insert new data: (class ID name) -> C1 1301001 AIZU Jiro
ID 1301001 is already on the list!
Head - 
   C1 1301001 AIZU         Taro        
   C2 1301022 BANDAI       Hanako      
   C4 1301033 TSURUGA      Shirou      
    .....（中略）
   C5 1301150 KITAKATA     Testuo      
   C5 1301164 SUKAGAWA     Yoshiko     
   C6 1301200 ASHINOMAKI   Masaru      
14 nodes exist in the list.

Insert new data: (class ID name) -> C3 1301100 IKKI Goro
Head - 
   C1 1301001 AIZU         Taro        
   C2 1301022 BANDAI       Hanako      
   C4 1301033 TSURUGA      Shirou      
    .....（中略）
   C5 1301150 KITAKATA     Testuo      
   C5 1301164 SUKAGAWA     Yoshiko     
   C6 1301200 ASHINOMAKI   Masaru      
   C3 1301100 IKKI         Goro        
15 nodes exist in the list.

Insert new data: (class ID name) -> Ctrl-D
%*/