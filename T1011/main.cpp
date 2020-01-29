#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    float a,b,c;
    char C[3];
    float result=1;
    for(int i=0;i<3;i++)
    {
        cin>>a>>b>>c;
        float tmp=max(max(a,b),c);
        C[i]=tmp==max(a,b)?(tmp==a?'W':'T'):'L';
        result*=tmp;
    }
    printf("%c %c %c ",C[0],C[1],C[2]);
    printf("%.2f",(result*0.65-1)*2);
    return 0;
}
