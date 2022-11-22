#include<stdio.h>

int main()
{
    typedef struct{
    int x;
    int y;
  }XY;
  typedef struct{
    char name[12];
    XY vertex[3];
  }Triangle;

  Triangle triangle[10], *p;
  printf("(1)%ld\n(2)%ld\n(3)%ld\n(4)%ld\n", sizeof(XY), sizeof(Triangle), sizeof(triangle),  sizeof(triangle[0]));
  ++p;
  printf("%p\n", &p);
    return 0;
}