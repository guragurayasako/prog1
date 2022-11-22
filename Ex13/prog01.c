//2022.11.21
//A問題(50点)
//演習問題１（２次元配列の動的確保と文字列）
/**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GYO 5
#define M 100

int main()
{
  char str[M]; //一旦文字列入れるやつ
  char *arr[5]; //文字配列の配列
  int i, j;
  int len[5];

  //入力
  for( i=1 ; i<=5 ; i++ )
  {
    printf("Input word #%d : ",i);
    scanf("%s",str);
    len[i-1] = strlen(str);
    arr[i-1] = (char *)malloc((len[i-1]+1) * sizeof(int)); //ピッタリ文字配列を作成
    strcpy(arr[i-1], str);
  }

  //出力
  for( i=1 ; i<=5 ; i++ )
  {
    printf("Word #%d (Length: %d): %s\n", i, len[i-1], arr[i-1]);
    free(arr[i-1]);
  }


  return 0;
}

/*実行例：
% ./a.out
Input word #1: to
Input word #2: Advance
Input word #3: Knowledge
Input word #4: for
Input word #5: Humanity
Word #1 (Length: 2): to
Word #2 (Length: 7): Advance
Word #3 (Length: 9): Knowledge
Word #4 (Length: 3): for
Word #5 (Length: 8): Humanity
%
*/