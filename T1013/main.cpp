#include<iostream>
#include<algorithm>
using namespace std;
/*������ҵ��뷨������һ������������ͼ,Ȼ�����ÿ���ڵ�ĳ��ȣ�����Щ�ڵ�ĳ���Ϊ1��ֻ�ͱ�ռ��Ľڵ�����*/
int edge[1005][1005];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int cnt,ocp; // ��Ҫ���ӵ������ͱ�ռ��Ľڵ�
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
