/*题目的意思很简单，就是求一颗树每一层叶子节点的个数,关键的问题是我们怎么保存一棵树，以及怎么搜索节点
因为这道题给的数据量不大，而且对每个节点来说，只要知道节点的父亲节点和孩子个数，就可以做这道题，所以只需要
1.用一个数组保存每个节点的父亲节点
2.用一个数组保存孩子的个数
3.用一个数组保存每一层没有孩子节点的个数
建树完成以后，遍历第二个数组，找到没有孩子的节点，然后用第一个数字向前遍历，确定层数，则该层没有孩子节点的个数加1
*/
#include<iostream>
#include<algorithm>
using namespace std;
int father[505];  //父亲节点
int childnum[505];
int levelnum[505];  //每一层叶子节点的个数
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        father[i]=-1;
    }
    for(int i=0;i<m;i++)
    {
        int f,k; //f代表父亲节点，k代表孩子的数目
        scanf("%d %d",&f,&k);
        childnum[f]=k;
        for(int j=0;j<k;j++)
        {
            int c;  //c代表孩子节点
            scanf("%d",&c);
            father[c]=f;
        }
    }
    int maxlevel =0;  //记录最深有几层
    for(int i=1;i<=n;i++)
    {
        if(childnum[i]==0) //没有孩子
        {
            int l =1; //层数
            int p = i;  //指针
            while(father[p]!=-1)
            {
                l++;
                p=father[p];
            }
            levelnum[l]+=1;
            if(l>maxlevel)
                maxlevel = l;
        }
    }
    //输出节点个数
    for(int i=1;i<=maxlevel;i++)
    {
        if(i>1) printf(" ");
        printf("%d",levelnum[i]);
    }
    return 0;
}
