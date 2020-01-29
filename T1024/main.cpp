#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long LL;
/*这道题有两个需要注意的地方
1.给的数据太大，需要用字符串处理
2.如果给出的是回文数，那么直接输出该数和0步就可以了，还有一些要注意的是字符串函数的用法*/
bool ispail(string N)             // 判断是不是回文数的函数
{
    string r = N;
    reverse(r.begin(),r.end());
    if(r==N)
        return true;
    else
        return false;
}
string Stradd(string s1,string s2)    //字符串加法
{
    //因为是回文数，所以一定是维数相同的
    string ans="";
    int len = s1.length();
    int ram=0;
    for(int i=len-1;i>=0;i--)
    {
        int v1= s1[i]-'0';
        int v2= s2[i]-'0';
        ans = to_string((ram+v1+v2)%10)+ans;
        ram = (ram+v1+v2)/10;
       // cout<<ans<<endl;
    }
    if(ram!=0)
        ans=to_string(ram)+ans;
   // cout<<ans<<endl;
    return ans;
}
int main()
{
    string N;
    int K;
    cin>>N>>K;
    if(ispail(N))
    {
        cout<<N<<endl<<0<<endl;
        return 0;
    }
    int i;
    for(i=0;i<K;i++)
    {
        string tmp = N;
        reverse(N.begin(),N.end());
        N = Stradd(N,tmp);
        if(ispail(N))
        {
            cout<<N<<endl<<i+1<<endl;
            break;
        }
    }
    if(i==K)
        cout<<N<<endl<<K<<endl;
    return 0;
}
