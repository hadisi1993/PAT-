#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 505;
const int INF = 0x7fffff;
/*����⻹�����·�ı������⣬����Ҫѡ�����·����Ҫ
1. ͳ�����·��Ҫ���͵����г�����Ŀ���Լ�Ҫ���ص����г�����Ŀ
2. ͳ��·��
ע��:�������һ����Ŀ��������������ʵ��һ�㲻���ף���û��˵����ܲ����ú���Ҫ���صĳ�����ǰ��
δ����ͣ���㣬�Ҽ������������ϵ����г����ͺʹ����Ƿֿ��ģ�����һ�����·��������վ�������ֱ�����1,8
�Ǿ�������4��������3��������������1��
��������Ϊ�����Ӧ����ô˼��
1. ���յϽ�˹�����㷨�����·
2. ���·�����ͺ��ջص����г��ǲ��ܵ��Ƶģ���Ϊ���һ�����ӵĽڵ��Ӱ�����·��ѡ��������������·�Ժ�
��������������㷨�Ӷ��㿪ʼ������������Ŀ��ڵ��Ժ�������������С���룬�Ƚ����͵����г��ͻ��յ����г�
��Ŀ��ѡ����õ�·��
*/
vector<int>p;    // ���浱ǰ·��
vector<int>px;
int minbikeS=INF;    // �������ٵ�������
int minbikeT=INF;    // �������ٵĻ�����
int edge[maxn][maxn]; // ͼ
int cap[maxn];        // ����
int vis[maxn];
int dist[maxn];
int c,n,e,m;
void DFS(int s,int D)   // ��ǰ�ڵ㣬����
{
    vis[s] = 1;
    p.push_back(s);   // ����ýڵ�
    if(s==e)          //����Ŀ�ĵ�
    {
        if(D==dist[e])         // ��һ�����·
        {
           // printf("�ҵ����·\n");
            //�����������ʹ�����
            int send=0,take=0;
            for(int i = 0;i<p.size();i++)
            {
                int temp = p[i];   // ��ǰ�ڵ�
                if(temp)
                {
                    send+=(c/2-take-cap[temp])>0?c/2-take-cap[temp]:0;
                    take = take+cap[temp]-c/2>0?take+cap[temp]-c/2:0;
                   // printf("�ӵ�ǰ�ڵ����:%d\n",take);
                }
            }
            //���������·��
            if(send<minbikeS||(send==minbikeS&&minbikeT>take))
            {
                minbikeS = send;
                minbikeT = take;
                px.clear();
                for(int i=0;i<p.size();i++)
                {
                    px.push_back(p[i]);
                }
            }
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&edge[s][i])
        {
            DFS(i,D+edge[s][i]);
            p.pop_back();
            vis[i]=0;
        }
    }
}
void DFSTrave()      // DFS����
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&edge[0][i])     // ���������
        {
            DFS(i,edge[0][i]);
            p.pop_back();
            vis[i]=0;
        }

    }
}
int main()
{
    scanf("%d %d %d %d",&c,&n,&e,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&cap[i]);
    int sp,ep,v;   //
    fill(dist+1,dist+n+1,INF);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&sp,&ep,&v);
        edge[sp][ep]=v;
        edge[ep][sp]=v;
        if(!sp)
            dist[ep]=v;
        if(!ep)
            dist[sp]=v;
    }
    int mindist,k;
    for(int i=0;i<n;i++)            //�����·
    {
        mindist = INF;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&mindist>dist[j])
            {
                mindist = dist[j];
                k = j;
            }
        }
       // printf("%d\n",k);
        if(k==e)
            break;
        vis[k]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&edge[j][k]&&dist[j]>dist[k]+edge[j][k])
                dist[j] = dist[k]+edge[j][k];
        }
    }
   // for(int i=1;i<=n;i++)
     //   printf("%d\n",dist[i]);
    //printf("1\n");
    fill(vis,vis+n+1,0);      // ��vis�������Ϊ0��DFSʱ��¼��������
    DFSTrave();
    printf("%d 0",minbikeS);
    for(int i=0;i<px.size();i++)
    {
        printf("->");
        printf("%d",px[i]);
    }
    printf(" %d\n",minbikeT);
  //  printf("%d\n",dist[3]);
    return 0;
}
