#include<iostream>
#include<cmath>
/*这道题题意很简单，实际处理起来却很麻烦,是递推吗？可是递推没办法保存那么大的数组
后来想了一想，还是递推，但是要换一种思路*/
using namespace std;
typedef long long LL;
LL dp[15];
int main()
{
    dp[1]=1;
    for(int i=2;i<=9;i++)
    {
        dp[i]=pow(10,i-1)+10*dp[i-1];
    }
    for
    LL n;
    cin>>n;

    return 0;
}
