#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct Student
{
    string name;
    string ID;
    char gender;
    int score;
    Student(){};
    Student(string _name,string _ID,char _gender,int _score)
    {
        name = _name;
        ID =_ID;
        gender =_gender;
        score=_score;
    }
    bool operator<(const Student&a)const
    {
        return score>a.score;
    }
}M[100005],F[100005];
int main()
{
    int n;
    cin>>n;
    string name,ID;
    char gender;
    int score;
    int mc=0,fc=0;
    for(int i=0;i<n;i++)
    {
        cin>>name>>gender>>ID>>score;
        if(gender=='M')
            M[mc++]=Student(name,ID,gender,score);
        else
            F[fc++]=Student(name,ID,gender,score);
    }
    sort(M,M+mc);
    sort(F,F+fc);    // ≈≈–Ú
    if(fc)
        cout<<F[0].name<<" "<<F[0].ID<<endl;
    else
        cout<<"Absent"<<endl;
    if(mc)
        cout<<M[mc-1].name<<" "<<M[mc-1].ID<<endl;
    else
        cout<<"Absent"<<endl;
    if(fc&&mc)
        cout<<F[0].score-M[mc-1].score<<endl;
    else
        cout<<"NA"<<endl;
    return 0;
}
