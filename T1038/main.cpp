#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*�Ҿ����������һ��������,
����ķ���
1.���������ĵ�һ������ʼ���������Ƚϴ�С
2.������αȽϹ���һ�����Ѿ�����β�����򷵻�ͷ�������¿�ʼ�Ƚ�
3.���������������β����û�зֳ���С�������������

ps:�����û�п�����⣬���Ǹ����������������˷���ʱ��
*/
string num[10005];
bool cmp(string x,string y)     //�ȽϺ���
{
    int p1=0,p2=0;   // ָ��
    int len1= x.length(),len2 = y.length();
    while(1)
    {
        if(x[p1]==y[p2])
        {
            if(p1==len1-1&&p2==len2-1)  // ˫��ͬʱ��ͷ
                return x[p1]<y[p2];
            else if(p1==len1-1&&p2!=len2-1)
            {
                p2++;
                p1 = 0;
            }
            else if(p2==len2-1&&p1!=len1-1)
            {
                p1++;
                p2 = 0;
            }
            else
                p1++,p2++;
        }
        else
            return x[p1]<y[p2];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort(num,num+n,cmp);
    int index=n;
    for(int i=0;i<n;i++)
    {
        if(stoi(num[i])>0)
        {
            index = i+1;
            cout<<stoi(num[i]);
            break;
        }

    }
    for(int i=index;i<n;i++)
        cout<<num[i];
    if(index==n)
        cout<<0<<endl;
    return 0;
}
