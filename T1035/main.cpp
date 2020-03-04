#include<iostream>
#include<string>
using namespace std;
/*要解决密码这道题，我想到的流程是
1. 输入数据，name和pwd(string),统计需要修改的密码，如果不需要修改就直接输出；需要修改则在结构体当中标记
2. 输入结束以后进行第二次统计，如果是被标记过得，则输出修改过后的结果*/
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
    int cnt=0;   // 需要修改的人的数量
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
