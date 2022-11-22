/*****************************************************************
  アスキーコードを表示する
   ex01/prog01a.c
   Last update: Sep 25 2019
*****************************************************************/
#include <stdio.h>

int main()
{
  char c;

  /* １文字入力 */
  printf("Input a character: ");
  scanf("%c", &c);

  /* 出力 */
    printf("ASCII code of '%c' is %d(0x%x).\n", c, c, c);

  return 0;
}

/*反省
　int型で宣言するとscanfで%lcじゃないとダメなのに、
  char型で宣言すると%cでいいのなんなん*/