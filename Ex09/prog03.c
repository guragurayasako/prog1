#include<stdio.h>
#include<stdlib.h>
#include"stulist03.h"

int main()
{
  FILE *fp;
  Record data;
  int i,op,id;
  
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
    printf("Choose oparation (1:Insert, 0:Delete, ^D: Finish)-> ");
    if(scanf("%d",&op) == EOF)
    {
        printf("\n");
        break;
    }
    if(op == 1)
    {
        printf("Inset new data: (class ID name) ->");
        if(scanf("%s", data.class) == EOF) break;
        scanf("%d %s %s", &data.id, data.surname, data.givenname);

        if(insert(data) == NULL) printf("ID %d is already on the list!\n", data.id);
        listprint();
    }

    if(op == 0)
    {
        printf("Delete ID ->");
        scanf("%d", &id);
        if(delete(id) == NULL)
        {
            printf("ID %d is not found.\n", id);
        }
        listprint();
    }
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

NodePointer delete(int keydata)
{
    NodePointer n,delete_node;

    if((n = finditem(kaydata)) != NULL)
    {
        delete_node = n->next;

        free(delete_node);
        return n;
    }

    else return NULL;
}