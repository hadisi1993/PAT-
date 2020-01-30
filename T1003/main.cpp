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
const int Max =1e6;
int maxrescueman[600];   //各个城市的最多救援人数
int rescue[600];    //各个城市的救援人数
int Distance[600]; //最短路的距离
int path[600];     //救援路线的数目
int vis[600];     //是否被选择
int edge[600][600];  // 距离矩阵
int main()
{
    int n,m,c1,c2;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    path[c1]=1;       //到自己的点
    for(int i=0;i<n;i++)
    {
        scanf("%d",&rescue[i]);
    }
    maxrescueman[c1]=rescue[c1];
    for(int i=0;i<m;i++)
    {
        int s,e,v; //起始节点，终止节点和值
        scanf("%d %d %d",&s,&e,&v);
        if(s==c1)
        {
            Distance[e]=v;
            path[e]=1;
            maxrescueman[e]=maxrescueman[s]+rescue[e];
        }

        if(e==c1)
        {
            Distance[s]=v;
            path[s]=1;
            maxrescueman[s]=maxrescueman[e]+rescue[s];
        }
        edge[s][e] = v;
        edge[e][s] = v;
    }
    vis[c1]=1;   //自己所在节点被选择
    for(int i=0;i<n-1;i++)   // 进行n-1次选择
    {
        if(vis[c2])
            break;    //若c2已经被计算，则停止计算
        int k;        //k为待选择的节点
        int minDistance = Max;
        for(int j=0;j<n;j++)
        {
            if(!vis[j])    //遍历没有被选择的节点
            {
                if(Distance[j]!=0&&Distance[j]<minDistance)
                {
                    minDistance = Distance[j];
                    k = j;
                }
            }
        }
//        printf("第%d次选择:%d\n",i,k);
//        printf("更新后节点信息\n");
//        for(int j=0;j<n;j++)
//            printf("%d ",Distance[j]);
//        printf("\n");
        vis[k]=1;   //选择新节点
        if(k==c2)
            break;
        for(int j=0;j<n;j++)    //更新节点距离
        {
            if(!vis[j])
            {
                if(!Distance[j]&&edge[j][k]>0)                  //新的联通的节点
                {
                    Distance[j]=Distance[k]+edge[j][k];
                    path[j]=path[k];
                    maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
                else if(Distance[j]>0&&edge[j][k]&&edge[j][k]+Distance[k]<Distance[j])
                {
                    Distance[j]=edge[j][k]+Distance[k];            //发现新的路线
                    path[j]=path[k];
                    maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
                else if(Distance[j]>0&&edge[j][k]&&edge[j][k]+Distance[k]==Distance[j])
                {
                    path[j]+=path[k];                                     //其他新的路线被发现
                    if(maxrescueman[k]+rescue[j]>maxrescueman[j])
                        maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
            }
        }
    }
    printf("%d %d\n",path[c2],maxrescueman[c2]);
    return 0;
}
