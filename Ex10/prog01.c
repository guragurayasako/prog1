#include <stdio.h>
#include <stdlib.h>

int myatoi(char *);
int main() {
    char str2[][20]={ "  2022",
                    " -60.50",
                    "+32m",
                    " 999,654",
                    "+-24",
                    "x86",
                    "2022/11/30",
                    ""};
  int ival, i;

  for ( i=0; str2[i][0]!='\0'; i++ ){
    ival = myatoi( str2[i] );
    printf("string:%s\n", str2[i]);
    printf("value:%d\n", ival);
  }
    return 0;
}

int myatoi(char *str)
{
    int minus=1;
    int value;
    int i=0,j=0;//カウンタ
    //スペース読み込み
    while(str[i] == ' ')
    {
        i++;
    }

    //符号読み込み
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
        {
        minus = -1;
        i++;
        }
        else i++;
    }

    //符号が続いたら0返す
    if(str[i] == '-' || str[i] == '+')
    {
        return 0;
    }

    //数字を値に変換
    if( !('0'<= str[i] && str[i]<='9') )
    {

        return 0;
    }

    else
    {
        while('0'<= str[i] && str[i]<='9')
        {

            if(j==0)
            {
            value = (int)(str[i] - '0');
            i++;
            j++;
            }
            else
            {
                value = 10*value + (int)(str[i] - '0');
                i++;
            }
            if(str[i] == '\0')
                return value*minus;
        }
        return value*minus;
    }
}

/*実行例：
% ./a.out
String:  2022
Value:2022
String: -60.50
Value:-60
String:+32m
Value:32
String: 999,654
Value:999
String:+-24
Value:0
String:x86
Value:0
String:2022/11/30
Value:2022
%*/