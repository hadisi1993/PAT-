#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*我觉得这道题是一道排序题,
排序的方法
1.从两个数的第一个数开始，依次向后比较大小
2.如果依次比较过后，一个数已经到了尾部，则返回头部，重新开始比较
3.如果两个数都到达尾部还没有分出大小，则算两数相等

ps:这道题没有看清楚题，将非负数看作了正数，浪费了时间
*/
string num[10005];
bool cmp(string x,string y)     //比较函数
{
    int p1=0,p2=0;   // 指针
    int len1= x.length(),len2 = y.length();
    while(1)
    {
        if(x[p1]==y[p2])
        {
            if(p1==len1-1&&p2==len2-1)  // 双方同时到头
                return x[p1]<y[p2];
            else if(p1==len1-1&&p2!=len2-1)
            {
                p2++;
                p1 = 0;
            }
            else if(p2==len2-1&&p1!=len1-1)
            {
                p1++;
                p2 = 0;
            }
            else
                p1++,p2++;
        }
        else
            return x[p1]<y[p2];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort(num,num+n,cmp);
    int index=n;
    for(int i=0;i<n;i++)
    {
        if(stoi(num[i])>0)
        {
            index = i+1;
            cout<<stoi(num[i]);
            break;
        }

    }
    for(int i=index;i<n;i++)
        cout<<num[i];
    if(index==n)
        cout<<0<<endl;
    return 0;
}
