#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
/*������һ������ʱ���˺�1013һ���Ĵ��󣬶������ó���ȵķ���ȥ���������⡣�������̫���ˣ�
�ڶ��γ�����DFSȥ����˼·��������
1.�����ڵ����Ƚϴ�Ҫ���ڽӱ�������ͼ
2.����Ҫ����ͨ�����������ͨ��������1����ʾ�ڵ��д���
3.��DFS������Ҫ��¼����Ĳ�
�������Ĺ����г��������⣬��ΪҪ������ĸ������Զ����еĽڵ㶼Ҫ���б������Ҳ�����vis
��������ͨ�����ͼ�¼�ڵ�Ҫ�ֿ������ߣ�������ǳ�ʱ
*/
const int maxn=1e4+5;
int vis[maxn];
int cnt;   // ��ͨ�������
int dept;  // ����ĸ�
vector<int>P[maxn];
vector<int>node;   // ����Ľڵ�
int n,u,v;
int flag;       //�ж��Ƿ񳬳��˵�ǰ��ĸ�
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
void DFSTrave()     // ��һ�α�����������ͨ�����ĸ���
{
    for(int i=1;i<=n;i++)      // ��ÿ���ڵ㶼���б���
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
void DFSTrave2()    // �ڶ��α�����������ĸ�
{
    for(int i=1;i<=n;i++)      // ��ÿ���ڵ㶼���б���
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
    if(cnt>1)        // �ж����ͨ����
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
