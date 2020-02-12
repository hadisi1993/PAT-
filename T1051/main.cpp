#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
/*这道题有点说不清楚是什么类型的，感觉是一道和栈相关的模拟题
题意很简单，给你一个出栈序列，判断这个出栈序列是否存在
解题思路:由出栈序列推测出栈情况，会出现这么几种情况
1.栈顶元素为空，则把小于等于当前元素所有元素压入栈中(不含以前出过栈的)，这些元素必须入栈，当前元素才能
出栈，然后当前元素出栈,所有入过栈的元素标记
2.当前元素大于栈顶元素，这种情况和第一种情况基本相同，但压栈从栈顶元素+1开始
3.当前元素等于栈顶元素，栈顶元素出栈
4.当前元素小于栈顶元素，这种情况就不行，这种情况代表栈顶元素还没有出栈，就有栈中比它小的元素出栈了*/
int vis[1005];   // 判断当前元素是否入过栈
int main()
{
    int m,n,k;
    stack<int>S;
    scanf("%d %d %d",&m,&n,&k);
    for(int i=0;i<k;i++)
    {
        while(!S.empty())
            S.pop();
        fill(vis+1,vis+n+1,0);
        int flag = 1;  // 判断可不可行
        int cur; // 当前输入的数
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cur);
            if(S.empty())      // 当前栈为空
            {
                for(int l=1;l<=cur;l++)
                {
                    if(!vis[l])
                    {
                        vis[l] =1;
                        S.push(l);
                    }
                }
                if(S.size()>m)
                    flag =0;
                S.pop();   // 弹出当前元素
            }
            else if(S.top()<cur)
            {
                for(int l =S.top()+1;l<=cur;l++)
                {
                    if(!vis[l])
                    {
                        vis[l] =1;
                        S.push(l);
                    }
                }
                if(S.size()>m)
                    flag = 0;
                S.pop();
            }
            else if(S.top()==cur)
                S.pop();
            else if(S.top()>cur)
                flag = 0;
        }
       // printf("1\n");
        printf("%s\n",flag?"YES":"NO");

    }
    return 0;
}
