#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
/*������е�˵�������ʲô���͵ģ��о���һ����ջ��ص�ģ����
����ܼ򵥣�����һ����ջ���У��ж������ջ�����Ƿ����
����˼·:�ɳ�ջ�����Ʋ��ջ������������ô�������
1.ջ��Ԫ��Ϊ�գ����С�ڵ��ڵ�ǰԪ������Ԫ��ѹ��ջ��(������ǰ����ջ��)����ЩԪ�ر�����ջ����ǰԪ�ز���
��ջ��Ȼ��ǰԪ�س�ջ,�������ջ��Ԫ�ر��
2.��ǰԪ�ش���ջ��Ԫ�أ���������͵�һ�����������ͬ����ѹջ��ջ��Ԫ��+1��ʼ
3.��ǰԪ�ص���ջ��Ԫ�أ�ջ��Ԫ�س�ջ
4.��ǰԪ��С��ջ��Ԫ�أ���������Ͳ��У������������ջ��Ԫ�ػ�û�г�ջ������ջ�б���С��Ԫ�س�ջ��*/
int vis[1005];   // �жϵ�ǰԪ���Ƿ����ջ
int main()
{
    int m,n,k;
    stack<int>S;
    scanf("%d %d %d",&m,&n,&k);
    for(int i=0;i<k;i++)
    {
        while(!S.empty())
            S.pop();
        fill(vis+1,vis+n+1,0);
        int flag = 1;  // �жϿɲ�����
        int cur; // ��ǰ�������
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cur);
            if(S.empty())      // ��ǰջΪ��
            {
                for(int l=1;l<=cur;l++)
                {
                    if(!vis[l])
                    {
                        vis[l] =1;
                        S.push(l);
                    }
                }
                if(S.size()>m)
                    flag =0;
                S.pop();   // ������ǰԪ��
            }
            else if(S.top()<cur)
            {
                for(int l =S.top()+1;l<=cur;l++)
                {
                    if(!vis[l])
                    {
                        vis[l] =1;
                        S.push(l);
                    }
                }
                if(S.size()>m)
                    flag = 0;
                S.pop();
            }
            else if(S.top()==cur)
                S.pop();
            else if(S.top()>cur)
                flag = 0;
        }
       // printf("1\n");
        printf("%s\n",flag?"YES":"NO");

    }
    return 0;
}
