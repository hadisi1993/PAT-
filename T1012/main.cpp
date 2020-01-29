/*这道题我一开始打算这么做，用一个矩阵来保存信息，每一行存储一门课的排名的学号(学号按成绩排)，一共四行
分别是A,C,M,E,然后在这四个个数组中查找，如果找到则输出排名和课程，否则则输出N/A
以上这个想法有一个漏洞:没办法考虑并列情况
这道题应该不用这么复杂，直接拿一个同学的四门成绩去在成绩当中，第一个出现的排名+1就是名次
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct student{
  string ID;
  int C;
  int M;
  int E;
  float A;
  student(){}  //用以不初始化就能定义结构体变量
  student(string _ID, int _C,int _M,int _E)
  {
      ID = _ID;
      C = _C;
      M = _M;
      E = _E;
      A = (C+M+E)/3;
  }
}S[2005];
bool cmp(int a,int b)
{
    return a>b;
}
bool cmp2(float a,float b)
{
    return a>b;
}
int eg[2005],mt[2005],cp[2005];
float avg[2005];
int main()
{
    string id;
    int c,m,e;
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        cin>>id>>c>>m>>e;
        S[i] = student(id,c,m,e);
        cp[i]=c;
        mt[i]=m;
        eg[i]=e;
        avg[i]=S[i].A;
    }
    sort(cp,cp+n,cmp);
    sort(mt,mt+n,cmp);
    sort(eg,eg+n,cmp);
    sort(avg,avg+n,cmp2);
    for(int j=0;j<t;j++)
    {
        cin>>id;
        char BestCourse;
        int Rank;
        int i;
        for(i=0;i<n;i++)
            if(S[i].ID==id)
                break;
        if(i==n)
        {
            cout<<"N/A"<<endl;
            continue;
        }

        int escore=S[i].E,mscore = S[i].M,cscore =S[i].C;
        float avge = S[i].A;
        for(i=0;i<n;i++)
        {
            if(eg[i]==escore)
            {
                Rank=i+1;
                BestCourse='E';
            }

        }
        for(i=0;i<n;i++)
        {
            if(mt[i]==mscore)
            {
                if(Rank>=i+1)
                {
                    Rank=i+1;
                    BestCourse = 'M';
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(cp[i]==cscore)
            {
                if(Rank>=i+1)
                {
                    Rank=i+1;
                    BestCourse = 'C';
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(avg[i]==avge)
            {
                if(Rank>=i+1)
                {
                    Rank=i+1;
                    BestCourse = 'A';
                }
            }
        }
        cout<<Rank<<" "<<BestCourse<<endl;
    }
    return 0;
}

/*
4 4
310101     98 85 88
310102     70 95 88
310103     82 87 94
310104     91 91 91

310103
310102
999999
310104
*/
