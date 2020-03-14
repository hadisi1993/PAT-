#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
/*�������һ���Ƚϼ򵥵Ĺ�������DFS��,����ô����Ҫ��
1. ����Ĵ�root��leaf��Ȩ��֮��
2. ��vectorģ����,��Ϊ�ڵ�Ƚ���
3. ÿ��vectorҪ����Ȩ������
4. ��һ��vector���鱣�浱ǰ·��
*/
int w[105];
vector<int>v[105];  // ��
vector<int>q;    // �����·��
LL sum;        // Ȩ��֮��
bool cmp(int a,int b)   // �ȽϺ���
{
    return w[a]>w[b];
}
void DFS(int node, int s)  // node:��ǰ�ڵ�  s:Ȩ��֮��
{
    if(v[node].size()==0)
    {
        if(s==sum)   // ��ȣ���ӡ
        {
            for(int i=0;i<q.size();i++)
            {
                i==0?printf("%d",q[i]):printf(" %d",q[i]);
            }
            printf("\n");
        }
        return ;
    }
    else
    {
        if(s>=sum)
            return ;  // û�ߵ�Ҷ�ӽڵ�Ȩֵ�Ѿ��ȸ���Ȩ�ش��ˣ�ֱ�Ӽ�֦��
        else
        {
            for(int i=0;i<v[node].size();i++)
            {
                q.push_back(w[v[node][i]]);
                DFS(v[node][i],s+w[v[node][i]]);
                q.pop_back();
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m>>sum;
    for(int i=0;i<n;i++)
        cin>>w[i];
    int p,c,num;  // ���ڵ㣬�ӽڵ�,���ӵĸ���
    for(int i=0;i<m;i++)
    {
        cin>>p>>num;
        for(int j=0;j<num;j++)
        {
            cin>>c;
            v[p].push_back(c);
        }
        sort(v[p].begin(),v[p].end(),cmp);  // ����
    }
    q.push_back(w[0]);
    DFS(0,w[0]);
    return 0;
}
