/*������˼·��ʵ���ѣ�����ʱû�в���һ�ֺܺúܼ��ķ�����д�����,�ο������ϵĴ����Ժ���д*/
/*�µ�˼·��*/
#include<iostream>
#include<algorithm>
using namespace std;
int flag=0;
struct stu
{
    int id,best,course;   // ��λ��ѧ��,��õ�����,������������
    int score[4];  // ���ſεķ�����ע��������ƽ������ȡ����
}s[2005];
bool cmp(stu a,stu b)    //������д�����Է�������
{
    return a.score[flag]>b.score[flag];
}
char kw[] ={'A','C','M','E'};
int main()
{
    int n,t,id;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&s[i].id,&s[i].score[1],&s[i].score[2],&s[i].score[3]);
        s[i].score[0] = (s[i].score[1]+s[i].score[2]+s[i].score[3])/3;  // ����ƽ����
        s[i].best = 10000;
    }
    for(int i=0;i<t;i++)  // �����������
    {
        scanf("%d",&id);
        int index=-1;
        for(flag =0;flag<4;flag++)
        {
            sort(s,s+n,cmp);
            for(int j=0;j<n;j++)
            {
                if(id==s[j].id)
                {
                    if(j+1<s[j].best)
                    {
                        s[j].best = j+1;
                        s[j].course = flag;
                    }
                    index =j;   //��λ
                }
            }
        }
        if(index>=0)
            printf("%d %c\n",s[index].best,kw[s[index].course]);
        else
            printf("N/A\n");
    }
}
