#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
/*这道题应该是一道贪心题，要获得最大的利益，我们总是想让价值大的商品返回尽量多的次数
有这样一些规定
1.正的优惠券，应该用在价值为正的商品且价值越大的商品上
2.负的优惠券，应该用在价值为负且且价值小的商品上
3.优惠券和商品不同号则不用
计算策略
1.先计算两者全为负的
2.再计算两者全为正的*/
int main()
{
    LL nc,np,sum=0;
    LL c[100005],p[100005];
    scanf("%lld",&nc);
    for(int i=0;i<nc;i++)
        scanf("%lld",&c[i]);
    scanf("%lld",&np);
    for(int i=0;i<np;i++)
        scanf("%lld",&p[i]);
    sort(c,c+nc);
    sort(p,p+np);
    int p1 = 0;
    while(p[p1]*c[p1]>0&&p[p1]<0)
    {
        sum+=p[p1]*c[p1];
        p1++;
    }
   // printf("%d\n",p1);
    //printf("%lld\n",sum);
    int p21=nc-1,p22= np-1;
    while(p21>=p1&&p22>=p1&&c[p21]*p[p22]>0)
    {
        sum+=c[p21]*p[p22];
        p21--,p22--;
    }
    printf("%lld\n",sum);
    return 0;
}

