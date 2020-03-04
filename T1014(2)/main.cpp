#include<iostream>
#include<queue>
using namespace std;
struct Windows
{
    int id;   // 当前id
    int cutime;  // 当前时间
    Windows()
    {
        cutime = 0;
    }
};
int tf[1005];      //个人交易所花时间
int ctd[1005];    //每个人办理完业务的时间，用秒钟记
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
