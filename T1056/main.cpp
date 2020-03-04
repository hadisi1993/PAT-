#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*这道题的难点应该在分块上，我先用vector来做试试看*/
int p,g;
vector<int >v[1005];   // 每一层代表一轮比赛
int w[1005];
int R[1005];
int Rank(int n)  // 给函数中的函数排名
{
    int l = 0;
    while(1)
    {
        if(v[l].size()==1)
            return l;
        else
        {
            int maxn=-1;
            for(int i=0;i<v[l].size();i++)
            {
                if(maxn==-1||w[v[l][i]]>w[maxn])
                    maxn = v[l][i];
                //printf("w[v[l][i]]  %d  maxn: %d\n",w[v[l][i]],maxn);
                if((i+1)%n==0||i+1==v[l].size())
                {
                    v[l+1].push_back(maxn);
                    maxn = -1;
                }
            }
            l++;  // 进入下一层
        }
    }
}
int main()
{
    scanf("%d %d",&p,&g);
    for(int i=0;i<p;i++)
        scanf("%d",&w[i]);
    int r;
    for(int i=0;i<p;i++)
    {
        scanf("%d",&r);  // 输入排名
        v[0].push_back(r);  // 输入排名
    }
    int res = Rank(g);   // 排序结果
    //printf("%d\n",res);
    int sum=0;
    while(res>=0)
    {
        for(int i=0;i<v[res].size();i++)
            if(!R[v[res][i]])
                R[v[res][i]]=sum+1;
        sum=v[res].size();
        res--;
    }
    printf("%d",R[0]);
    for(int i=1;i<p;i++)
        printf(" %d",R[i]);
    return 0;
}
