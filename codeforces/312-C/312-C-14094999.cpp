#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;cin>>n>>k;
    if(n*(n-1)/2<=k)return(cout<<"no solution\n",0);
    for(int i=1;i<=n;++i)cout<<0<<" "<<i<<endl;
}