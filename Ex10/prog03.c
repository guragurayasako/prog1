//2022.11.16
//B問題(50点)


#include<stdio.h>
#include<stdlib.h>
#include"stulist02.h"

int main()
{
  FILE *fp;
  Record data;
  int i;
  char *search_str;
  
  if((fp = fopen("Student.dat","r")) == NULL) exit(1);

  head = make_1node(data, NULL);

  while(fscanf(fp,"%s", data.class) != EOF)
  {
    fscanf(fp, "%d %s %s",&data.id, data.surname, data.givenname)
    insert(data);
  }
  listprint();
  while(1)
  {
    printf("Input match data (Class or ID) ->");
    if(scanf("%s", search_str) == EOF)
    {
      printf("\n");
      break;
    }
    else
    {
        listprint_sel( search_str );
    }
  }
  fclose(fp);
  return 0;
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


void listprint_sel(char str)
/*検索関数
 仕様：　数字の場合は文字数カウントしてその数まで比較してデータの中から一致するの探して全部出力
        クラスは比較してデータの中から一致するの探して全部出力
        構成はこんな感じです採点してくださいお願いします*/
{
    FILE *fp;
    Record data;
    int i=0;

    while(cnt[i] != '\0') i++;

    if( '0' <= str[0] && str[0] <= '9' )
    {
         while(fscanf(fp,"%s", data.class) != EOF)
        {
            fscanf(fp, "%s %s %s",&data.id, data.surname, data.givenname);
        }
    }

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