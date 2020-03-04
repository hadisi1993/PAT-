#include<iostream>
#include<map>
using namespace std;
/*这道题的题意很明确，就是要找第一个出现的独一无爱的数
做法，用map和vis数组
*/
map<int,int>m;
int vis[100005];
int main()
{
    int n,v,flag=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v);
        vis[i]=v;
        m[v]++;
    }
    map<int,int>::iterator it;
    for(int i=0;i<n;i++)
    {
        if(m[vis[i]]==1)
        {
            flag = 1;
            printf("%d\n",vis[i]);
            break;
        }
    }
    if(!flag)
        printf("None\n");
    return 0;
}
