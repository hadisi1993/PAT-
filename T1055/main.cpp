#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
//这道题处理字符串有点费力，应尝试更通用的办法
struct richman
{
    char name[80];
    int age;   // 年纪
    int money;
    bool operator <(const richman&a)const
    {
        if(money!=a.money)
            return money>a.money;
        else
        {
            if(age!=a.age)
                return age<a.age;
            else
            {
                if(strcmp(name,a.name)<0)
                    return 1;
                else return 0;
            }
        }
    }
}rm[100005];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        scanf("%s %d %d",rm[i].name,&rm[i].age,&rm[i].money);
       // cin>>rm[i].name>>rm[i].age>>rm[i].money;
    sort(rm,rm+n);     // 排序
    int c,s,e;
    for(int i=0;i<k;i++)
    {
        cin>>c>>s>>e;
        printf("Case #%d:\n",i+1);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(rm[i].age>=s&&rm[i].age<=e)
            {
                printf("%s %d %d\n",rm[i].name,rm[i].age,rm[i].money);
                cnt++;
            }
            if(cnt==c)
                break;
        }
        if(!cnt)
            cout<<"None"<<endl;
    }
    return 0;
}
