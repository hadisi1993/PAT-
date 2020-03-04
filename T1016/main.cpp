#include<iostream>
#include<algorithm>
#include<string>
#include<algorithm>
#include<queue>
#include<utility>
#include<iomanip>
#include<map>
using namespace std;
/*����һ��ģ���⣬�ǳ����ӣ���������Ҫ��˼·�����
1.���������ÿ��ʱ��εĻ��Ѻ�һϵ�����У�ÿ�����а�������Ԫ��:ͨ����,ʱ��(��,��,ʱ,��)��������ǹҶ�
������������һ���ṹ��record���洢������Ԫ��:����(�ַ���)��ʱ��(���³�������)��on/off(1/0)
2.����������ģ����Ҳ�һ����ȫ�������,��ͬһ������������������ļ�¼,ѡ���һ���������������Ҷϵļ�¼��ѡ��ǰһ��
�����ȸ��ṹ�����鰴������ʱ�����������Ժ��ٴ���һ���˿ͽṹ�壬��Ա������������һ��ͨ��ʱ�䣬ͨ�����У������д洢pair<int,int>������͹Ҷϣ�
3.��ĿҪ�����󻰷�,����Ҫ������ã�����ʱ�����һ���˿ʹӿ�ʼ��������ʱ�䣬������ò�����
*/
struct record
{
    string name;
    int Time;
    int status;   // 1:on,0:off
    bool operator <(const record&a)const
    {
        if(name!=a.name)
            return name<a.name;        //�Ȱ�������������ͬһ���˵ļ�¼������һ��
        else
            return Time<a.Time;
    }
}r[1005];
map<string, priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > >mu; //����һ��map��map����һ�����ȶ��С�
int str2timeb(string s)   //���ط�����
{
    int mm,d,h,m;
    sscanf(s.c_str(),"%d:%d:%d:%d",&mm,&d,&h,&m);
    return d*24*60+h*60+m;
}
int toll[24];           //��λʱ��Ļ���
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
void print(int t1,int t2)   // ��ʾʱ��ĺ���
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
    sort(r,r+n);  // ����
    int on=0,off=0;
    string flagname = r[0].name;      // ��һ������
    int numc=0;       // �ڼ����˿�
    for(int i=0;i<n;i++)
    {
        if(flagname!=r[i].name||i==0)
        {
            mu[r[i].name]= q[numc++];
            flagname = r[i].name;
            on = 0;          //���������¿�ʼ��
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
            mu[flagname].push(make_pair(on,off));    //����������
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
                money = calmoney(it->second.top().first,it->second.top().second);  // �������
                print(it->second.top().first,it->second.top().second);  // ��ӡ���
                cout<<it->second.top().second-it->second.top().first<<" "<<"$"<<setiosflags(ios::fixed)<<setprecision(2)<<money<<endl;
                totalmoney +=money;
                it->second.pop();
            }
            cout<<"Total amount: $"<<setiosflags(ios::fixed)<<setprecision(2)<<totalmoney<<endl;
        }
    }
    return 0;
}
