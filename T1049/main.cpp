#include<iostream>
#include<cmath>
/*这道题题意很简单，实际处理起来却很麻烦,是递推吗？可是递推没办法保存那么大的数组
后来想了一想，还是递推，但是要换一种思路;
后来我尝试过DP，但我根本想不出动态规划方程应该怎么写,然后上网看了一下，发现这就是一道
找规律题，不需要递推动态规划:
思路:按位数处理,每一位都需要计算
计算过程中需要用到三个数:1. 当前位之前的数 2.当前位 3. 当前位之后的数*/
using namespace std;
typedef long long LL;
int main()
{
    LL n;
    cin>>n;
    LL res = 0;
    LL r = 10,l=0;
    while(n>=r/10)
    {
        int ram = (n/(r/10))%10;   // 当前位
        res+=(n/r)*(r/10);   // (n/r代表当前位左边的数)
        if(ram==1)
            res+=l+1;
        else if(ram>1)
            res+=r/10;
        l=ram*(r/10)+l;   // 更新当前位右边的数
        r*=10;
    }
    printf("%lld\n",res);
    return 0;
}
