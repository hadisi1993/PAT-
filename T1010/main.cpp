#include<iostream>
#include<cmath>
#include<string.h>
#include<cctype>
using namespace std;
//�������һ��ʼ�����ͨ����ⷽ����ý⣬�����Ƚϸ��ӣ�������ѧ֪ʶҲ�����������ñ�����һ��
//�������һ�£��������ܳ��ֵ��������long long���ͻ��ǿ���װ�µģ�����û��Ҫ���ַ����ô������
//��һ��������ֻ��ʮ��֣���radix��ߵ�100��19�֣���ߵ�1000��������
//�����������35�����г�����LL�ͱ�ʾ�Ŀ���
typedef long long LL;
int main()
{
    LL t1=0,t2=0;
    char str1[10],str2[10];
    int tag,radix;
    scanf("%s %s %d %d",str1,str2,&tag,&radix);
    if(tag==1)    // Ҫת�����ǵ�һ����
    {
        int len = strlen(str1);
        for(int i=0;i<len;i++)
        {
            t1 =t1*radix+(isdigit(str1[i])?str1[i]-'0':(str1[i]-'a'+10));   //����t2
        }
       //printf("t1:%lld\n",t1);
        int len2 = strlen(str2);
        for(int i=2;i<=100;i++)
        {
            t2 = 0;
            for(int j=0;j<len2;j++)
            {
                t2 =t2*i+(isdigit(str2[j])?str2[j]-'0':(str2[j]-'a'+10));   //����t2
              //  printf("%d\n",t2);
                if(t2>t1)
                    break;
            }
            //printf("t2:%lld\n",t2);
            if(t2==t1)
            {
                printf("%d\n",i);
                return 0;
            }

        }
    }
    else
    {
        int len = strlen(str2);
        for(int i=0;i<len;i++)
        {
            t2 =t2*radix+(isdigit(str2[i])?str2[i]-'0':(str2[i]-'a'+10));   //����t2
        }
      //  printf("t1:%lld\n",t2);
        int len2 = strlen(str1);
        for(int i=2;i<=100;i++)
        {
            t1 = 0;
            for(int j=0;j<len2;j++)
            {
                t1 =t1*i+(isdigit(str1[j])?str1[j]-'0':(str1[j]-'a'+10));   //����t2
                if(t1>t2)
                    break;
            }
            if(t2==t1)
            {
                printf("%d\n",i);
                return 0;
            }
        }

    }
    printf("Impossible\n");
    return 0;
}
