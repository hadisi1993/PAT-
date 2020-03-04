/*这道题的思路其实不难，但当时没有采用一种很好很简便的方法来写这道题,参考了网上的代码以后，重写*/
/*新的思路，*/
#include<iostream>
#include<algorithm>
using namespace std;
int flag=0;
struct stu
{
    int id,best,course;   // 六位的学号,最好的排名,最好排名的序号
    int score[4];  // 四门课的分数，注意这道题的平均分是取整的
}s[2005];
bool cmp(stu a,stu b)    //这样的写法可以方便排序
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
        s[i].score[0] = (s[i].score[1]+s[i].score[2]+s[i].score[3])/3;  // 计算平均分
        s[i].best = 10000;
    }
    for(int i=0;i<t;i++)  // 查找最佳排名
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
                    index =j;   //定位
                }
            }
        }
        if(index>=0)
            printf("%d %c\n",s[index].best,kw[s[index].course]);
        else
            printf("N/A\n");
    }
}
