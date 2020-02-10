#include<iostream>
#include<algorithm>
#include<vector>
//现在我们已经学会了DFS和树的静态表示，可以用这种新的写法来做这道题
using namespace std;
const int maxn = 105;
vector<int>p[maxn];
int vis[maxn];
int maxlevel=-1;   // 最大层次数
void DFS(int father,int level)
{
    if(p[father].size()==0)
    {
        vis[level]++;
        maxlevel = max(maxlevel,level);
        return ;
    }
    for(int i = 0;i<p[father].size();i++)
        DFS(p[father][i],level+1);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int id,childnum,child;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&id);
        scanf("%d",&childnum);
        for(int i=0;i<childnum;i++)
        {
            scanf("%d",&child);
            p[id].push_back(child);
        }
    }
    DFS(1,0);
    for(int i=0;i<=maxlevel;i++)
    {
        if(i) printf(" ");
        printf("%d",vis[i]);
    }
    return 0;
}
