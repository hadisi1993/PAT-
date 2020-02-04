#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;
/*这道题我打算用multimap解决，可以发现，书籍里面所有的属性都和digit是多对一的关系
要解决的问题
1.关键字是分隔开的字符串，要写一个函数把字符分开
2.输入查询语句的时候要注意,处理字符串
第一次交没有全对，我觉得可能是因为我只用了一个multimap的容器
再次提交后发现还是不对,再次检查后发现是输出格式出现了错误
*/
void sock(string s,vector<string>&v,string c)           //字符串分割函数
{
    int pos1 = s.find(c);
    int pos2 = 0;
    while(string::npos!=pos1)
    {
        //cout<<pos1<<endl;
        string s1 = s.substr(pos2,pos1-pos2);
        v.push_back(s1);
        pos2=pos1+c.size();
        pos1 = s.find(c,pos2);
    }
    if(pos2!=s.length())
        v.push_back(s.substr(pos2));
  // cout<<"the number of keywords:"<<v.size()<<endl;
}
int main()
{
    int id;
    string year;
    string title;
    string keywords;
    string author;
    string publisher;
    int n;
    cin>>n;
    vector<string>kw;       //关键词
    multimap<string, int>m[6];   // 字符串和序号
    while(n--)             //输入函数
    {
        cin>>id;
        string t;
        getline(cin,t);      //吃掉换行符
        getline(cin,title);  // 输入标题
        m[0].insert(pair<string,int>(title,id));
        getline(cin,author);  // 输入作者
        m[1].insert(pair<string,int>(author,id));
        getline(cin,keywords);  // 输入关键词
        getline(cin,publisher);  // 输入发行商
        m[3].insert(pair<string,int>(publisher,id));
        getline(cin,year);
        m[4].insert(pair<string,int>(year,id));
        while(kw.size()!=0)
            kw.pop_back();
   //     cout<<id<<"   "<<author<<"   "<<title<<kw.size()<<"    "<<keywords<<endl;
        sock(keywords,kw," ");
        for(int i=0;i<kw.size();i++)
        {
           // cout<<i<<endl;
            m[2].insert(pair<string,int>(kw[i],id));
        }

       // cout<<"第一个输完"<<endl;
    }
    int q;
    cin>>q;
    string ques;   //输入查询项
    vector<int>v;
    for(int i=0;i<q;i++)
    {
        int order;  //问题序号
        cin>>order;
        getline(cin,ques);
        int len=ques.length();
        ques = ques.substr(2,len-2);
        cout<<order<<": "<<ques<<endl;
        multimap<string,int>::iterator mu;
        mu=m[order-1].find(ques);
        if(m[order-1].count(ques)==0)
            cout<<"Not Found"<<endl;
        while(v.size()!=0)
            v.pop_back();
        for(int j=0;j<m[order-1].count(ques);j++,mu++)
            v.push_back(mu->second);
        sort(v.begin(),v.end());       //排序
        for(int j=0;j<m[order-1].count(ques);j++)
            cout<<setw(7)<<setfill('0')<<v[j]<<endl;
    }
    return 0;
}
