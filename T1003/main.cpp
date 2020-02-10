/*�������һ�����·���⣬����˼·������Dijkstra�㷨���
�ڼ������·��ʱ��Ҫͬʱ�������·����Ŀ�����ռ����������
�ڼ���ʱ���������Ĳ���
1. �������·ʱ����������µ����·�������·�������¼�Ϊ1
2. ������·����͵�ǰ���·������ͬ�����·������1�����ұȽ����ռ������ľ�Ԯ����������·�����ռ���
��Ԯ����

3. �����ǰ��һֱ�����һ������Ҫ��ԭ���ǣ�û�п��ǵ�������·��ʱ�������ӵ�·����Ŀ����1��������
ǰ��һ���ڵ��·����������һ���Ӿ��ǣ�Ҫ���ǳ����ڵ���ǵ���ڵ�������
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int INF =1e6;
int maxrescueman[600];   //�������е�����Ԯ����
int rescue[600];    //�������еľ�Ԯ����
int Distance[600]; //���·�ľ���
int path[600];     //��Ԯ·�ߵ���Ŀ
int vis[600];     //�Ƿ�ѡ��
int edge[600][600];  // �������
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
    path[S]=1;       //���Լ��ĵ�
    maxrescueman[S]=rescue[S];
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&s,&e);
        scanf("%d",&edge[s][e]);
        edge[e][s] = edge[s][e];            //�Գƾ���
    }
    for(int i=0;i<n;i++)   // ��������n��ѭ��,�������Ͳ��������⴦����
    {
        int k=-1,minDistance = INF;        //kΪ��ѡ��Ľڵ㣬��������̾���;
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&Distance[j]<minDistance)
            {
                minDistance = Distance[j];
                k = j;
            }
        }
       // printf("%d",k);
        if(k==-1) break;  // û���µ���ͨ�ڵ���
        vis[k]=1;   //ѡ���½ڵ�
        for(int j=0;j<n;j++)    //���½ڵ����
        {
            if(!vis[j]&&edge[j][k])
            {
                if(edge[j][k]+Distance[k]<Distance[j])
                {
                    Distance[j]=edge[j][k]+Distance[k];            //�����µ�·��
                    path[j]=path[k];
                    maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
                else if(edge[j][k]+Distance[k]==Distance[j])
                {
                    path[j]+=path[k];                                     //�����µ�·�߱�����
                    if(maxrescueman[k]+rescue[j]>maxrescueman[j])
                        maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
            }
        }
    }
    printf("%d %d\n",path[E],maxrescueman[E]);
    return 0;
}
