#include<iostream>
#include<algorithm>
#include<string>
#include<map>
/*这道题看上去像一个求总数的问题
解题思路:将所有的数输入容器内，按照出现的次数，筛选出出现次数最多的数
*/
using namespace std;
int main()
{
    map<string,int>mt;
    int m,n;
    cin>>m>>n;
    int i=0;
    string str;
    while(i<m*n)
    {
        cin>>str;
        mt[str]++;
        i++;
    }
    map<string,int>::iterator it;
    int maxn = 0;
    for(it=mt.begin();it!=mt.end();it++)
    {
        if(it->second>maxn)
        {
            maxn = it->second;
            str = it->first;
        }
    }
    cout<<str<<endl;
    return 0;
}
