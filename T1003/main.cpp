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
const int Max =1e6;
int maxrescueman[600];   //�������е�����Ԯ����
int rescue[600];    //�������еľ�Ԯ����
int Distance[600]; //���·�ľ���
int path[600];     //��Ԯ·�ߵ���Ŀ
int vis[600];     //�Ƿ�ѡ��
int edge[600][600];  // �������
int main()
{
    int n,m,c1,c2;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    path[c1]=1;       //���Լ��ĵ�
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
                    k = j;
                }
            }
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
                if(!Distance[j]&&edge[j][k]>0)                  //�µ���ͨ�Ľڵ�
                {
                    Distance[j]=Distance[k]+edge[j][k];
                    path[j]=path[k];
                    maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
                else if(Distance[j]>0&&edge[j][k]&&edge[j][k]+Distance[k]<Distance[j])
                {
                    Distance[j]=edge[j][k]+Distance[k];            //�����µ�·��
                    path[j]=path[k];
                    maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
                else if(Distance[j]>0&&edge[j][k]&&edge[j][k]+Distance[k]==Distance[j])
                {
                    path[j]+=path[k];                                     //�����µ�·�߱�����
                    if(maxrescueman[k]+rescue[j]>maxrescueman[j])
                        maxrescueman[j]=maxrescueman[k]+rescue[j];
                }
            }
        }
    }
    printf("%d %d\n",path[c2],maxrescueman[c2]);
    return 0;
}
