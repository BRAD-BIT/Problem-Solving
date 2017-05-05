#include<iostream>
using namespace std;
int main()
{int n, day = 0, a[7]; cin >> n >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];
while (n > 0){if (day == 7)day = 1;else day++;n -= a[day-1];}
cout << day << endl;}