/*��Ŀ����˼�ܼ򵥣�������һ����ÿһ��Ҷ�ӽڵ�ĸ���,�ؼ���������������ô����һ�������Լ���ô�����ڵ�
��Ϊ�����������������󣬶��Ҷ�ÿ���ڵ���˵��ֻҪ֪���ڵ�ĸ��׽ڵ�ͺ��Ӹ������Ϳ���������⣬����ֻ��Ҫ
1.��һ�����鱣��ÿ���ڵ�ĸ��׽ڵ�
2.��һ�����鱣�溢�ӵĸ���
3.��һ�����鱣��ÿһ��û�к��ӽڵ�ĸ���
��������Ժ󣬱����ڶ������飬�ҵ�û�к��ӵĽڵ㣬Ȼ���õ�һ��������ǰ������ȷ����������ò�û�к��ӽڵ�ĸ�����1
*/
#include<iostream>
#include<algorithm>
using namespace std;
int father[505];  //���׽ڵ�
int childnum[505];
int levelnum[505];  //ÿһ��Ҷ�ӽڵ�ĸ���
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        father[i]=-1;
    }
    for(int i=0;i<m;i++)
    {
        int f,k; //f�����׽ڵ㣬k�����ӵ���Ŀ
        scanf("%d %d",&f,&k);
        childnum[f]=k;
        for(int j=0;j<k;j++)
        {
            int c;  //c�����ӽڵ�
            scanf("%d",&c);
            father[c]=f;
        }
    }
    int maxlevel =0;  //��¼�����м���
    for(int i=1;i<=n;i++)
    {
        if(childnum[i]==0) //û�к���
        {
            int l =1; //����
            int p = i;  //ָ��
            while(father[p]!=-1)
            {
                l++;
                p=father[p];
            }
            levelnum[l]+=1;
            if(l>maxlevel)
                maxlevel = l;
        }
    }
    //����ڵ����
    for(int i=1;i<=maxlevel;i++)
    {
        if(i>1) printf(" ");
        printf("%d",levelnum[i]);
    }
    return 0;
}
