#include <iostream>

using namespace std;

int main()
{int n,k,a[55],i,sum=0,j;
cin>>n>>k;
for(i=1;i<=n;i++)
{cin>>a[i];
}
for(j=1;j<=n;j++)
{if(a[j]>=a[k]&&a[j]!=0)
{sum=sum+1;
}
}
cout<<sum;

return 0;
}