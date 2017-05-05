#include<bits/stdc++.h>
using namespace std;
int ocr[10000000+7];
int main()
{
    int n,ans=0;cin>>n;
    for(int i=0;i<n;i++){int a;scanf("%d",&a);ocr[a]++;}
    for(int i=0;i<2*1000000;i++)
    {
        if(ocr[i]==0)continue;
        ocr[i+1]+=ocr[i]/2;
        ans+=(ocr[i]%2);
    }
    cout<<ans<<endl;
}