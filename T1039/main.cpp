#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*这道题应该用multimap容器解决*/
/*第一遍运行超时，考虑先输入char str[4],在将字符串转化为string类型*/
/*第一遍运行超时，考虑先输入char str[4],在将字符串转化为string类型*/
char name[4];
multimap<string,int>m;
vector<int>v;
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int index,stu;  // 课程代号，学生数
    for(int i=0;i<k;i++)
    {
        scanf("%d %d",&index,&stu);
        for(int j=0;j<stu;j++)
        {
            scanf("%s",name);
            m.insert(make_pair(string(name),index));
        }
    }
    for(int i=0;i<n;i++)
    {
        v.clear();
        scanf("%s",name);
        printf("%s %d",name,m.count(name));
        //cout<<name<<" "<<m.count(name);
        multimap<string,int>::iterator it=m.find(name);
        for(int j=0;j<m.count(string(name));it++,j++)
            v.push_back(it->second);
        sort(v.begin(),v.end());
        for(int j=0;j<v.size();j++)
            printf(" %d",v[j]);
        printf("\n");
         //   cout<<" "<<v[j];
        //cout<<endl;
    }
    return 0;
}
