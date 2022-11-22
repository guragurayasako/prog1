/* struct declaration */
typedef struct {
  int id;
  char surname[12];
  char givenname[12];
  char class[3];
} Record;

typedef struct node *NodePointer;

struct node {
  Record      data;
  NodePointer next; //次のnodeのアドレス
};


/* prototype declaration */
NodePointer insert(Record);
NodePointer finditem(int);
void listprint(void);
NodePointer make_1node(Record, NodePointer);
                   
/* Global Variable head */
NodePointer head;
