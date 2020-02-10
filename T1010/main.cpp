#include<iostream>
#include<cmath>
#include<string>
#include<cctype>
using namespace std;
//这道题我一开始想的是通过求解方程组得解，但求解比较复杂，而且数学知识也不够，所以用遍历试一下
//大概试了一下，这道题可能出现的最大数用long long类型还是可以装下的，所以没必要开字符串用大数求解
//第一遍做下来只有十五分，将radix提高到100有19分，提高到1000分数不变
//如果基数超过35，就有超过用LL型表示的可能
//使用了unsigned long long,分数没有任何改变
//添加了一个判断条件，基数要从比当前所有出现的数大，分数变为21分
//用大数，分数没有任何变化
//结果这道题是要用二分法去做,根本没有想到
//这道题有两个关键问题，一个是二分法的上界到底是多少，还有就是最大的数是不是会超过LL的限制
//参考网上的代码和博客，经过大量提交后他们发现，用题目测试点给出的radix算出来的数，是不会溢出的
//那么这个问题就简单了，测试另一个基数时，如果溢出，就当作较大的数来处理
//二分法的上界是多少能，仔细分析可以得出，上界不能大于给出的已知的数
typedef long long LL;
int main()
{
    LL t1=0,t2=0;
    string str1,str2;
    int tag,radix;
    cin>>str1>>str2>>tag>>radix;        //输入两个字符串，tag和基数
    if(tag==2)         //如果tag==2，交换两个数(字符串)
    {
        string str;
        str = str1;
        str1 = str2;
        str2 = str;
    }
    //确定二分法的上下界
    LL index=0,low,high;
    int flag=0;  // 判断这个数是不是存在
    for(int i=0;i<str2.length();i++)
    {
        LL tmp = isdigit(str2[i])?str2[i]-'0':(str2[i]-'a'+10);
        index = max(index,tmp+1);
    }
    low = index;      //下界
   // printf("low:  %d\n",low);
    index = 0;
    for(int i=0;i<str1.length();i++)
    {
        index = index*radix+(isdigit(str1[i])?str1[i]-'0':(str1[i]-'a'+10));
        //printf("%d\n",index);
    }
    high = index+1;   // 上界
    t1 = index;
    LL mid = (low+high)/2;
    //printf("mid: %d",mid);
    while(low<=high)
    {
        t2 = 0;
        for(int i=0;i<str2.length();i++)
        {
            t2 = t2*mid+(isdigit(str2[i])?str2[i]-'0':(str2[i]-'a'+10));
          //  printf("t2:%d\n",t2);
            if(t2<0)
                break;
        }
        //printf("%d\n",t2);
        if(t2<0||t2>t1)
        {
            high = mid-1;
            mid = (high+low)/2;
            //printf("mid:  %d\n",mid);
        }
        else if(t2<t1)
        {
            low = mid+1;
            mid = (high+low)/2;
        }
        else if(t1==t2)
        {
            flag = 1;
            printf("%d\n",mid);
            return 0;
        }
    }
    if(!flag)
        printf("Impossible\n");     // 这个数不存在
    return 0;
}
