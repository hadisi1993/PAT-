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
int main()
{
    int n,value;
    int SS=0;  //子序列之和
    scanf("%d",&n);
    int s,e,S,E; //子序列的第一个数和最后一个数,最大子序列的第一个数和最后一个数
    int flag = 0;
    int first;  //第一个数
    for(int i=0;i<n;i++)
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
    return 0;
}
