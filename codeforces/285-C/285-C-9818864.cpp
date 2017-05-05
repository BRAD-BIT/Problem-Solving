#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n, sum = 0; cin >> n; int *a = new int[n]; for (int i = 0; i < n; i++)cin >> a[i];
    sort(a, a + n);for (int i = 0; i < n; i++){sum += abs(i + 1 - a[i]);}cout << sum << endl;
}