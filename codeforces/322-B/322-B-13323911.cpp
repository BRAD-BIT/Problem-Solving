#include <bits/stdc++.h>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;
int main()
{
#ifndef ONLINE_JUDGE
   // freopen("in.txt", "rt", stdin);
//freopen("ot.txt", "wt", stdout);
#endif
   int r,g,b;
   cin>>r>>g>>b;
  int m=min(r,min(g,b));
   cout<<max(m+(r-m)/3+(g-m)/3+(b-m)/3,
           (m!=0)*(m+(r-m+1)/3+(g-m+1)/3+(b-m+1)/3-1))<<endl;
}