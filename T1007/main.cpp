/*�����㷨�������е����������֮��
�㷨��˼���������ģ�
���������һ���Ǵ�һ��������ʼ�ģ����������ڼ���Ĺ�����ֻ����һ��������֮�ͣ����������֮��Ϊ�����ͽ������к͵�ǰ����ӣ�
����������ǰ�����кͣ��Ե�ǰ��Ϊ�������еĵ�һ��Ԫ��
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int INF = -9999999;
int MSS=INF;    //���������֮��
int main()
{
    int n,value;
    int SS=0;  //������֮��
    scanf("%d",&n);
    int s,e,S,E; //�����еĵ�һ���������һ����,��������еĵ�һ���������һ����
    int flag = 0;
    int first;  //��һ����
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(!i)
            first=value;
        if(value>=0)
            flag=1;
        if(SS<=0)
        {
            s = value,e=value;
            SS = value;
        }
        else
        {
            e = value;
            SS = SS+value;
        }
        if(SS>MSS)
        {
            MSS = SS;
            S = s,E = e;
        }
    }
    if(!flag)
        printf("0 %d %d\n",first,value);
    else
        printf("%d %d %d\n",MSS,S,E);
    return 0;
}
