#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
/*����һ��ģ���⣬�ǳ����ӣ���������Ҫ��˼·�����
1.���������ÿ��ʱ��εĻ��Ѻ�һϵ�����У�ÿ�����а�������Ԫ��:ͨ����,ʱ��(��,��,ʱ,��)��������ǹҶ�
2.����������ģ����Ҳ�һ����ȫ�������,��ͬһ������������������ļ�¼,ѡ���һ���������������Ҷϵļ�¼��ѡ��ǰһ��
3.��ĿҪ�����󻰷�
˼·:
1. �ֱ����������ṹ�壬һ��������¼ͨ����¼����һ��������¼�˿�
2.
*/
int toll[24];           //��λʱ��Ļ���
typedef char* Str;  // Ϊ�˱��ڼ����ض����ַ���
struct Record
{
    Str t;        //ʱ��
    int tp;            //���ͣ�online��1��ʾ,off-line��0��ʾ
};
struct Customer
{
    Str Name;
    int recordnum;           //��¼��Ŀ
    Record r[1000];        //��¼
    int sumtime;           //�ܵ�ʱ��
    float TotalAmount;  // �ܻ���
    bool cmp(Record a,Record b)     //�ȽϺ���
    {
        return strcmp(a.t,b.t);
    }
    void timesort()    //������,����ʱ��
    {
        sort(r,r+recordnum,cmp);
    }
    void cal()//���㻰�ѵĺ���
    {
        int i = 0;
        while(i+1<recordnum)
        {
            if(r[i].tp)
        }
    }
};
int main()
{

    return 0;
}
