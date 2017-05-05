#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int max = a[0];
    int min = a[0];
    int maxi=0, mini=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            maxi = i;
        }
        if (a[i] <= min)
        {
            min = a[i];
            mini = i;
        }
    }
    bool test = true;
    for (int i = 0; i < n-1; i++)
    {
        if (a[i]!=a[i+1])
        {
            test = false;
        }
    }
    if (test)cout << 0;
    else
    if (mini > maxi)cout << maxi + (n - 1 - mini);
    else    if(mini < maxi)cout << maxi + (n - 1 - mini - 1);
    

}