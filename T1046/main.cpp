#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a[100005];
int main()
{
    int n,m,s,e,v;
    LL sum =0;
    scanf("%d",&n);
    for(int i=2;i<=n+1;i++)
    {
        scanf("%d",&v);
        sum+=v;
        a[i]=a[i-1]+v;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&s,&e);
        if(s>e) swap(s,e);
        printf("%lld\n",min(a[e]-a[s],sum-(a[e]-a[s])));
    }
    return 0;
}
