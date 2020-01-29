#include<iostream>
#include<string.h>
using namespace std;
int num[20];
int digit[10];
int main()
{
    char str[20]="";
    scanf("%s",str);     //输入字符串
    int len = strlen(str);
    for(int i=0;i<len;i++)
    {
        digit[str[i]-'0']+=1;   //统计字符的数目
    }
    int ram=0;       //余项
    for(int i=len-1;i>=0;i--)
    {
        num[i]=(2*(str[i]-'0')+ram)%10;
        ram = (2*(str[i]-'0')+ram)/10;
    }
    if(ram)
    {
        printf("No\n%d",ram);
    }

    else
    {
         for(int i=0;i<len;i++)
        {
            digit[num[i]]-=1;   //统计字符的数目
        }
        int flag=1;
        for(int i=0;i<10;i++)
            if(digit[i]!=0) flag=0;
        flag?printf("Yes\n"):printf("No\n");
    }
    for(int i=0;i<=len-1;i++)
        printf("%d",num[i]);
    return 0;
}
