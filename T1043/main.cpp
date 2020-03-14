#include<iostream>
#include<vector>
using namespace std;
/*判断按照给出序列建的树是不是二叉搜索树,主要考点在于关于二叉搜索树的一系列操作*/
vector<int>origin,pre,preM,post,postM;
struct node  // 树的节点
{
    int data;
    node*left;
    node*right;
};
void insert(node*&root,int data)
{
    if(root==NULL)
    {
        root = new node;  // 创建一个节点
        root->data = data;  // 赋予数据
        root->left = root->right=NULL;
        return ;
    }
    if(data<root->data)
        insert(root->left,data);
    else
        insert(root->right,data);
}
void preOrder(node*&root,vector<int>&vi)   // 原树的前序遍历
{
    if(root == NULL)
        return ;
    vi.push_back(root->data);
    preOrder(root->left,vi);
    preOrder(root->right,vi);
}
void preMOrder(node*&root,vector<int>&vi)  // 镜像树的前序遍历
{
    if(root == NULL)
        return ;
    vi.push_back(root->data);
    preMOrder(root->right,vi);
    preMOrder(root->left,vi);

}
void postOrder(node*&root,vector<int>&vi)  // 原树的后序遍历
{
    if(root == NULL)
        return ;
    postOrder(root->left,vi);
    postOrder(root->right,vi);
    vi.push_back(root->data);
}
void postMOrder(node*&root,vector<int>&vi)   // 镜像树的后序遍历
{
    if(root == NULL)
        return ;
    postMOrder(root->right,vi);
    postMOrder(root->left,vi);
    vi.push_back(root->data);
}
int main()
{
    int n,v;
    scanf("%d",&n);
    node*root = NULL  ;// 根节点
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v);
        insert(root,v);  // 建树
        origin.push_back(v);  // 输入原始序列
    }
    preOrder(root,pre);
    preMOrder(root,preM);
    postOrder(root,post);
    postMOrder(root,postM);
    if(origin == pre)
    {
        printf("YES\n");
        for(int i=0;i<post.size();i++)
            i>0?printf(" %d",post[i]):printf("%d",post[i]);
    }
    else if(origin == preM)
    {
        printf("YES\n");
        for(int i=0;i<postM.size();i++)
            i>0?printf(" %d",postM[i]):printf("%d",postM[i]);
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
