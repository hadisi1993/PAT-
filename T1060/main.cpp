//这道题的思路就是比较*前后的两个部分，
#include"iostream"
#include"cstring"
using namespace std;
bool IsZero(string str)       //判断字符串是否为0
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!='0'&&str[i]!='.')
        return false;
    }
    return true;
}
void change(string &str)   //将字符串化简
{
    int index;
    if(IsZero(str))
    {
        str="0";
        return ;
    }
    if(str.find('.')==string::npos)  //整数
    {
        for(int i=0;i<str.length();)
            if(str[i]=='0') i++;
            else
            {
                index=i;
               // cout<<index<<endl;;
                break;
            }
        str.erase(str.begin(),str.begin()+index);
       // cout<<str<<endl;
    }
    else
    {
        for(int i=0;i<str.length();)
            if(str[i]=='0'&&str[i+1]!='.') i++;
            else
            {
                index=i;
                break;
            }
        str.erase(str.begin(),str.begin()+index);
        for(int i=str.length()-1;i>=0;)
            if(str[i]=='0'&&str[i-1]!='.') i--;
            else
            {
                index=i;
                break;
            }
        str.erase(str.begin()+index+1,str.end());   //去除尾部
        if(str[str.length()-1]=='.') str.erase(str.end()-1);
    }
}
int Elen(string str)   //判断科学计数法指数的大小
{
    if(IsZero(str)) return 0;   //如果是0，则有效长度为0
    //处理字符串，使字符串简化
    if(str.find('.')==string::npos)  //整数
        return str.length();
    else
    {
       int num=0;
       if(str[0]=='0')
       {

           for(int i=2;i<str.length();i++)
            if(str[i]=='0') num++;
           return -1*num;
       }
       else
           return str.find('.');
    }

}
void Scichange(string&str,int digit)   //化为科学计数法的表示
{
     if(str.find('.')!=string::npos)//整数不用处理，只要处理小数
     {
        if(str[0]!='0')
        {
            int index=str.find('.');
            str.erase(str.begin()+index);
        }
        else
        {
            int index;
            int len=str.length();
            for(int i=2;i<str.length();i++)
            if(str[i]!='0')
            {
                index=i;
                break;
            }
            str=str.substr(index,len-index+1);
        }
     }
    while(str.length()<digit) str+="0";   //补齐
    str=str.substr(0,digit);
    str="0."+str+"*10^";
}
int main()
{
    string str1;
    string str2;
    int digit;
    cin>>digit>>str1>>str2;
    change(str1);
    change(str2);    //规范化
    int index1=Elen(str1),index2=Elen(str2);
    Scichange(str1,digit);
    Scichange(str2,digit);
    if(index1==index2&&str1==str2)
        cout<<"YES"<<" "<<str1<<index1;
    else
        cout<<"NO"<<" "<<str1<<index1<<" "<<str2<<index2;
    return 0;
}
