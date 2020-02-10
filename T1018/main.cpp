#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 505;
const int INF = 0x7fffff;
/*这道题还是最短路的变形问题，除了要选择最短路，还要
1. 统计最短路上要派送的自行车的数目，以及要带回的自行车的数目
2. 统计路线
注意:我理解了一下题目，这道题的题意其实有一点不明白，它没有说清楚能不能用后面要带回的车补充前面
未满的停车点，我假设它整条线上的自行车派送和带回是分开的，例如一条最短路径上两个站的容量分别是是1,8
那就是派送4辆，返回3辆，而不是派送1辆
所以我认为这道题应该这么思考
1. 按照迪杰斯特拉算法求最短路
2. 最短路上派送和收回的自行车是不能递推的，因为最后一个增加的节点会影响最短路的选择，所以在求出最短路以后，
用深度优先搜索算法从顶点开始遍历，遍历到目标节点以后，如果距离等于最小距离，比较派送的自行车和回收的自行车
数目，选出最好的路径
*/
vector<int>p;    // 保存当前路径
vector<int>px;
int minbikeS=INF;    // 保存最少的派送数
int minbikeT=INF;    // 保存最少的回收数
int edge[maxn][maxn]; // 图
int cap[maxn];        // 容量
int vis[maxn];
int dist[maxn];
int c,n,e,m;
void DFS(int s,int D)   // 当前节点，距离
{
    vis[s] = 1;
    p.push_back(s);   // 保存该节点
    if(s==e)          //到达目的地
    {
        if(D==dist[e])         // 是一条最短路
        {
           // printf("找到最短路\n");
            //计算派送量和带回量
            int send=0,take=0;
            for(int i = 0;i<p.size();i++)
            {
                int temp = p[i];   // 当前节点
                if(temp)
                {
                    send+=(c/2-take-cap[temp])>0?c/2-take-cap[temp]:0;
                    take = take+cap[temp]-c/2>0?take+cap[temp]-c/2:0;
                   // printf("从当前节点带走:%d\n",take);
                }
            }
            //如果是最优路径
            if(send<minbikeS||(send==minbikeS&&minbikeT>take))
            {
                minbikeS = send;
                minbikeT = take;
                px.clear();
                for(int i=0;i<p.size();i++)
                {
                    px.push_back(p[i]);
                }
            }
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&edge[s][i])
        {
            DFS(i,D+edge[s][i]);
            p.pop_back();
            vis[i]=0;
        }
    }
}
void DFSTrave()      // DFS遍历
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&edge[0][i])     // 和起点相连
        {
            DFS(i,edge[0][i]);
            p.pop_back();
            vis[i]=0;
        }

    }
}
int main()
{
    scanf("%d %d %d %d",&c,&n,&e,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&cap[i]);
    int sp,ep,v;   //
    fill(dist+1,dist+n+1,INF);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&sp,&ep,&v);
        edge[sp][ep]=v;
        edge[ep][sp]=v;
        if(!sp)
            dist[ep]=v;
        if(!ep)
            dist[sp]=v;
    }
    int mindist,k;
    for(int i=0;i<n;i++)            //求最短路
    {
        mindist = INF;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&mindist>dist[j])
            {
                mindist = dist[j];
                k = j;
            }
        }
       // printf("%d\n",k);
        if(k==e)
            break;
        vis[k]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&edge[j][k]&&dist[j]>dist[k]+edge[j][k])
                dist[j] = dist[k]+edge[j][k];
        }
    }
   // for(int i=1;i<=n;i++)
     //   printf("%d\n",dist[i]);
    //printf("1\n");
    fill(vis,vis+n+1,0);      // 将vis数组填充为0，DFS时记录遍历个数
    DFSTrave();
    printf("%d 0",minbikeS);
    for(int i=0;i<px.size();i++)
    {
        printf("->");
        printf("%d",px[i]);
    }
    printf(" %d\n",minbikeT);
  //  printf("%d\n",dist[3]);
    return 0;
}
