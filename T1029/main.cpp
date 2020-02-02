#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 5*1e5+5;
int a[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=n;i<n+m;i++)
        scanf("%d",&a[i]);
    sort(a,a+m+n,cmp);
    int median = (n+m+1)/2-1;
    cout<<a[median]<<endl;
    return 0;
}
