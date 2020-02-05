#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1005;
/*������ҵ��뷨������һ������������ͼ,Ȼ�����ÿ���ڵ�ĳ��ȣ�����Щ�ڵ�ĳ���Ϊ1��ֻ�ͱ�ռ��Ľڵ�����
֮��֤������뷨����ȫ����ģ��ο����ϵĽⷨ�������Ӧ��Ҫ�õ�DFS������ͨͼ�����е���ͨ��������ͨ������Ҫ
�޵�·֮����n��n-1�Ĺ�ϵ
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
           // cout<<"���ʵ�"<<i<<"���ڵ�"<<endl;
            cnt++;
            DFS(i);
        }
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    int s,e;
    for(int i=0;i<m;i++)          //��ͼ
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
