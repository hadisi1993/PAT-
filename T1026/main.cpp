#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
/*��������ǰ������1014��1017����񣬶���ģ���⣬����Ҫ���Ӹ���һ�㣬��Ϊ����һ��VIP��
�����ڱ���ƹ��������ʱ��1.Ҫ��ƹ�������ǲ���VIP��2.Ҫ����������û��VIP�ͻ�
��Ŀ�����̴�������
1.������������������ǲ��ǿյģ��пյ�
    1.1 ��VIP�������Ƚϵ�ǰʱ��͵�һ���ȴ���Ա�ĵ���ʱ�䣬�����������
    1.2 VIP���������Ҷ������Ƿ���VIP��Ա���еĻ��Ƚϵ�ǰʱ����䵽��ʱ�䣬����������䣬�����ڷ�VIP��Ա��
    ����
2.������ǿյ������ʱ��-1
3.��ǰʱ��+1
����ؼ�:VIP��Ա�ͷ�VIP��Ա��δ洢
�ҵ��뷨��:������Ա��һ������洢��VIP��Ա����һ�����ȶ��д洢������Ա��ַ����Ա�ṹ������һ������
�����Ա�Ƿ񱻷��������������������Աʱ���������Ѿ��������VIP��Ա
*/
using namespace std;
int cutime =0; // ��ǰʱ��
struct baller*
{
    int atime; // ����ʱ��
    int ptime; // �˶�ʱ��
    int vip; //�ǲ���vip
    int flag; // �Ƿ��Ѿ�������
    int stime; // ��ʼ�����ʱ��
    bool operator <(const baller*&b)const
    {
        return b->atime<time;
    }
}b[10005];
struct table
{
    int remain;
    int vip; // �ǲ���vip��
    int sev; // ���������
    table()
    {
        remain = 0;
        vip=0;
    }
}Table[200];
int waittime[10005];
int str2time(char*s)
{
    int h,m,s;
    sscanf(s,"%d:%d:%d",&h,&m,&s);
    return 3600*h+60*m+s;
}
void print(int t1,int t2)  // ʱ���תʱ��
{
    int h,m,s;
    h = t1/3600;
    m = (t1-3600*h)/60;
    s = t1%60;
    printf("%02d:%02d:%02d ",h,m,s);
    h = t2/3600;
    m = (t2-3600*h)/60;
    s = t12%60;
    printf("%02d:%02d:%02d %d\n",h,m,s,round((t2-t1)/60));
}
struct cmp{
    bool operator ()(baller*x,baller*y)
    {
        return x->atime<y.time;
    }
};
priority_queue<baller*,vector<baller*>,cmp>Q;  // VIP�û�
int main()
{
    char str[20];
    int t,v; // ����ʱ����ǲ���vip
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d",str,&t,&v);
        b[i]->atime = cal(str);
        b[i]->ptime = cal(t);
        b[i]->vip = v;
        if(v)
        {
            Q.push(b[i]);
        }
    }
    sort(b,b+n);
    int cnt,vcnt; // ��������vip������
    scanf("%d %d",&cnt,&vcnt);
    int w;
    for(int i=0;i<vcnt;i++)
    {
        scanf("%d",&w);
        Table[w].vip = 1;
    }
    cutime = 8*3600;
    int ab = 0;  // �������˵���
    while(Cutime<17*3600)
    {
        for(int i=0;i<cnt;i++)
        {
            if(Table[i].remain==0&&ab<n)  //��̨û���ˣ�������Ҫ����
            {
                 if(Table[i].vip&&Q.size()>0)    //����������vip��,����vip�ͻ�
                {
                    baller*tmp = Q.top();
                    if(tmp->atime<Cutime)
                    {
                        Table[i].remain = tmp->ptime;
                        Table[i].sev +=1;
                        tmp->flag=1;  // ȥ����
                        Q.pop();   //�ӵȴ�������ɾ��
                    }
                    else                //vip���˻�
                    {
                        while(b[ab]->flag)   // �Ѿ��������vip
                            ab++;
                        if(b[ab]->atime<Cutime)  // �����ǰʱ����ڵȴ�ʱ��
                        {
                            Table[i].remain = b[ab]->ptime;
                            Table[i].sev+=1;
                            b[ab]->wtime =Cutime;
                            ab++;
                        }

                    }
                }
                else
                {
                    while(b[ab]->flag)   // �Ѿ��������vip
                        ab++;
                    if(b[ab]->atime<Cutime)  // �����ǰʱ����ڵȴ�ʱ��
                    {
                        Table[i].remain = b[ab]->ptime;
                        b[ab]->wtime =Cutime;
                        ab++;
                    }
                }
            }

        }
        Cutime++;
    }
    for(int i=0;i<n;i++)
    {
        if(b[i].stime)
            printf("%02d:%02d:%02d %02d:%02d:%02d %d",,,,,);
    }
    for(int i=0;i<cnt;i++)
    {
        if(i) printf(" ");
        printf("%d",Table[i].sev);
    }

    return 0;
}
