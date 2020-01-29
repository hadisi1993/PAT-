#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    if(n==1)
        return false;
    return true;
}
int calrd(int n,int d)   //¼ÆËãrdµÄº¯Êý
{
    int res=0;
    while(n>0)
    {
        int r = n%d;
        n = n/d;
        res =res*d+r;
    }
  //  printf("%d\n",res);
    return res;
}
int main()
{
    int n,d;
    while(cin>>n)
    {
        if(n<0)
            break;
        else
        {
            cin>>d;
            int rd;
            rd = calrd(n,d);
            if(isPrime(n)&&isPrime(rd))
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
