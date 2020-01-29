#include<iostream>
#include<queue>
using namespace std;
const int maxn =35;
/*这道题以前做过比较多次了，今天我用建树再遍历的方法做一遍*/
int postorder[maxn],inorder[maxn];
struct node{
    int data; //数据
    node*leftchild;
    node*rightchild;
};
node*newnode(int x)   //x为数据
{
    node*root = new node;   //创建一个新的节点
    root->data = x;
    root->leftchild = NULL;
    root->rightchild = NULL;
    return root;
}
void createlevelorder(node*&now,int pl,int pr,int il,int ir)         //创建层次遍历的函数
{
    if(pl>pr||il>ir)
        return;                   //子树没有节点

    now = newnode(postorder[pr]);  //给节点赋值
    int index;
    for(int i=il;i<=ir;i++)                  //在中序遍历中找到根节点
    {
        if(inorder[i]==postorder[pr])
        {
            index = i;
            break;
        }
    }
    int llen=index-il;            //左子树节点个数
    int rlen=ir-index;            //左子树节点个数
    createlevelorder(now->leftchild,pr-llen-rlen,pr-rlen-1,il,index-1); //构建左子树
    createlevelorder(now->rightchild,pr-rlen,pr-1,index+1,ir);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&postorder[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&inorder[i]);
    node*r;
    createlevelorder(r,1,n,1,n);    // 建树
    //建树完毕后进行层次遍历
    queue<node*>q;        //创建队列，注意这里存储节点的地址
    q.push(r);
    int flag=0;
    while(!q.empty())
    {
        node*x = q.front();
        if(!flag)
        {
            printf("%d",x->data);
            flag=1;
        }
        else
        {
            printf(" %d",x->data);
        }
        if(x->leftchild!=NULL)
            q.push(x->leftchild);
        if(x->rightchild!=NULL)
            q.push(x->rightchild);
        q.pop();
    }

    return 0;
}
