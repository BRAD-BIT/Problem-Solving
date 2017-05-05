#include<iostream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    ll n, t; cin >> n >> t; int *a = new int[n];
    for (int i = 0; i < n; i++)cin >> a[i];
    int max = 0, sum = 0, time = 0,begin = 0;
    for (int i = 0; i < n; i++)
    {
        time += a[i]; sum++;
        if (time>t)
        {
            time -= a[begin];
            if (sum-1>max)max = sum;
            sum--;
            begin++;
        }
    }
    if (sum > max)max = sum;
    cout << sum << endl;
}