#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
const int maxn = 1e5+5;
/*这道题还是讲的栈的运用，在普通栈的功能上，这道题还增加了一个功能，
要求输出栈中元素的中位数
这道题我尝试用V1ector数组来模拟栈,结果做下来运行超时
学习了新的算法以后，决定用分块的思想重新做这道题
这道题的数据不超过100000，sqrt(100000)=316.23,则分317块，每块代表316个数字
1.用一个block数组记录每个块包含的元素数
2.用table数组记录每个元素的数量
3.这道题的关键就是如何更新block和table数组
1. push:假设加入数是x,x属于block[x/316]这个块中，block[x/316]+=1,table[x]+=1;
2. pop:栈顶数为x，block[x/316]-=1,table[x]-=1;
3. peekMedian:查找第(N/2)的元素或者((N+1)/2)的元素
使用分块做了以后，答案依旧超时
修改了pmd函数的写法，发现用栈作为参数会大大提升运行时间，修改后不超时，但答案错误
*/
stack<int>S;
int block[320];
int table[maxn];
void pmd()
{
    if(S.empty())
    {
        printf("Invalid\n");
        return ;
    }
    else    // 查找中位数
    {
        int cnt = S.size();
        int m = cnt%2?(cnt+1)/2:cnt/2;
        //printf("m:%d\n",m);
        int sum =0;
        int num=0;
        while(sum+block[num]<m)
        {
            sum+=block[num];
            num++;
        }
        num = num*316+1;
        while(sum+table[num]<m)
        {
            sum+=table[num];
            num++;
        }
        printf("%d\n",num);
    }
}
int main()
{
    char str[20];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        if(str[1]=='o')
        {
            if(S.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                int v = S.top();
                table[v]--;
                block[(v-1)/316]--;
                printf("%d\n",v);
                S.pop();
            }

        }
        else if(str[1]=='u')
        {
            int v;
            scanf("%d",&v);
            S.push(v);
            table[v]++;
            block[(v-1)/316]+=1;
        }
        else
        {
            pmd();
        }
    }
    return 0;
}

