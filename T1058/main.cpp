#include<iostream>
#include<algorithm>
using namespace std;
/*ºÚµ•Ã‚*/
int main()
{
    int s1,k1,g1,s2,k2,g2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    printf("%d.%d.%d",(g1+g2+(s1+s2+(k1+k2)/29)/17),(s1+s2+(k1+k2)/29)%17,(k1+k2)%29);
    return 0;
}
