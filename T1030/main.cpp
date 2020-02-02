#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=550;
const int INF = 0x777ffff;
/*����������·�㷨�ı��Σ�����Ϊ���ѵ����ڼ�¼���·�ģ�����Ϊ���ѵ����ڸ������·���������ò�����
������
˼·:�������Ժ󣬱Ƚ����·���󣬽���һ���ڵ�����·���ͱ��ڵ����������洢*/
int edge[maxn][maxn];
int cost[maxn][maxn];  // ÿ�����е���С����
int sumcost[maxn];  // ����ÿ�����е���С����
int dist[maxn];  // ����ڵ����̾���
int vis[maxn];   // �ڵ��Ƿ�ѡ��
int mindist = INF;
vector<int>p[maxn];
void add(int x,int y)
{
    for(int i=0;i<p[y].size();i++)
    {
        p[x].push_back(p[y][i]);
    }
}
void clc(int x)   // ��սڵ�
{
    while(!p[x].empty())
        p[x].pop_back();
}
int main()
{
    int n,m,d,c,s,e,c1,c2;
    scanf("%d %d %d %d",&n,&m,&s,&e);
    p[s].push_back(s);
    fill(dist,dist+n,INF);      //��ʼ�����м����Ϊ����
    fill(sumcost,sumcost+n,INF); // ��ʼ���ܷ���Ϊ����
    dist[s]=0;   //�Լ��ľ���Ϊ0
    sumcost[s] = 0; // �ܷ���Ҳ��0
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&c1,&c2,&d,&c);
        edge[c1][c2]= d;
        edge[c2][c1]= d;
        cost[c1][c2]= c;
        cost[c2][c1]= c;
    }
    for(int i=0;i<n;i++)   //Ҫ����n�α���
    {
        mindist=INF;
        int k;
        for(int j=0;j<n;j++)   // �����ڵ�
        {
            if(!vis[j])
            {
                if(dist[j]<mindist)
                {
                    mindist=dist[j];
                    k = j;             //ѡ����������Ľڵ�
                }
            }

        }
        if(k==e)
            break;
        vis[k]=1;
        for(int j=0;j<n;j++)
        {
            if(!vis[j])             // ���¾���
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
                    sumcost[j] = sumcost[k]+cost[j][k];  // �����ܷ���
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
