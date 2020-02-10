/*这道题的思路是这样的：
1.用结构体保存多项式，有两个成员变量:系数和指数；两个多项式分别用两个结构体保存
2.做加法的时候，采用这样的策略，
   用两个指针遍历两个结构体，由题意，结构体的指数是自动降序的，所以不需要额外的处理
   比较两个指针指向的结构体，如果指数不相同，则把指数大的结构体复制到新数组中，该结构体指针向后移；
   如相同，则将系数相加，若不为0，则将结构存入新数组中，两个指针同时后移
3. 按要求输出新数组的个数，各项的指数和系数
这道题的写法比较固定了
*/
#include <iostream>
using namespace std;
struct term{
  int exp;
  float cof;
}t1[15],t2[15],t3[15];
int main()
{
   int k1,k2;
   scanf("%d",&k1);
   for(int i=0;i<k1;i++)
   {
       scanf("%d %f",&t1[i].exp,&t1[i].cof);
   }
   scanf("%d",&k2);
   for(int i=0;i<k2;i++)
   {
       scanf("%d %f",&t2[i].exp,&t2[i].cof);
   }
   int i=0,j=0,k=0;  //指针
   while(i<k1&&j<k2)
   {
       if(t1[i].exp>t2[j].exp)
       {
           t3[k].cof = t1[i].cof;
           t3[k].exp = t1[i].exp;
           i++;
           k++;
       }
       if(t1[i].exp<t2[j].exp)
       {
           t3[k].cof = t2[j].cof;
           t3[k].exp = t2[j].exp;
           j++;
           k++;
       }
       if(t1[i].exp==t2[j].exp)
       {
           if(t1[i].cof+t2[j].cof!=0)
           {
               t3[k].cof = t1[i].cof+t2[j].cof;
               t3[k].exp = t1[i].exp;
               k++;
           }
           i++,j++;
       }
   }
   while(i<k1)
   {
        t3[k].cof = t1[i].cof;
        t3[k].exp = t1[i].exp;
        i++;
        k++;
   }
    while(j<k2)
   {
        t3[k].cof = t2[j].cof;
        t3[k].exp = t2[j].exp;
        j++;
        k++;
   }
   printf("%d",k);
   for(int i=0;i<k;i++)
   {
       printf(" %d %.1f",t3[i].exp,t3[i].cof);
   }
   printf("\n");
   return 0;
}
