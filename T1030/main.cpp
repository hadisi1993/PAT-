#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=550;
const int INF = 0x777ffff;
/*这道题是最短路算法的变形，我认为的难点在于记录最短路的，我认为的难点在于更新最短路径，尝试用不定长
数组解决
思路:在输入以后，比较最短路径后，将上一个节点的最短路径和本节点连接起来存储*/
int edge[maxn][maxn];
int cost[maxn][maxn];  // 每个城市的最小费用
int sumcost[maxn];  // 到达每个城市的最小费用
int dist[maxn];  // 到达节点的最短距离
int vis[maxn];   // 节点是否被选入
int mindist = INF;
vector<int>p[maxn];
void add(int x,int y)
{
    for(int i=0;i<p[y].size();i++)
    {
        p[x].push_back(p[y][i]);
    }
}
void clc(int x)   // 清空节点
{
    while(!p[x].empty())
        p[x].pop_back();
}
int main()
{
    int n,m,d,c,s,e,c1,c2;
    scanf("%d %d %d %d",&n,&m,&s,&e);
    p[s].push_back(s);
    fill(dist,dist+n,INF);      //初始化城市间具体为无限
    fill(sumcost,sumcost+n,INF); // 初始化总费用为无限
    dist[s]=0;   //自己的距离为0
    sumcost[s] = 0; // 总费用也是0
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&c1,&c2,&d,&c);
        edge[c1][c2]= d;
        edge[c2][c1]= d;
        cost[c1][c2]= c;
        cost[c2][c1]= c;
    }
    for(int i=0;i<n;i++)   //要进行n次遍历
    {
        mindist=INF;
        int k;
        for(int j=0;j<n;j++)   // 遍历节点
        {
            if(!vis[j])
            {
                if(dist[j]<mindist)
                {
                    mindist=dist[j];
                    k = j;             //选出距离最近的节点
                }
            }

        }
        if(k==e)
            break;
        vis[k]=1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j])             // 更新距离
            {
                if(edge[j][k]&&dist[k]+edge[j][k]<dist[j])
                {
                    sumcost[j] = sumcost[k]+cost[j][k];
                    dist[j] = dist[k]+edge[j][k];
                    clc(j);
                    add(j,k);
                    p[j].push_back(j);
                }
                if(edge[j][k]&&dist[k]+edge[j][k]==dist[j]&&sumcost[k]+cost[j][k]<sumcost[j])
                {
                    sumcost[j] = sumcost[k]+cost[j][k];  // 更新总费用
                    clc(j);
                    add(j,k);
                    p[j].push_back(j);
                }
            }
        }
    }
    for(int i=0;i<p[e].size();i++)
    {
        if(i) printf(" ");
        printf("%d",p[e][i]);
    }
    printf(" %d %d\n",dist[e],sumcost[e]);
    return 0;
}
