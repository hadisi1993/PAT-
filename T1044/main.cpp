#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
/*������ó�ȡ����*/
/*�����Ƚ��鷳�ĵط���������Ҫ������С���*/
vector<pair<int,int> >P;   // ��vector��������¼��ʼλ��
typedef long long LL;
LL total=0;
int a[100005];    // ��Ʒ
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
    int p1=1,p2 = 1;   // ��ȡ������ʼ�ͽ���λ��
    LL sum = a[1];    // ��
    while(p2<=n&&p1<=n)
    {
        //printf("%lld %d %d\n",total,p1,p2);
        if(sum<total)
        {
            if(sum>=m)
            {
                P.clear();   // ���P�е�����Ԫ��
                total = sum;
                P.push_back(make_pair(p1,p2));   //��������Ԫ��
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
