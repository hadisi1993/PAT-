#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1005;
/*这道题我的想法就是用一个数组来保存图,然后计算每个节点的出度，看哪些节点的出度为1且只和被占领的节点相连
之后证明这个想法是完全错误的，参考网上的解法，这道题应该要用到DFS遍历联通图中所有的联通分量，联通分量和要
修的路之间是n与n-1的关系
*/
int edge[maxn][maxn];
int vis[maxn];
int cnt=0;
int n,m,k;
int ocp=0;
void DFS(int u)
{
    vis[u] = 1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&i!=ocp&&edge[u][i])
            DFS(i);
    }
}
void DFSTrave()
{
   // cout<<ocp<<endl;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&i!=ocp)
        {
           // cout<<"访问第"<<i<<"个节点"<<endl;
            cnt++;
            DFS(i);
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    int s,e;
    for(int i=0;i<m;i++)          //建图
    {
        scanf("%d %d",&s,&e);
        edge[s][e]=1;
        edge[e][s]=1;
    }
    for(int i=0;i<k;i++)
    {
        fill(vis+1,vis+n+1,0);
        cnt = 0;
        scanf("%d",&ocp);
        DFSTrave();
        printf("%d\n",cnt-1);
    }
    return 0;
}
