#include<iostream>
#include<algorithm>
using namespace std;
/*������֮ǰ����������񣬲�֮ͬ��������Ҫ����ƽ���ȴ�ʱ�䣬���Ҵ���ֻ��һ���ˣ����Բ���Ҫ����
1.�����˿���ṹ�壬���õ���ʱ�䣬ҵ����ʱ��ͱȽ������;��һ�����鱣�洰�ڴ���ǰ�˿�ҵ���ʣ��ʱ��
2.ͳ��17:00ǰ���Ĺ˿͵�����
2. ��8:00��ʼ����ʱ����������ȱ��������Ƿ����ˣ����û���ˣ��Ƚϵ�ǰʱ�����һ���˿͵ĵ���ʱ�䣬������ڸù˿��ҵ�ǰ
ʱ����ڵ��ڸ�ʱ�䣬���Ÿù˿ͽ��봰�ڣ����˿͵�ҵ����ʱ�丳���������飻��������ˣ��򴰿�ʣ��ʱ��-1��
3.����������17:00���Ĺ˿�ҵ�������Ϊֹ
ע�⣺��Ҫһ����������ʱ��ת��Ϊ���������Խ���ʱ���00:00:00֮���������Ϊʱ�䱣��

���������һ���ⲻͬ�ĵط����ڣ�ֻҪ����������(������5:00֮ǰ)���Ϳ��Ա�������
*/
int W[105];    //��������ÿ������ʣ���ҵ��ʱ��
struct Customer
{
    int arrtime; //����ʱ��
    int protime; //ҵ����ʱ��
    bool operator<(const Customer&a)const
    {
        return arrtime<a.arrtime;
    }
}C[10005];
int calsec(char*str)  // ����ʱ����
{
    int h,m,s;
    sscanf(str,"%d:%d:%d",&h,&m,&s);
    return h*3600+m*60+s;
}
int main()
{
    float totalwaittime=0;   // �ܵĵȴ�ʱ��
    int n,k;
    scanf("%d %d",&n,&k);
    int numc=0;  //���������
    char str[20];
    int ptime;
    for(int i=0;i<n;i++)
    {
        scanf("%s %d",str,&ptime);
        C[i].arrtime = calsec(str);
        C[i].protime = ptime*60;
    }
    sort(C,C+n);       //���յ���ʱ���С������������
    int ab=0;           //17:00��ǰ�Ŀ��Ա��������Ⱥ
    for(int i=0;i<n;i++)
        if(C[i].arrtime<=17*3600)
            ab++;
    int Current = 8*3600;    // ��ǰʱ�䣬��8:00��ʼ����
    while(numc<ab)                 //�Ƿ����иñ�������˶���������
    {
        for(int i=0;i<k;i++)
        {
            if(W[i])
                W[i]-=1;                           //������ˣ������һ����
            else
            {
                if(Current>=C[numc].arrtime&&numc<ab)    //�ڱ��������У�����numc�п��ܵ���ab�����Ի���Ҫд��
                {
                    W[i] = C[numc].protime-1;       // ������,ͬʱ����һ����
                    totalwaittime +=Current-C[numc].arrtime;
                    numc++;
                }

            }
        }
        Current+=1;        // ��ǰʱ���1
    }
    if(ab==0)         //����5:00֮ǰû���˵�������ƽ���ȴ�ʱ�伴Ϊ0
        printf("0.0");
    else
        printf("%.1f",(totalwaittime/ab)/60.0);
    return 0;
}
