#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n; cin >> n; pair<int, int>a[5001]; for (int i = 0; i < n; i++){ cin >> a[i].first>>a[i].second; } sort(a, a + n);
    long long last = 0;
    for (int i = 0; i < n; i++)
    {
        if (last <= a[i].second)last = a[i].second;
        else last = a[i].first;
    }
    cout << last;
}