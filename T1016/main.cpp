#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
/*这是一道模拟题，非常复杂，首先我们要把思路理清楚
1.输入包括，每个时间段的话费和一系列序列，每个序列包括三个元素:通话人,时间(月,日,时,分)，打出还是挂断
2.序列是无序的，而且不一定完全内配对上,当同一个人连续有两个打出的记录,选择后一个，连续有两个挂断的记录，选择前一个
3.题目要求是求话费
思路:
1. 分别设立两个结构体，一个用来记录通话记录，另一个用来记录顾客
2.
*/
int toll[24];           //单位时间的话费
typedef char* Str;  // 为了便于计算重定义字符串
struct Record
{
    Str t;        //时间
    int tp;            //类型，online用1表示,off-line用0表示
};
struct Customer
{
    Str Name;
    int recordnum;           //记录数目
    Record r[1000];        //记录
    int sumtime;           //总的时间
    float TotalAmount;  // 总花费
    bool cmp(Record a,Record b)     //比较函数
    {
        return strcmp(a.t,b.t);
    }
    void timesort()    //排序函数,排序时间
    {
        sort(r,r+recordnum,cmp);
    }
    void cal()//计算话费的函数
    {
        int i = 0;
        while(i+1<recordnum)
        {
            if(r[i].tp)
        }
    }
};
int main()
{

    return 0;
}
