#include <iostream>
#include<string.h>
/*这道题比较简单，稍微套一下数学公式就出来了*/
using namespace std;
int main()
{
    char str[80];
    scanf("%s",str);
    int len = strlen(str);
    int p1 = 0,p2 = len-1,j;
    for(j=3;j<=len;j++)
    {
        if((len+2-j)%2==0&&j>=(len+2-j)/2)   //找最小的满足条件的底长
            break;
    }
    int p = (len+2-j)/2;    //两条边的长度
    for(int i=0;i<p-1;i++)
    {
        printf("%c",str[p1]);
        for(int k=0;k<j-2;k++)
            printf(" ");
        printf("%c\n",str[p2]);
        p1++,p2--;
    }
    for(int k=p1;k<=p2;k++)
        printf("%c",str[k]);
    return 0;
}
