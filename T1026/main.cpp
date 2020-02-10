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
后来发现，按照原想法，加入队列的就要是节点的地址，这样才能修改数据。这样太复杂了，所以换了一个想法
如果是vip桌，直接在当前用户向后找第一个可能的vip用户既可
前面交了两次，得到24分，说明还是有不对的地方，我又看了一下题目，发现有一个地方没有考虑，假如一个
vip用户来到球馆，所有的桌都是空的，那他应该会优先选择vip桌,这样做又多了4分
最后的2分是这样的，题目里说假定一对的服务时间不超过2小时，这道题是要我们自己设定的，以前的题目测试数据
中好像没有这个测试点
*/
using namespace std;
int cutime =0; // 当前时间
struct baller
{
    int atime; // 到达时间
    int ptime; // 运动时间
    int vip; //是不是vip
    int flag; // 是否已经加入了
    int stime; // 开始处理的时间
    bool operator <(const baller&b)const
    {
        return atime<b.atime;
    }
}b[10005];
struct table
{
    int remain;
    int vip; // 是不是vip桌
    int sev; // 服务的人数
    int id;
    table()
    {
        remain = 0;
        vip=0;
        sev=0;
    }
}Table[200];
int str2time(char*str)
{
    int h,m,s;
    sscanf(str,"%d:%d:%d",&h,&m,&s);
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
    s = t2%60;
    printf("%02d:%02d:%02d %.0f\n",h,m,s,round((float)(t2-t1)/60));
}
bool cmp(baller a,baller b)
{
    return a.stime<b.stime;
}
int main()
{
    char str[20];
    int t,v; // 处理时间和是不是vip
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d",str,&t,&v);
        b[i].atime = str2time(str);
        b[i].ptime = t*60;
        b[i].vip = v;
    }
    int cnt,vcnt; // 桌子数和vip桌子数
    scanf("%d %d",&cnt,&vcnt);
    int w;
    for(int i=0;i<vcnt;i++)
    {
        scanf("%d",&w);
        Table[w].vip = 1;
    }
    cutime = 8*3600;
    sort(b,b+n);
    int ab = 0;  // 服务完了的人
    while(ab<n&&cutime<21*3600)
    {
        for(int i=1;i<=cnt;i++)    //首先遍历vip桌，和vip球员配对
        {
            if(Table[i].vip&&ab<n&&!Table[i].remain)     // 是vip桌
            {
                int p = ab;    // 从当前用户开始，查找vip用户
                while(p<n)
                {
                    if(b[p].vip&&!b[p].flag&&cutime>=b[p].atime)   // 当前队伍中有vip顾客可以服务
                        break;
                    p++;
                }
                if(p<n)      //找到了可以服务的vip客户
                {
                    b[p].stime = cutime;  // 将当前时间记为开始服务的时间
                    Table[i].remain =b[p].ptime>7200?7200:b[p].ptime;   //这里先不减去当前服务的1秒，再次遍历时统一减
                    Table[i].sev+=1;
                    b[p].flag = 1;
                }
            }
        }
        for(int i=1;i<=cnt;i++)//已经没有vip球员要去vip桌了
        {
            if(!Table[i].remain&&ab<n)
            {
                while(b[ab].flag)    //跳过当前所有被服务过的vip用户
                  ab++;
                if(cutime>=b[ab].atime&&ab<n)
                {
                    Table[i].remain = b[ab].ptime>7200?7200:b[ab].ptime-1;
                    Table[i].sev+=1;
                    b[ab].stime = cutime;
                    ab++;
                }
            }
            else if(Table[i].remain>0)
            {
                Table[i].remain-=1;
            }
        }
        cutime++;
    }
    sort(b,b+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(b[i].stime)
            print(b[i].atime,b[i].stime);
    }
    for(int i=1;i<=cnt;i++)
    {
        if(i>1) printf(" ");
        printf("%d",Table[i].sev);
    }

    return 0;
}
