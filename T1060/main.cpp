//������˼·���ǱȽ�*ǰ����������֣�
#include"iostream"
#include"cstring"
using namespace std;
bool IsZero(string str)       //�ж��ַ����Ƿ�Ϊ0
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!='0'&&str[i]!='.')
        return false;
    }
    return true;
}
void change(string &str)   //���ַ�������
{
    int index;
    if(IsZero(str))
    {
        str="0";
        return ;
    }
    if(str.find('.')==string::npos)  //����
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
        str.erase(str.begin()+index+1,str.end());   //ȥ��β��
        if(str[str.length()-1]=='.') str.erase(str.end()-1);
    }
}
int Elen(string str)   //�жϿ�ѧ������ָ���Ĵ�С
{
    if(IsZero(str)) return 0;   //�����0������Ч����Ϊ0
    //�����ַ�����ʹ�ַ�����
    if(str.find('.')==string::npos)  //����
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
void Scichange(string&str,int digit)   //��Ϊ��ѧ�������ı�ʾ
{
     if(str.find('.')!=string::npos)//�������ô���ֻҪ����С��
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
    while(str.length()<digit) str+="0";   //����
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
    change(str2);    //�淶��
    int index1=Elen(str1),index2=Elen(str2);
    Scichange(str1,digit);
    Scichange(str2,digit);
    if(index1==index2&&str1==str2)
        cout<<"YES"<<" "<<str1<<index1;
    else
        cout<<"NO"<<" "<<str1<<index1<<" "<<str2<<index2;
    return 0;
}
