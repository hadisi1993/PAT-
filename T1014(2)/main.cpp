#include<iostream>
#include<queue>
using namespace std;
struct Windows
{
    int id;   // ��ǰid
    int cutime;  // ��ǰʱ��
    Windows()
    {
        cutime = 0;
    }
};
int tf[1005];      //���˽�������ʱ��
int ctd[1005];    //ÿ���˰�����ҵ���ʱ�䣬�����Ӽ�
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
