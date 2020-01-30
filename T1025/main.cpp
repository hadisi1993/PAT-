#include<iostream>
#include<map>
#include<queue>
#include<string>
using namespace std;
map<string,queue<int> >p;
int main()
{
//    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
//    q.push(make_pair(34,45));
//    q.push(make_pair(45,65));

//    queue<int>q[10];
//    q[0].push(3);
//    q[1].push(4);
//    map<string,queue<int> >c;
//    c["str1"] = q[0];
//    c["str2"] = q[1];
//    while(!q.empty())
//    {
//        cout<<q.top().first<<endl;
//        cout<<q.top().second<<endl;
//        q.pop();
//    }
//    string s = "str2";
//    cout<<c["str1"].front();
//    cout<<c[s].front();
map<string, priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > >mu;
    return 0;
}
