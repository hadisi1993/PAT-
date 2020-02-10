/*经典算法，求序列的最大子序列之和
算法的思想是这样的：
最大子序列一定是从一个正数开始的，所以我们在计算的过程中只计算一个子序列之和，如果子序列之和为正，就将子序列和当前数相加，
否则舍弃当前子序列和，以当前数为新子序列的第一个元素
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int INF = -9999999;
int MSS=INF;    //最大子序列之和
int a[10005];
int main()
{
    int n;
    int SS=0;  //子序列之和
    scanf("%d",&n);
    int flag = 0,P1,P2;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=0)flag = 1;
    }
    if(!flag)
        printf("0 %d %d",a[0],a[n-1]);  //如果全是负数就按要求输出
    else
    {
        int p1,p2;   // 两个指针，指向最大子序列第一个和最后一个元素
        for(int i=0;i<n;i++)
        {
            p2 = i;
            if(SS<=0)
            {
                p1 = i;
                SS = a[i];
            }
            else
                SS+=a[i];
            if(SS>MSS)
            {
                MSS = SS;
                P1 = p1;
                P2 = p2;
            }
        }
    printf("%d %d %d",MSS,a[P1],a[P2]);
    return 0;
    }
}

    /*for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(!i)
            first=value;
        if(value>=0)
            flag=1;
        if(SS<=0)
        {
            s = value,e=value;
            SS = value;
        }
        else
        {
            e = value;
            SS = SS+value;
        }
        if(SS>MSS)
        {
            MSS = SS;
            S = s,E = e;
        }
    }
    if(!flag)
        printf("0 %d %d\n",first,value);
    else
        printf("%d %d %d\n",MSS,S,E);
    return 0;*/

