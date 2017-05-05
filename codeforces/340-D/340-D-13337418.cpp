#include <bits/stdc++.h>
#include <ext/numeric>
#include <vector>
using namespace std;
using namespace __gnu_cxx;
int arr[100000];
int CI(int A[], int l, int r, int key) {
    int m;
    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m;
    }
    return r;
}

int LIS(int A[], int size) {
    int *B   = new int[size];
    int len=1;
    memset(B, 0, sizeof(B[0])*size);
    B[0] = A[0];
    for( int i = 1; i < size; i++ ) {
        if(A[i]<B[0])B[0] = A[i];
        else if(A[i]>B[len-1])B[len++] = A[i];
        else B[CI(B, -1, len-1, A[i])] = A[i];
    }
    return len;
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("in.txt", "rt", stdin);
//freopen("ot.txt", "wt", stdout);
#endif
   int n;cin>>n;
   for(int i=0;i<n;i++)cin>>arr[i];
   cout<<LIS(arr,n)<<endl;
}