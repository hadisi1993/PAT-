//这道题目其实没什么可讲的，因为它接人是一个一个接的，不存在时间最优化的问题
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int pos = 0; //电梯所在的位置
    int time = 0;
    for(int i=0;i<n;i++)
    {
        int loc;  //要求在的位置
        cin>>loc;
        time+=loc>pos?6*(loc-pos):4*(pos-loc);
        pos = loc; //更新电梯位置
    }
    time+=5*n;
    cout<<time<<endl;
    return 0;
}
