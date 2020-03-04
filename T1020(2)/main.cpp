#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
/*这道题第一次做的时候犯了和1013一样的错误，都是想用出入度的方法去解决这个问题。还是想的太简单了，
第二次尝试用DFS去做，思路是这样的
1.这道题节点数比较大，要用邻接表来储存图
2.首先要求联通分量，如果联通分量大于1，表示节点有错误
3.在DFS过程中要记录最深的层
这样做的过程中出现了问题，因为要求最深的根，所以对所有的节点都要进行遍历，且不保存vis
所以求联通分量和记录节点要分开求两边，结果就是超时
*/
const int maxn=1e4+5;
int vis[maxn];
int cnt;   // 连通块的数量
int dept;  // 最深的根
vector<int>P[maxn];
vector<int>node;   // 最深的节点
int n,u,v;
int flag;       //判断是否超出了当前深的根
void DFS(int x)
{
    vis[x]=1;
    for(int i=0;i<P[x].size();i++)
    {
        int tmp = P[x][i];
        if(!vis[tmp])
        {
            DFS(tmp);
        }
    }
}
void DFSTrave()     // 第一次遍历，遍历联通分量的个数
{
    for(int i=1;i<=n;i++)      // 对每个节点都进行遍历
    {
        if(!vis[i])
        {
            cnt++;
            DFS(i);
        }

    }
}
void DFS2(int x,int level)
{
    if(level>dept)
    {
        dept = level;
        node.clear();
        flag = 1;
    }
    else if(level == dept)
    {
        flag = 1;
    }
    vis[x]=1;
    for(int i=0;i<P[x].size();i++)
    {
        int tmp = P[x][i];
        if(!vis[tmp])
        {
            DFS2(tmp,level+1);
        }
    }
}
void DFSTrave2()    // 第二次遍历，查找最长的根
{
    for(int i=1;i<=n;i++)      // 对每个节点都进行遍历
    {
        flag =0;
        fill(vis+1,vis+n+1,0);
        DFS2(i,1);
        if(flag)
            node.push_back(i);
    }
}
int main()
{
    scanf("%d",&n);
    for(int j=0;j<n-1;j++)
    {
        scanf("%d %d",&u,&v);
        P[u].push_back(v);
        P[v].push_back(u);
    }
    DFSTrave();
    if(cnt>1)        // 有多个联通分量
    {
        printf("Error: %d components\n",cnt);
        return 0;
    }
    DFSTrave2();
    //printf("%d\n",node.size());
    for(int i=0;i<node.size();i++)
        printf("%d\n",node[i]);
    return 0;
}
