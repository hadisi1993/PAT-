#include<iostream>
#include<algorithm>
using namespace std;
/*这道题就是让我们洗牌，每一次洗牌要输入54个数字，每个数字代表将当前数字移动到
的新的位置
做法
1. 用一个结构体表示一张牌
2. 牌的结构包括:花色，牌号，当前位置
3. 每次输入新位置，就将当前位置输入，然后重新排序
4. 排序结束后，输出排序结果*/
struct card
{
    char ty;  // 类型
    int order; // 序号
    int pos;   // 位置
    card(){}
    card(char _t,int _order,int _pos):ty(_t),order(_order),pos(_pos){}
    bool operator <(const card&a)const
    {
        return pos<a.pos;
    }
}Card[55];
int tmp[55];
char s[] = {'S','H','C','D','J'};
int main()
{
    for(int i=0;i<=53;i++)
    {
        Card[i] = card(s[i/13],i%13+1,i+1);
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<54;i++)
        scanf("%d",&tmp[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=53;j++)
        {
            Card[j].pos = tmp[j];
        }
        sort(Card,Card+54);
    }
    printf("%c%d",Card[0].ty,Card[0].order);
    for(int i=1;i<54;i++)
        printf(" %c%d",Card[i].ty,Card[i].order);
    return 0;
}
