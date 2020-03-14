#include<iostream>
#include<algorithm>
using namespace std;
/*原则:便宜的加油站多加油
1. 将加油站结构体按照油价排序
2. 选择加油站,加油站包括车到这里剩多少油
3. 在车的运动范围内，看能不能找到更便宜的加油站(或者是终点)，如果能找到则加油到刚好能开到那个加油站，否则全部加满
4. 车在运动的过程中，更新运动范围内的加油站的含油量
5. 将加油站结构体按距离排序,判断能不能到达
6. 按照每个加油站的情况，计算最远能到达的距离
*/
double sum=0 ;  // 重费用
double cap,dist,per;
int n;
struct station
{
    int flag;   // 是否能够到达
    double price;
    double distance; //当前距离
    double remain;  // 车剩下的油量
    double m_distance;   // 加满油最远能够到达的距离
}S[505];
bool cmp1(station a,station b)
{
    return a.price<b.price;
}
bool cmp2(station a,station b)
{
    return a.distance<b.distance;
}
int main()
{
    cin>>cap>>dist>>per>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf",&S[i].price,&S[i].distance);
        S[i].m_distance=S[i].distance+per*cap<=dist?S[i].distance+per*cap:dist;  // 计算最远能到达的距离
    }
    sort(S,S+n,cmp1);  // 按照价格排序
    for(int i=0;i<n;i++)
    {
        double add=0;
        int index=0;  // 标记离它最近的加油站
        int flag=0;  //标记这个加油站是否存在
        for(int j=0;j<i;j++)
        {
            if(S[j].distance>S[i].distance&&S[i].m_distance>=S[j].distance)
            {
                if(index==0||S[j].distance<S[index].distance)
                {
                    index = j;
                    flag =1;
                }
            }
        }
        if(S[i].remain*per+S[i].distance<dist)  // 目前的油开不到终点
        {
            if(flag)
                add=S[i].price*((S[index].distance-S[i].distance)/per-S[i].remain);  //
            else
            {
                if(S[i].m_distance<dist)  // 终点不再可达范围内，那加满油就行了
                    add = (cap-S[i].remain)*S[i].price;
                else
                    add = ((dist-S[i].distance)/per)*S[i].price;
            }
        }
        for(int j=0;j<n;j++)
        {
            if(S[j].distance>S[i].distance&&S[i].m_distance>=S[j].distance)
            {
                S[j].remain = cap-(S[j].distance-S[i].distance)/per;  // 更新剩下的油量
            }
        }
       // cout<<add<<endl;
        sum+=add;    //更新费用
    }
    sort(S,S+n,cmp2);  // 按照距离排序
    for(int i=0;i<n;i++)
    {
        if(S[i].distance ==0)
            S[i].flag = 1;
        if(S[i].flag)
        {
            for(int j=0;j<n;j++)
            {
                if(S[j].distance<=S[i].m_distance)
                    S[j].flag=1;
            }
        }
    }
    double maxdist=0;
    for(int i=0;i<n;i++)
    {
        if(S[i].flag)
            maxdist=max(maxdist,S[i].m_distance);
    }
    if(maxdist==dist)
        printf("%.2f\n",sum);
    else
        printf("The maximum travel distance = %.2f\n",maxdist);
    return 0;
}
/*第4个测试点包含了有多个加油站距离目标城市的距离小于等于邮箱最大容积的行驶距离且距离目标城市越近的加油站油越贵。*/
