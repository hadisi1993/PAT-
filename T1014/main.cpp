#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/*�������һ��ģ���⣬�ܿ������ǵ�����
1.Ϊÿ����������һ���ͻ����У������д洢�������ڸô��ڵĹ˿͵���ţ���������һ�����飬�洢�˿͵İ���ʱ��
2.������Ӫʱ��(8:00~17:00),�ж�ÿ��ʱ���Ƿ��пմ��ڣ��еĻ����Ź˿ͣ����û�д��ڣ���ǰ���ڵ�ʣ��ʱ��-1
3.Ϊ�˽�Լʱ��,��������n*m��������ʣ�µģ�ʣ�µİ���ʱ�����

�����ܿӵ�һ��������������17:00ǰ���񣬷������ʱ�䳬��17:00����Ҳ����������
*/
struct Windows{
  queue<int>q;   //q��¼�������
  int remaintime=0;   //�迪ʼ�ĵȺ�ʱ��Ϊ0
}wd[25];
int tf[1005];      //���˽�������ʱ��
int ctd[1005];    //ÿ���˰�����ҵ���ʱ�䣬�����Ӽ�
int cutime=1;
int main()
{
    int n,m,k,Q;
    scanf("%d %d %d %d",&n,&m,&k,&Q);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&cutime);
        tf[i] = cutime;
    }
    int index;  // ��ѯ���
    int i =1;
    cutime=1;  //��ǰ������ʱ��
    for(int j=1;j<=m;j++)   //�ȷ�ǰ��n*m��
    {
        for(i=1;i<=n;i++)
        {
            if(i+(j-1)*n<=k)
            {
                if(j==1)
                    wd[i].remaintime=tf[i];
                wd[i].q.push(i+(j-1)*n);
            }
        }
    }
    i = n*m+1;  //�������û�ŶӵĹ˿��Ǿʹ�n*m+1����ʼ
    while(cutime<=600)     //��ǰʱ�䣬��������10��Сʱ�ڷ�����Խ���
    {
        for(int j=1;j<=n;j++)
        {
            if(wd[j].remaintime>0)
            {
                wd[j].remaintime-=1;              //һ���ӹ�ȥ��
                if(wd[j].remaintime==0)
                {
                    index = wd[j].q.front();   //������Ĺ˿�
                    ctd[index] = cutime;
                    wd[j].q.pop();
                    if(i<=k)
                    {
                        wd[j].q.push(i);      //    �����µĹ˿�
                        i++;                 //��һ���Ⱥ�Ĺ˿�
                    }
                    if(wd[j].q.size()>0&&cutime<540)        //17:00�Ժ��ٷ����µĹ˿Ͳ��ٲ���
                    {
                        index = wd[j].q.front();
                        wd[j].remaintime = tf[index];       //���´���ʱ��
                    }
                    else
                        wd[j].remaintime = 0;
                }
            }
        }
        cutime++;
    }
    for(i=0;i<Q;i++)
    {
        scanf("%d",&index);
        if(ctd[index])
            printf("%02d:%02d\n",8+ctd[index]/60,ctd[index]%60);
        else
            printf("Sorry\n");
    }
    return 0;
}
