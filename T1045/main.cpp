#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
/*这道题的题意也比较简单，就是叫我们在原序列中选择一个最长的满足条件的子序列，然后输出它的长度
这道题感觉应该是动态规划题
数组:dp[i][j]: i代表当前序列的长度，j代表第几个最喜欢的数
*/
int dp[10005][205];
map<int,int>s;
int main()
{
    int nc,n,m,v;
    scanf("%d",&nc);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v);
        s[v]=i;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&v);
        int maxn = 0;
        for(int j=1;j<=n;j++)
            dp[i][j]=dp[i-1][j];
        for(int j=1;j<=s[v];j++)
            maxn = max(maxn,dp[i-1][j]);
        if(s[v])
            dp[i][s[v]]=maxn+1;
    }
    int maxn =0;
    for(int i=1;i<=n;i++)
        maxn = max(maxn,dp[m][i]);
    printf("%d\n",maxn);
    return 0;
}
