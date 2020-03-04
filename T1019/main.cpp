#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
LL num[10];
int digit;
bool ispali(LL n,LL b)
{
    int i;
    for(i=0;n>0;i++,n/=b)    //因为是判断回文，所以正着来反着来都可以
    {
        num[i] = n%b;
    }
    digit=i-1;
    for(i=0;i<=digit-i;i++)
    {
        if(num[i]!=num[digit-i])
            return false;
    }
    return true;
}
int main()
{
    LL n,b;
    cin>>n>>b;
    cout<<(ispail(n,b)?"Yes":"No")<<endl;
    cout<<num[digit];
    for(int i=digit-1;i>=0;i--)
        cout<<" "<<num[i];
    return 0;
}
