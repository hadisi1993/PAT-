#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 505;
const int INF = 0x7fffff;
/*这道题还是最短路的变形问题，除了要选择最短路，还要
1. 统计最短路上要派送的自行车的数目，以及要带回的自行车的数目
注意:我理解了一下题目，这道题的题意其实有一点不明白，它没有说清楚能不能用后面要带回的车补充前面
未满的停车点，我假设它整条线上的自行车派送和带回是分开的，例如一条最短路径上两个站的容量分别是是1,8
那就是派送4辆，返回3辆，而不是派送1辆
*/
vector<int>p[maxn];
int edge[maxn][maxn]; // 图
int minbikeS[maxn];    // 每个节点最小要派送自行车的数量
int cap[maxn];        // 容量
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
                    printf("更新路径:添加节点%d\n",k);
                    dist[j] = dist[k]+edge[j][k];
                    minbikeS[j] = (minbikeS[k] - (cap[j]-c/2))>0?(minbikeS[k] - (cap[j]-c/2)):0;
                    minbikeT[j] = minbikeT[k]+cap[j]-c/2;
                    addv(k,j);       // 添加路径
                }
                else if(edge[j][k]&&dist[j]==dist[k]+edge[j][k])
                {
                    printf("更新路径:添加节点%d\n",k);
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
