#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/*这道题是一道模拟题，很考验我们的耐心
1.为每个窗口设立一个客户队列，队列中存储的是排在该窗口的顾客的序号，另外设立一个数组，存储顾客的办理时间
2.遍历经营时间(8:00~17:00),判断每个时间是否有空窗口，有的话安排顾客；如果没有窗口，则当前窗口的剩余时间-1
3.为了节约时间,可以先排n*m个，再排剩下的，剩下的按照时间遍历

这道题很坑的一点就是如果有人在17:00前服务，服务结束时间超过17:00，它也会给你服务完
*/
struct Windows{
  queue<int>q;   //q记录的是序号
  int remaintime=0;   //设开始的等候时间为0
}wd[25];
int tf[1005];      //个人交易所花时间
int ctd[1005];    //每个人办理完业务的时间，用秒钟记
int cutime=1;
int main()
{
    int n,m,k,Q;
    scanf("%d %d %d %d",&n,&m,&k,&Q);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&cutime);
        tf[i] = cutime;
    }
    int index;  // 查询序号
    int i =1;
    cutime=1;  //当前经过的时间
    for(int j=1;j<=m;j++)   //先放前面n*m个
    {
        for(i=1;i<=n;i++)
        {
            if(i+(j-1)*n<=k)
            {
                if(j==1)
                    wd[i].remaintime=tf[i];
                wd[i].q.push(i+(j-1)*n);
            }
        }
    }
    i = n*m+1;  //如果还有没排队的顾客那就从n*m+1个开始
    while(cutime<=600)     //当前时间，按照题意10个小时内服务可以结束
    {
        for(int j=1;j<=n;j++)
        {
            if(wd[j].remaintime>0)
            {
                wd[j].remaintime-=1;              //一分钟过去了
                if(wd[j].remaintime==0)
                {
                    index = wd[j].q.front();   //办理完的顾客
                    ctd[index] = cutime;
                    wd[j].q.pop();
                    if(i<=k)
                    {
                        wd[j].q.push(i);      //    插入新的顾客
                        i++;                 //下一个等候的顾客
                    }
                    if(wd[j].q.size()>0&&cutime<540)        //17:00以后不再服务，新的顾客不再插入
                    {
                        index = wd[j].q.front();
                        wd[j].remaintime = tf[index];       //更新代办时间
                    }
                    else
                        wd[j].remaintime = 0;
                }
            }
        }
        cutime++;
    }
    for(i=0;i<Q;i++)
    {
        scanf("%d",&index);
        if(ctd[index])
            printf("%02d:%02d\n",8+ctd[index]/60,ctd[index]%60);
        else
            printf("Sorry\n");
    }
    return 0;
}
