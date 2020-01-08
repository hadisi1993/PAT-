#include<iostream>
#include<cstring>
#include<algorithm>
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
    string Sum = to_string(sum);
    len = Sum.length();
    for(int i=0;i<len;i++)
    {
        int j=Sum[i]-'0';
        cout<<(i==0?"":" ");
        cout<<num[j];
    }
    cout<<endl;
    return 0;
}
