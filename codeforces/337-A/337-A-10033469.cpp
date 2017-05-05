#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int test(int n)
{
    if (n >= 0)return n;
    else return -n;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int *a = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a, a+m);
    int diff = 10000;
    for (int i = 0; i <= m-n; i++)
    {
        int max = a[i];
        int min = a[i];
        for (int j = i; j < i+n; j++)
        {
            if (max < a[j])max = a[j];
            if (min>a[j])min = a[j];
        }
        if (diff>(max - min))diff = max - min;
    }
    cout << diff;
}