#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
/*这道题用尺取法做*/
/*这道题比较麻烦的地方在于它还要输入最小金额*/
vector<pair<int,int> >P;   // 用vector数组来记录起始位置
typedef long long LL;
LL total=0;
int a[100005];    // 商品
int main()
{
    int n;
    LL m;
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        total +=a[i];
    }
    int p1=1,p2 = 1;   // 尺取法，开始和结束位置
    LL sum = a[1];    // 和
    while(p2<=n&&p1<=n)
    {
        //printf("%lld %d %d\n",total,p1,p2);
        if(sum<total)
        {
            if(sum>=m)
            {
                P.clear();   // 清除P中的所有元素
                total = sum;
                P.push_back(make_pair(p1,p2));   //插入这组元素
                if(p1==p2)
                {
                    p1++;
                    p2++;
                    sum = a[p1];
                }
                else
                {
                    sum-=a[p1];
                    p1++;
                }
            }
            else
            {
                p2++;
                sum+=a[p2];
            }
        }
        else if(sum==total)
        {
            P.push_back(make_pair(p1,p2));
            if(p1==p2)
            {
                p1++;
                p2++;
                sum = a[p1];
            }
            else
            {
                sum-=a[p1];
                p1++;
            }
        }
        else
        {
            sum-=a[p1];
            p1++;
        }
    }
    for(int i=0;i<P.size();i++)
    {
        printf("%d-%d\n",P[i].first,P[i].second);
    }
    return 0;
}
