#include<iostream>
#include<algorithm>
using namespace std;
/*这道题和之前做过的题很像，不同之处在于它要计算平均等待时间，而且窗口只有一个人，所以不需要队列
1.设立顾客类结构体，放置到达时间，业务处理时间和比较运算符;用一个数组保存窗口处理当前顾客业务的剩余时间
2.统计17:00前来的顾客的数量
2. 从8:00开始，按时间遍历，首先遍历窗口是否有人，如果没有人，比较当前时间和下一个顾客的到来时间，如果存在该顾客且当前
时间大于等于该时间，则安排该顾客进入窗口，将顾客的业务处理时间赋给窗口数组；如果都有人，则窗口剩余时间-1；
3.遍历到所有17:00到的顾客业务处理完毕为止
注意：需要一个函数，将时间转化为整数，可以将该时间和00:00:00之间的秒数作为时间保存

这题和上面一道题不同的地方在于，只要有人来服务(在下午5:00之前)，就可以被服务完
*/
int W[105];    //用数组存放每个窗口剩余的业务时间
struct Customer
{
    int arrtime; //到达时间
    int protime; //业务处理时间
    bool operator<(const Customer&a)const
    {
        return arrtime<a.arrtime;
    }
}C[10005];
int calsec(char*str)  // 计算时间间隔
{
    int h,m,s;
    sscanf(str,"%d:%d:%d",&h,&m,&s);
    return h*3600+m*60+s;
}
int main()
{
    float totalwaittime=0;   // 总的等待时间
    int n,k;
    scanf("%d %d",&n,&k);
    int numc=0;  //处理的人数
    char str[20];
    int ptime;
    for(int i=0;i<n;i++)
    {
        scanf("%s %d",str,&ptime);
        C[i].arrtime = calsec(str);
        C[i].protime = ptime*60;
    }
    sort(C,C+n);       //按照到达时间从小到大排序排序
    int ab=0;           //17:00以前的可以被服务的人群
    for(int i=0;i<n;i++)
        if(C[i].arrtime<=17*3600)
            ab++;
    int Current = 8*3600;    // 当前时间，从8:00开始计算
    while(numc<ab)                 //是否所有该被服务的人都被服务了
    {
        for(int i=0;i<k;i++)
        {
            if(W[i])
                W[i]-=1;                           //如果有人，则服务一秒钟
            else
            {
                if(Current>=C[numc].arrtime&&numc<ab)    //在遍历窗口中，可能numc有可能等于ab，所以还是要写上
                {
                    W[i] = C[numc].protime-1;       // 安排人,同时服务一秒钟
                    totalwaittime +=Current-C[numc].arrtime;
                    numc++;
                }

            }
        }
        Current+=1;        // 当前时间加1
    }
    if(ab==0)         //下午5:00之前没有人到来，则平均等待时间即为0
        printf("0.0");
    else
        printf("%.1f",(totalwaittime/ab)/60.0);
    return 0;
}
