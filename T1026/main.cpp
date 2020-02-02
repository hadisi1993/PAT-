#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
/*这道题和以前做过的1014、1017题很像，都是模拟题，但是要更加复杂一点，因为它有一个VIP桌
所以在遍历乒乓球桌的时候1.要看乒乓球桌是不是VIP桌2.要看队伍中有没有VIP客户
题目的流程大致如下
1.遍历球桌，检测球桌是不是空的，有空的
    1.1 非VIP球桌，比较当前时间和第一个等待球员的到达时间，若大于则分配
    1.2 VIP球桌，查找队伍中是否有VIP球员，有的话比较当前时间和其到达时间，若大于则分配，否则在非VIP球员中
    查找
2.如果不是空的则服务时间-1
3.当前时间+1
问题关键:VIP球员和非VIP球员如何存储
我的想法是:所有球员用一个数组存储，VIP球员用另一个优先队列存储，存球员地址，球员结构体中用一个符号
标记球员是否被服务过，这样遍历所有球员时可以跳过已经服务过的VIP球员
*/
using namespace std;
int cutime =0; // 当前时间
struct baller*
{
    int atime; // 到达时间
    int ptime; // 运动时间
    int vip; //是不是vip
    int flag; // 是否已经加入了
    int stime; // 开始处理的时间
    bool operator <(const baller*&b)const
    {
        return b->atime<time;
    }
}b[10005];
struct table
{
    int remain;
    int vip; // 是不是vip桌
    int sev; // 服务的人数
    table()
    {
        remain = 0;
        vip=0;
    }
}Table[200];
int waittime[10005];
int str2time(char*s)
{
    int h,m,s;
    sscanf(s,"%d:%d:%d",&h,&m,&s);
    return 3600*h+60*m+s;
}
void print(int t1,int t2)  // 时间戳转时间
{
    int h,m,s;
    h = t1/3600;
    m = (t1-3600*h)/60;
    s = t1%60;
    printf("%02d:%02d:%02d ",h,m,s);
    h = t2/3600;
    m = (t2-3600*h)/60;
    s = t12%60;
    printf("%02d:%02d:%02d %d\n",h,m,s,round((t2-t1)/60));
}
struct cmp{
    bool operator ()(baller*x,baller*y)
    {
        return x->atime<y.time;
    }
};
priority_queue<baller*,vector<baller*>,cmp>Q;  // VIP用户
int main()
{
    char str[20];
    int t,v; // 处理时间和是不是vip
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d",str,&t,&v);
        b[i]->atime = cal(str);
        b[i]->ptime = cal(t);
        b[i]->vip = v;
        if(v)
        {
            Q.push(b[i]);
        }
    }
    sort(b,b+n);
    int cnt,vcnt; // 桌子数和vip桌子数
    scanf("%d %d",&cnt,&vcnt);
    int w;
    for(int i=0;i<vcnt;i++)
    {
        scanf("%d",&w);
        Table[w].vip = 1;
    }
    cutime = 8*3600;
    int ab = 0;  // 服务完了的人
    while(Cutime<17*3600)
    {
        for(int i=0;i<cnt;i++)
        {
            if(Table[i].remain==0&&ab<n)  //球台没有人，还有人要服务
            {
                 if(Table[i].vip&&Q.size()>0)    //这张桌子是vip桌,且有vip客户
                {
                    baller*tmp = Q.top();
                    if(tmp->atime<Cutime)
                    {
                        Table[i].remain = tmp->ptime;
                        Table[i].sev +=1;
                        tmp->flag=1;  // 去打球
                        Q.pop();   //从等待队列中删除
                    }
                    else                //vip无人或
                    {
                        while(b[ab]->flag)   // 已经处理过的vip
                            ab++;
                        if(b[ab]->atime<Cutime)  // 如果当前时间大于等待时间
                        {
                            Table[i].remain = b[ab]->ptime;
                            Table[i].sev+=1;
                            b[ab]->wtime =Cutime;
                            ab++;
                        }

                    }
                }
                else
                {
                    while(b[ab]->flag)   // 已经处理过的vip
                        ab++;
                    if(b[ab]->atime<Cutime)  // 如果当前时间大于等待时间
                    {
                        Table[i].remain = b[ab]->ptime;
                        b[ab]->wtime =Cutime;
                        ab++;
                    }
                }
            }

        }
        Cutime++;
    }
    for(int i=0;i<n;i++)
    {
        if(b[i].stime)
            printf("%02d:%02d:%02d %02d:%02d:%02d %d",,,,,);
    }
    for(int i=0;i<cnt;i++)
    {
        if(i) printf(" ");
        printf("%d",Table[i].sev);
    }

    return 0;
}
