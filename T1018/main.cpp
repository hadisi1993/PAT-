#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 505;
const int INF = 0x7fffff;
/*����⻹�����·�ı������⣬����Ҫѡ�����·����Ҫ
1. ͳ�����·��Ҫ���͵����г�����Ŀ���Լ�Ҫ���ص����г�����Ŀ
ע��:�������һ����Ŀ��������������ʵ��һ�㲻���ף���û��˵����ܲ����ú���Ҫ���صĳ�����ǰ��
δ����ͣ���㣬�Ҽ������������ϵ����г����ͺʹ����Ƿֿ��ģ�����һ�����·��������վ�������ֱ�����1,8
�Ǿ�������4��������3��������������1��
*/
vector<int>p[maxn];
int edge[maxn][maxn]; // ͼ
int minbikeS[maxn];    // ÿ���ڵ���СҪ�������г�������
int cap[maxn];        // ����
int vis[maxn];
int dist[maxn];

void addv(int i,int j)
{
    while(p[j].size()>0)
        p[j].pop_back();
    for(int k=0;k<p[i].size();k++)
        p[j].push_back(p[i][k]);
}
int main()
{
    int c,n,e,m;
    scanf("%d %d %d %d",&c,&n,&e,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&cap[i]);
    int sp,ep,v;   //
  //  fill(minbikeS,minbikeS+n,INF);
    fill(dist,dist+n,INF);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&sp,&ep,&v);
        edge[sp][ep]=v;
        edge[ep][sp]=v;
        if(!sp)
        {
            dist[ep]=v;
            minbikeS[ep]=cap[ep]-c/2>0?0:c/2-cap[ep];
            minbikeT[ep]=c/2-cap[ep]>0?0:cap[ep]-c/2;
        }
        if(!ep)
        {
            dist[sp]=v;
            minbikeS[sp]=cap[sp]-c/2>0?0:c/2-cap[sp];
            minbikeT[sp]=c/2-cap[sp]>0?0:cap[sp]-c/2;
        }

    }
    int mindist,k;
    for(int i=0;i<n;i++)
    {
       // printf("%d\n",i);
        mindist = INF;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&mindist>dist[j])
            {
                mindist = dist[j];
                k = j;
            }
        }
        printf("time %d: %d\n",i,k);
        p[k].push_back(k);
        if(k==e)
            break;
        vis[k]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j])
            {
                if(edge[j][k]&&dist[j]>dist[k]+edge[j][k])
                {
                    printf("����·��:��ӽڵ�%d\n",k);
                    dist[j] = dist[k]+edge[j][k];
                    minbikeS[j] = (minbikeS[k] - (cap[j]-c/2))>0?(minbikeS[k] - (cap[j]-c/2)):0;
                    minbikeT[j] = minbikeT[k]+cap[j]-c/2;
                    addv(k,j);       // ���·��
                }
                else if(edge[j][k]&&dist[j]==dist[k]+edge[j][k])
                {
                    printf("����·��:��ӽڵ�%d\n",k);
                    int temp = (minbikeS[k] - (cap[j]-c/2))>0?(minbikeS[k] - (cap[j]-c/2)):0;
                    if(temp<minbikeS[j]||(temp==minbikeS[j]&&minbikeT[k]+cap[j]-c/2<minbikeT[j]))
                    {
                        minbikeS[j] = temp;
                        minbikeT[j] = minbikeT[k]+cap[j]-c/2;
                        addv(k,j);
                    }
                }
            }
        }
    }
    printf("%d %d\n",minbikeT[1],minbikeT[2]);
    printf("%d 0",minbikeS[e]);
    for(int i=0;i<p[e].size();i++)
        printf("->%d",p[e][i]);
    printf(" %d",minbikeT[e]);
    return 0;
}
