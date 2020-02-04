#include <iostream>
using namespace std;
struct ball
{
    int d;
    int t;
};
int main()
{
   // baller*b =new baller [10];
   // b[3]->d=0;
  //  printf("%d",b[5]->d);
  ball**a =new ball*[10005];
 // a[0]->d = 4;
  printf("%d",a[0]->d);
  return 0;
}
