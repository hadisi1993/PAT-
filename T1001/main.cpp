#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstdio>
using namespace std;
//˼·���ֽ�����ת��Ϊ�ַ�����Ȼ����붺��
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    string s;
    stringstream ss;
    ss<<(a+b);
    ss>>s;
    //��ת�ַ���
    reverse(s.begin(),s.end());
    int len = s.length();
    for(int i=3;i<len;i+=3)
    {
        if(isdigit(s[i]))
        {
            s.insert(i,",");   //��Ӷ���
            len+=1;
            i+=1;
        }
    }
    //���·�ת����
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}
