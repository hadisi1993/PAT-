#include<iostream>
#include<string>
using namespace std;
char str[][5] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
    string str1,str2,str3,str4;
    cin>>str1>>str2>>str3>>str4;
    int cnt = 0;
    for(int i=0;i<str1.length()&&i<str2.length();i++)
    {
        if(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G'&&!cnt)
        {
            printf("%s ",str[(str1[i]-'A')]);
            cnt++;
        }
        else if(str1[i]==str2[i]&&cnt)
        {
            if(str1[i]>='A'&&str1[i]<='N')
            {
                printf("%02d:",(str1[i]-'A')+10);
                break;
            }
            else if(str1[i]>='0'&&str1[i]<='9')
            {
                printf("%02d:",str1[i]-'0');
                break;
            }
        }
    }
    for(int i=0;i<str3.length()&&i<str4.length();i++)
    {
        if(str4[i]==str3[i]&&((str3[i]>='A'&&str3[i]<='Z')||(str3[i]>='a'&&str3[i]<='z')))
        {
            printf("%02d\n",i);
            break;
        }
    }
    return 0;
}
