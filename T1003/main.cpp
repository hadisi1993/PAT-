/*这道题是一个最短路问题，大致思路就是用Dijkstra算法解决
在计算最短路的时候，要同时计算最短路的数目和能收集的最多人手
在计算时采用这样的策略
1. 更新最短路时，如果发现新的最短路，则最短路条数重新记为1
2. 如果最短路距离和当前最短路距离相同，最短路条数加1，并且比较能收集的最多的救援人数和这条路上能收集的
救援人数

3. 这道题前面一直做错的一个很重要的原因是，没有考虑到，更新路径时，新增加的路径数目不是1条，而是
前面一个节点的路径数。还有一个坑就是，要考虑出发节点就是到达节点的情况。
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int INF =1e6;
int maxrescueman[600];   //各个城市的最多救援人数
int rescue[600];    //各个城市的救援人数
int Distance[600]; //最短路的距离
int path[600];     //救援路线的数目
int vis[600];     //是否被选择
int edge[600][600];  // 距离矩阵
int n,m,s,e,S,E;
int main()
{
    scanf("%d %d %d %d",&n,&m,&S,&E);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&rescue[i]);
    }
    fill(Distance,Distance+n,INF);
    Distance[S]=0;
    path[S]=1;       //到自己的点
    maxrescueman[S]=rescue[S];
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&s,&e);
        scanf("%d",&edge[s][e]);
        edge[e][s] = edge[s][e];            //对称矩阵
    }
    for(int i=0;i<n;i++)   // 连起点进行n次循环,这样起点就不用做特殊处理了
    {
        int k=-1,minDistance = INF;        //k为待选择的节点，并设置最短距离;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&Distance[j]<minDistance)
            {
                minDistance = Distance[j];
                k = j;
            }
        }
       // printf("%d",k);
        if(k==-1) break;  // 没有新的联通节点了
        vis[k]=1;   //选择新节点
        for(int j=0;j<n;j++)    //更新节点距离
        {
            if(!vis[j]&&edge[j][k])
            {
                if(edge[j][k]+Distance[k]<Distance[j])
                {
                    Distance[j]=edge[j][k]+Distance[k];            //发现新的路线
                    path[j]=path[k];
                    maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
                else if(edge[j][k]+Distance[k]==Distance[j])
                {
                    path[j]+=path[k];                                     //其他新的路线被发现
                    if(maxrescueman[k]+rescue[j]>maxrescueman[j])
                        maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
            }
        }
    }
    printf("%d %d\n",path[E],maxrescueman[E]);
    return 0;
}
