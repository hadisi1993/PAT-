#include<iostream>
#include<cmath>
/*���������ܼ򵥣�ʵ�ʴ�������ȴ���鷳,�ǵ����𣿿��ǵ���û�취������ô�������
��������һ�룬���ǵ��ƣ�����Ҫ��һ��˼·*/
using namespace std;
typedef long long LL;
LL dp[15];
int main()
{
    dp[1]=1;
    for(int i=2;i<=9;i++)
    {
        dp[i]=pow(10,i-1)+10*dp[i-1];
    }
    for
    LL n;
    cin>>n;

    return 0;
}
