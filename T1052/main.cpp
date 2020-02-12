#include <iostream>
#include<algorithm>
using namespace std;
//这道题想让我们把链表排个序(按照key值的大小，)，输入格式同T1032
//节点的当前地址和key值没有改变，改变的是next节点的值
//第一次做的时候是这么想的:先将值提取出来，然后排序，排序以后再遍历原链表，查找对应的值，添加到新链表中
//第二次想的时候，要不直接按列表做插入排序吧，得了21分
//这道题的坑点在于给出的节点不一定都在链表上，有可能有无效节点
const int maxn = 1e5+5;
int v[maxn];   // key值的大小
struct node
{
    int key;
    int next;  // 下一个的地址
    node()
    {
        next = -1;
    }
}S[maxn],N[maxn];
int main()
{
    int s1,s2,n;
    scanf("%d %d",&n,&s1);
    int cur,next,value;
    for(int i=0;i<n;i++)       //构建初始链表
    {
        scanf("%d %d %d",&cur,&value,&next);
        S[cur].key = value;
        S[cur].next = next;
    }
    //按照初始链表做插入排序
    s2 = -1;
    int cnt =0;   // 在链表上的节点数
    for(int i=s1;i!=-1;i=S[i].next)
    {
        cnt++;
        int j;
        int pre = -1;
        for(j=s2;j!=-1;j=N[j].next)
        {
            if(S[i].key<N[j].key)
                break;
            pre = j;
        }
        N[i].key = S[i].key;
        if(j>0)             // 在链表当中插入
            N[i].next = j;
        if(pre>0)
            N[pre].next = i;
        else
            s2 = i;
    }
    cnt>0?printf("%d %05d\n",cnt,s2):printf("0 -1");
    for(int i=s2;i!=-1;i=N[i].next)
        N[i].next==-1?printf("%05d %d %d\n",i,N[i].key,N[i].next):printf("%05d %d %05d\n",i,N[i].key,N[i].next);
    return 0;
}
