#include<iostream>
#include<string>
using namespace std;
/*最大回文字串,看了书上提示做的
这道题肯定要用动态规划做
这道动态规划题，先遍历长度，再遍历位置
动态规划方程:
dp[j][j+i-1]=dp[j+1][j+i-2]==1&&str[j]==str[j+i-1]?1:0(长度1和长度2特殊处理)
*/
int dp[1005][1005];  // 状态转移方程
int main()
{
    string str;
    getline(cin,str);
    int len = str.length();  // 字符串长度
    int maxlen = -1;
    for(int i=1;i<=len;i++)
    {
        for(int j=0;j+i<=len;j++)   // j为起始位置
        {
            if(i>2) // 回文串长度在2以上
            {
                if(str[j]==str[j+i-1]&&dp[j+1][j+i-2])
                {
                    dp[j][j+i-1]=1;
                    maxlen = i;
                }
                else
                    dp[j][j+i-1]=0;
            }
            else
            {
                if(str[j]==str[j+i-1])
                {
                    dp[j][j+i-1]=1;
                    maxlen = i;
                }
                else
                    dp[j][j+i-1]=0;
            }
        }
    }
    cout<<maxlen<<endl;
    return 0;
}
