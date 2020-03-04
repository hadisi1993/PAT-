#include <iostream>
using namespace std;
int coins[1005];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int value;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        coins[value]++;
    }
    for(int i=1;i<=m/2;i++)
    {
        if(i*2==m)
        {
            if(coins[i]>=2)
            {
                printf("%d %d",m/2,m/2);
                return 0;
            }

        }
        else if(coins[i]&&coins[m-i])
        {
            printf("%d %d",i,m-i);
            return 0;
        }

    }
    printf("No Solution");
    return 0;
}
