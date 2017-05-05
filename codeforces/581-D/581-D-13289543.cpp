#include<iostream>
using namespace std;
#define lop(i,a,n) for(int i=a;i<n;++i)
int main()
{
    int arr[6][2];
    lop(i,0,3)cin>>arr[i][0]>>arr[i][1];
    lop(i,0,3){arr[i+3][0]=arr[i][1];arr[i+3][1]=arr[i][0];}
    lop(i,0,6)lop(j,0,6)lop(k,0,6)if(i!=j&&j!=k&&i!=k)
        {
              if(arr[j][0]==arr[i][0]&&(arr[k][0]==arr[i][0]&&arr[i][0]==arr[i][1]+arr[j][1]+arr[k][1]))
              {
     
                   cout<<arr[i][0]<<endl;
                   lop(y,0,arr[i][1]){lop(x,0,arr[i][0])cout<<char('A'+(i%3));cout<<endl;}
                   lop(y,0,arr[j][1]){lop(x,0,arr[j][0])cout<<char('A'+(j%3));cout<<endl;}
                   lop(y,0,arr[k][1]){lop(x,0,arr[k][0])cout<<char('A'+(k%3));cout<<endl;}
                   return 0;
              }
              else
              if(arr[i][1]==arr[j][1]&&(arr[k][0]==arr[i][0]+arr[j][0]&&arr[i][0]+arr[j][0]==arr[k][1]+arr[i][1]))
              {
                    
                   cout<<arr[i][0]+arr[j][0]<<endl;
                   lop(y,0,arr[i][1]){lop(x,0,arr[i][0])cout<<char('A'+(i%3));lop(x,0,arr[j][0])cout<<char('A'+(j%3));cout<<endl;}
                   lop(y,0,arr[k][1]){lop(x,0,arr[k][0])cout<<char('A'+(k%3));cout<<endl;}
                   return 0;
                      
              }
       }
       cout<<"-1\n";
}