#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
    string num[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string number;
    cin>>number;
    int sum=0;
    int len = number.length();
    for(int i=0;i<len;i++)
        sum+=number[i]-'0';
    stack<int>s;
    if(!sum)
    {
        cout<<num[0]<<endl;
        return 0;
    }
    while(sum)
    {
        s.push(sum%10);
        sum/=10;
    }
    while(!s.empty())
    {
        int i = s.top();
        cout<<num[i];
        if(s.size()>1) cout<<" ";
        s.pop();
    }
    return 0;
}
