#include<iostream>
#include<algorithm>
using namespace std;
/*这道题我的想法就是用一个数组来保存图,然后计算每个节点的出度，看哪些节点的出度为1且只和被占领的节点相连*/
int edge[1005][1005];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int cnt,ocp; // 需要增加的条数和被占领的节点
    int s,e;
    for(int i=0;i<m;i++)
    {
        cin>>s>>e;
        edge[s][e]=1;
        edge[e][s]=1;
    }
    for(int i=0;i<k;i++)
    {
        cin>>ocp;
        cnt = 0;
        for(int j=1;j<=n;j++)
        {
            if(edge[j][ocp]==1)
            {
                cnt+=1;
                for(int l=1;l<=n;l++)
                {
                    if(edge[j][l]&&l!=ocp)
                    {
                        cnt-=1;
                        break;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
