#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
    if(n==1)
        return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int calrd(int n,int d)   //计算rd的函数
{
    int res=0;
    while(n>0)
    {
        int r = n%d;
        n = n/d;
        res =res*d+r;
    }
    return res;
}
int main()
{
    int n,d;
    while(cin>>n&&n>0)
    {
        cin>>d;
        int rd;
        rd = calrd(n,d);
        cout<<(isPrime(n)&&isPrime(rd)?"Yes":"No")<<endl;
    }
    return 0;
}
