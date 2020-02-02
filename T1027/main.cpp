#include<iostream>
#include<string.h>
using namespace std;
char r[]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
char s1[2],s2[2],s3[2];
void ntos(int x)
{
    char a,b;
    a=x<12?r[0]:r[x/13];
    b= r[x%13];
    printf("%c%c",a,b);
}
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("#");
    ntos(a);
    ntos(b);
    ntos(c);
    return 0;
}
