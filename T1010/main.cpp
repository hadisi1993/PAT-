#include<iostream>
#include<cmath>
#include<string.h>
#include<cctype>
using namespace std;
//这道题我一开始想的是通过求解方程组得解，但求解比较复杂，而且数学知识也不够，所以用遍历试一下
//大概试了一下，这道题可能出现的最大数用long long类型还是可以装下的，所以没必要开字符串用大数求解
//第一遍做下来只有十五分，将radix提高到100有19分，提高到1000分数不变
//如果基数超过35，就有超过用LL型表示的可能
typedef long long LL;
int main()
{
    LL t1=0,t2=0;
    char str1[10],str2[10];
    int tag,radix;
    scanf("%s %s %d %d",str1,str2,&tag,&radix);
    if(tag==1)    // 要转换的是第一个数
    {
        int len = strlen(str1);
        for(int i=0;i<len;i++)
        {
            t1 =t1*radix+(isdigit(str1[i])?str1[i]-'0':(str1[i]-'a'+10));   //计算t2
        }
       //printf("t1:%lld\n",t1);
        int len2 = strlen(str2);
        for(int i=2;i<=100;i++)
        {
            t2 = 0;
            for(int j=0;j<len2;j++)
            {
                t2 =t2*i+(isdigit(str2[j])?str2[j]-'0':(str2[j]-'a'+10));   //计算t2
              //  printf("%d\n",t2);
                if(t2>t1)
                    break;
            }
            //printf("t2:%lld\n",t2);
            if(t2==t1)
            {
                printf("%d\n",i);
                return 0;
            }

        }
    }
    else
    {
        int len = strlen(str2);
        for(int i=0;i<len;i++)
        {
            t2 =t2*radix+(isdigit(str2[i])?str2[i]-'0':(str2[i]-'a'+10));   //计算t2
        }
      //  printf("t1:%lld\n",t2);
        int len2 = strlen(str1);
        for(int i=2;i<=100;i++)
        {
            t1 = 0;
            for(int j=0;j<len2;j++)
            {
                t1 =t1*i+(isdigit(str1[j])?str1[j]-'0':(str1[j]-'a'+10));   //计算t2
                if(t1>t2)
                    break;
            }
            if(t2==t1)
            {
                printf("%d\n",i);
                return 0;
            }
        }

    }
    printf("Impossible\n");
    return 0;
}
