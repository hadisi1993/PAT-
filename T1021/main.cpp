#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e4+5;
int in[maxn],out[maxn];
int main()
{
    int n;
    cin>>n;
    int i,o;
    for(int j=0;j<n-1;j++)
    {
        cin>>o>>i;
        if(o>i)
            swap(i,o);
        in[i]+=1;
        out[o]+=1;
    }
    int cnt=0;
    for(int j=1;j<=n;j++)
        if(in[j]==0)
            cnt++;
    if(cnt>1)
        cout<<"Error: "<<cnt<<" componets"<<endl;
    else
    {
        for(int j=1;j<=n;j++)
            if(!out[j]||(in[j]==0&&out[j]==1))
                cout<<j<<endl;
    }

    return 0;
}
