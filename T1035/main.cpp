#include<iostream>
#include<string>
using namespace std;
/*Ҫ�����������⣬���뵽��������
1. �������ݣ�name��pwd(string),ͳ����Ҫ�޸ĵ����룬�������Ҫ�޸ľ�ֱ���������Ҫ�޸����ڽṹ�嵱�б��
2. ��������Ժ���еڶ���ͳ�ƣ�����Ǳ���ǹ��ã�������޸Ĺ���Ľ��*/
struct user
{
    string name;
    string pwd;
    int flag;
    user()
    {
        flag = 0;
    }
}U[1005];
void Rlace(struct user&a)
{
    //cout<<a.name<<"   "<<a.pwd<<endl;
    int pos =a.pwd.find("1");
   // cout<<pos<<endl;
    while(pos!=string::npos)
    {
        a.pwd = a.pwd.replace(pos,1,"@");
        //cout<<a.pwd<<endl;
        pos = a.pwd.find("1",pos+1);
        a.flag = 1;
    }
    pos =a.pwd.find("0");
    while(pos!=string::npos)
    {
        a.pwd = a.pwd.replace(pos,1,"%");
        pos = a.pwd.find("0",pos+1);
        a.flag = 1;
    }
    pos =a.pwd.find("l");
    while(pos!=string::npos)
    {
        a.pwd = a.pwd.replace(pos,1,"L");
        pos = a.pwd.find("l",pos+1);
        a.flag = 1;
    }
    pos =a.pwd.find("O");
    while(pos!=string::npos)
    {
        a.pwd = a.pwd.replace(pos,1,"o");
        pos = a.pwd.find("O",pos+1);
        a.flag = 1;
    }
}
int main()
{
    int n;
    cin>>n;
    int cnt=0;   // ��Ҫ�޸ĵ��˵�����
    for(int i=0;i<n;i++)
    {
        cin>>U[i].name>>U[i].pwd;
        Rlace(U[i]);
        if(U[i].flag)
            cnt++;
    }
    if(!cnt)
    {
        if(n==1)
            cout<<"There is 1 account and no account is modified"<<endl;
        else
            cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    }
    else
    {
        cout<<cnt<<endl;
        for(int i=0;i<n;i++)
        {
            if(U[i].flag)
                cout<<U[i].name<<" "<<U[i].pwd<<endl;
        }
    }
    return 0;
}
