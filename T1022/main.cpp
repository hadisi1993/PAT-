#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;
/*������Ҵ�����multimap��������Է��֣��鼮�������е����Զ���digit�Ƕ��һ�Ĺ�ϵ
Ҫ���������
1.�ؼ����Ƿָ������ַ�����Ҫдһ���������ַ��ֿ�
2.�����ѯ����ʱ��Ҫע��,�����ַ���
��һ�ν�û��ȫ�ԣ��Ҿ��ÿ�������Ϊ��ֻ����һ��multimap������
�ٴ��ύ���ֻ��ǲ���,�ٴμ������������ʽ�����˴���
*/
void sock(string s,vector<string>&v,string c)           //�ַ����ָ��
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
    vector<string>kw;       //�ؼ���
    multimap<string, int>m[6];   // �ַ��������
    while(n--)             //���뺯��
    {
        cin>>id;
        string t;
        getline(cin,t);      //�Ե����з�
        getline(cin,title);  // �������
        m[0].insert(pair<string,int>(title,id));
        getline(cin,author);  // ��������
        m[1].insert(pair<string,int>(author,id));
        getline(cin,keywords);  // ����ؼ���
        getline(cin,publisher);  // ���뷢����
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

       // cout<<"��һ������"<<endl;
    }
    int q;
    cin>>q;
    string ques;   //�����ѯ��
    vector<int>v;
    for(int i=0;i<q;i++)
    {
        int order;  //�������
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
        sort(v.begin(),v.end());       //����
        for(int j=0;j<m[order-1].count(ques);j++)
            cout<<setw(7)<<setfill('0')<<v[j]<<endl;
    }
    return 0;
}
