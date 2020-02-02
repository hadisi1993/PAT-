#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn =1e5+5;
struct student
{
    string ID;
    string name;
    int score;
}s[maxn];
bool cmp1(student x,student y)
{
    return x.ID<y.ID;
}
bool cmp2(student x,student y)
{
    if(x.name==y.name)
        return x.ID<y.ID;
    return x.name<y.name;
}
bool cmp3(student x,student y)
{
    if(x.score==y.score)
       return x.ID<y.ID;
    return x.score<y.score;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].ID>>s[i].name>>s[i].score;
    }
    switch(m)
    {
        case 1:
            {
                sort(s,s+n,cmp1);
                break;
            }
        case 2:
            {
                sort(s,s+n,cmp2);
                break;
            }
        case 3:
            {
                sort(s,s+n,cmp3);
                break;
            }
    }
    for(int i=0;i<n;i++)
        cout<<s[i].ID<<" "<<s[i].name<<" "<<s[i].score<<endl;
    return 0;
}
