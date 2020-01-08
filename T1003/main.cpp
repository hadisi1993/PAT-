/*�������һ�����·���⣬����˼·������Dijkstra�㷨���
�ڼ������·��ʱ��Ҫͬʱ�������·����Ŀ�����ռ����������
�ڼ���ʱ���������Ĳ���
1. �������·ʱ����������µ����·�������·�������¼�Ϊ1
2. ������·����͵�ǰ���·������ͬ�����·������1�����ұȽ����ռ������ľ�Ԯ����
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int Max =1e5;
int maxrescueman[600];   //����Ԯ����
int rescue[600];    //�������еľ�Ԯ����
int Distance[600]; //���·�ľ���
int path[600];     //��Ԯ·��
int vis[600];     //�Ƿ�ѡ��
int edge[600][600];  // �������
int main()
{
    int n,m,c1,c2;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&rescue[i]);
    }
    maxrescueman[c1]=rescue[c1];
    for(int i=0;i<m;i++)
    {
        int s,e,v; //��ʼ�ڵ㣬��ֹ�ڵ��ֵ
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
    vis[c1]=1;   //�Լ����ڽڵ㱻ѡ��
    for(int i=0;i<n-1;i++)   // ����n-1��ѡ��
    {
        if(vis[c2])
            break;    //��c2�Ѿ������㣬��ֹͣ����
        int k;        //kΪ��ѡ��Ľڵ�
        int minDistance = Max;
        for(int j=0;j<n;j++)
        {
            if(!vis[j])    //����û�б�ѡ��Ľڵ�
            {
                if(Distance[j]!=0&&Distance[j]<minDistance)
                {
                    minDistance = Distance[j];
                 //   printf("min:%d\n",minDistance);
                    k = j;
                //    printf("k:%d\n",k);
                }
            }
        //    printf("\n");
        }
//        printf("��%d��ѡ��:%d\n",i,k);
//        printf("���º�ڵ���Ϣ\n");
//        for(int j=0;j<n;j++)
//            printf("%d ",Distance[j]);
//        printf("\n");
        vis[k]=1;   //ѡ���½ڵ�
        if(k==c2)
            break;
        for(int j=0;j<n;j++)    //���½ڵ����
        {
            if(!vis[j])
            {
                if(!Distance[j]&&edge[j][k]>0)
                {
                    Distance[j]=Distance[k]+edge[j][k];
                    path[j]=1;
                    maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
                else if(Distance[j]>0&&edge[j][k]&&edge[j][k]+Distance[k]<Distance[j])
                {
                    Distance[j]=edge[j][k]+Distance[k];
                    path[j]=1;
                    maxrescueman[j]=maxrescueman[k]+rescue[j];

                }
                else if(Distance[j]>0&&edge[j][k]&&edge[j][k]+Distance[k]==Distance[j])
                {
                    path[j]+=1;
                    if(maxrescueman[k]+rescue[j]>maxrescueman[j])
                        maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
            }
        }
    }
    printf("%d %d\n",path[c2],maxrescueman[c2]);
    return 0;
}
