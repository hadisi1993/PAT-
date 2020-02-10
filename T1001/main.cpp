#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstdio>
using namespace std;
//思路，现将数字转化为字符串，然后插入逗号
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    string s;
    stringstream ss;
    ss<<(a+b);
    ss>>s;
    //翻转字符串
    reverse(s.begin(),s.end());
    int len = s.length();
    for(int i=3;i<len;i+=3)
    {
        if(isdigit(s[i]))
        {
            s.insert(i,",");   //添加逗号
            len+=1;
            i+=1;
        }
    }
    //重新翻转回来
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}
