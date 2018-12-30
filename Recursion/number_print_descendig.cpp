#include<iostream>
using namespace std;

void inc(int n)
{
  if(n==0)
   return;
  inc(n-1);
  cout<<n<<" ";
 return;
}

int main()
{
  int n;
  inc(5);
 return 0;
}
