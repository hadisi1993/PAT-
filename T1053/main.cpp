#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
/*这道题是一道比较简单的关于树的DFS题,有这么几个要点
1. 计算的从root到leaf的权重之和
2. 用vector模拟树,因为节点比较少
3. 每个vector要根据权重排序
4. 用一个vector数组保存当前路径
*/
int w[105];
vector<int>v[105];  // 树
vector<int>q;    // 保存的路径
LL sum;        // 权重之和
bool cmp(int a,int b)   // 比较函数
{
    return w[a]>w[b];
}
void DFS(int node, int s)  // node:当前节点  s:权重之和
{
    if(v[node].size()==0)
    {
        if(s==sum)   // 相等，打印
        {
            for(int i=0;i<q.size();i++)
            {
                i==0?printf("%d",q[i]):printf(" %d",q[i]);
            }
            printf("\n");
        }
        return ;
    }
    else
    {
        if(s>=sum)
            return ;  // 没走到叶子节点权值已经比给定权重打了，直接剪枝掉
        else
        {
            for(int i=0;i<v[node].size();i++)
            {
                q.push_back(w[v[node][i]]);
                DFS(v[node][i],s+w[v[node][i]]);
                q.pop_back();
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m>>sum;
    for(int i=0;i<n;i++)
        cin>>w[i];
    int p,c,num;  // 父节点，子节点,孩子的个数
    for(int i=0;i<m;i++)
    {
        cin>>p>>num;
        for(int j=0;j<num;j++)
        {
            cin>>c;
            v[p].push_back(c);
        }
        sort(v[p].begin(),v[p].end(),cmp);  // 排序
    }
    q.push_back(w[0]);
    DFS(0,w[0]);
    return 0;
}
