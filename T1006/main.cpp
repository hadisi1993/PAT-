/*这道题不是很难，主要思想就是使用结构体，然后对结构体进行排序*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct User{
    string ID;
    string sign_in_time;
    string sign_out_time;
}user[100005];
bool cmp1(User x,User y)
{
    return x.sign_in_time<y.sign_in_time;
}
bool cmp2(User x,User y)
{
    return x.sign_out_time>y.sign_out_time;
}
int main()
{
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>user[i].ID>>user[i].sign_in_time>>user[i].sign_out_time;
    }
    string ID1,ID2;
    sort(user,user+m,cmp1);
    ID1 = user[0].ID;
    sort(user,user+m,cmp2);
    ID2 = user[0].ID;
    cout<<ID1<<" "<<ID2<<endl;
    return 0;
}
