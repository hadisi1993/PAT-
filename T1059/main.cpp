#include"cstdio"
#include"algorithm"
#include"cmath"
using namespace std;
const int maxn=1e6+5;
bool P[maxn];
int Prime[maxn],pNum=1;
struct factor
{
    int x;
    int cnt;
}F[100];
void Find_Prime()    //´ò±íÕÒËØÊı
{
    for(int i=2;i<maxn;i++)
    {
        if(P[i]==false)
        {
            Prime[pNum++]=i;
            for(int j=2*i;j<maxn;j+=i)
            {
                P[j]=true;
            }
        }
    }
}
int main()
{
    Find_Prime();
    long num;
    scanf("%ld",&num);
    if(num==1)
    {
        printf("1=1\n");
    }
    else
    {
       printf("%ld=",num);
       int fNum=0;
       for(int i=2;i<pNum;i++)
       {
         if(num%i==0)
         {
             F[fNum].cnt=0;
             F[fNum].x=i;
             while(num%i==0)
             {
                 F[fNum].cnt++;
                 num/=i;
             }
             fNum++;
         }
       }
        for(int i=0;i<fNum;i++)
        {
            if(F[i].cnt==1)
                printf("%d",F[i].x);
            else printf("%d^%d",F[i].x,F[i].cnt);
            if(i<fNum-1) printf("*");
        }
    }
    return 0;
}
