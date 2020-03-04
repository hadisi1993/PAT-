#include<iostream>
#include<algorithm>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>
#include<iomanip>
#include<map>
using namespace std;
/*这是一道模拟题，非常复杂，首先我们要把思路理清楚
1.输入包括，每个时间段的话费和一系列序列，每个序列包括三个元素:通话人,时间(月,日,时,分)，打出还是挂断
所以我们设立一个结构体record来存储这三个元素:姓名(字符串)，时间(距月初的秒数)，on/off(1/0)
2.序列是无序的，而且不一定完全内配对上,当同一个人连续有两个打出的记录,选择后一个，连续有两个挂断的记录，选择前一个
首先先给结构体数组按姓名，时间排序，排完以后再创建一个顾客结构体，成员包括姓名，第一次通话时间，通话队列，队列中存储pair<int,int>（打出和挂断）
3.题目要求是求话费,所以要计算费用，按照时间遍历一个顾客从开始到结束的时间，计算费用并换算
*/
struct record
{
    string name;
    int Time;
    int status;   // 1:on,0:off
    bool operator <(const record&a)const
    {
        if(name!=a.name)
            return name<a.name;        //先按姓名排序，这样同一个人的记录会连在一起
        else
            return Time<a.Time;
    }
}r[1005];
map<string, priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > >mu; //创建一个map，map中有一个优先队列。
int str2timeb(string s)   //返回分钟数
{
    int mm,d,h,m;
    sscanf(s.c_str(),"%d:%d:%d:%d",&mm,&d,&h,&m);
    return d*24*60+h*60+m;
}
int toll[24];           //单位时间的话费
float calmoney(int x,int y)
{
    float res = 0.0;
    for(int i=x;i<y;i++)
    {
        int m = (i%1440)/60;
        res+=toll[m];
    }
    return res/100.0;
}
void print(int t1,int t2)   // 显示时间的函数
{
    int d=t1/1440;
    int h = (t1-d*1440)/60;
    int m = t1%60;
    cout<<setw(2)<<setfill('0')<<d<<":"<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<" ";
    d=t2/1440;
    h = (t2-d*1440)/60;
    m = t2%60;
    cout<<setw(2)<<setfill('0')<<d<<":"<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<" ";
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q[1000];
int main()
{
    for(int i=0;i<24;i++)
        cin>>toll[i];
    int n;
    cin>>n;
    string name,TimeStr,st;
    string month;
    for(int i=0;i<n;i++)
    {
        cin>>name>>TimeStr>>st;
        r[i].name = name;
        r[i].status = st=="on-line"?1:0;
        r[i].Time = str2timeb(TimeStr);
        month = TimeStr.substr(0,2);
    }
    sort(r,r+n);  // 排序
    int on=0,off=0;
    string flagname = r[0].name;      // 第一个名字
    int numc=0;       // 第几个顾客
    for(int i=0;i<n;i++)
    {
        if(flagname!=r[i].name||i==0)
        {
            mu[r[i].name]= q[numc++];
            flagname = r[i].name;
            on = 0;          //换了人重新开始记
        }
        if(r[i].status==1)
            on = r[i].Time;
        else
        {
            if(on)
                off = r[i].Time;
        }
        if(on&&off)
        {
            mu[flagname].push(make_pair(on,off));    //将队列输入
            on = 0;
            off =0;
        }
    }
    for(map<string, priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > >::iterator it = mu.begin();it!=mu.end();it++)
    {
        float totalmoney =0.0;
        float money = 0.0;
        if(it->second.size()>0)
        {
             cout<<it->first<<" "<<month<<endl;
            while(!it->second.empty())
            {
                money = calmoney(it->second.top().first,it->second.top().second);  // 计算费用
                print(it->second.top().first,it->second.top().second);  // 打印输出
                cout<<it->second.top().second-it->second.top().first<<" "<<"$"<<setiosflags(ios::fixed)<<setprecision(2)<<money<<endl;
                totalmoney +=money;
                it->second.pop();
            }
            cout<<"Total amount: $"<<setiosflags(ios::fixed)<<setprecision(2)<<totalmoney<<endl;
        }
    }
    return 0;
}
