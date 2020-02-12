#include <iostream>
#include<string>
using namespace std;
/*给字符串做减法,可能要注意时间的问题,关键在于字符串查找和字符串删除函数的运用*/
int main()
{
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    for(int i=0;i<str2.length();i++)
    {
        int pos = str1.find(str2[i]);
        while(pos!=string::npos)
        {
            str1.erase(pos,1);      //删除字符串
            pos = str1.find(str2[i]);
        }
    }
    cout<<str1<<endl;
    return 0;
}
