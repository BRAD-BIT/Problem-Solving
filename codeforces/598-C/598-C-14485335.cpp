#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <utility>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

#define INF (int)1e9
#define MAX (int)1e6+1
#define PI 2.000*acos(0.0)

long double Abs(long double i)
{
    return (i >= 0) ? i : -i;
}
long double magnitude(long double x, long double y)
{
    return sqrt((long double)(Abs(x) *Abs(x)) + (Abs(y) *Abs(y)));
}

int main()
{
    int n, mv1, mv2;    cin >> n;
    vector<pair<long double, int>> arr(100001); long double minAngle = INF;
    for (int i = 0; i < n; i++)
    {
        long double x, y; cin >> x >> y;
        arr[i].second = i;
        arr[i].first = atan2(y, x);
        if (arr[i].first < 0)
            arr[i].first += 2 * PI;
    }
    sort(arr.begin(), arr.begin() + n);

    if (arr[0].first - arr[n - 1].first + 2 * PI<minAngle)
    {
        minAngle = Abs(arr[0].first - arr[n - 1].first + 2 * PI);
        mv1 = arr[0].second + 1; mv2 = arr[n - 1].second + 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        long double temp = Abs(arr[i].first - arr[i + 1].first); temp = (temp >= 2 * PI) ? temp - 2 * PI : temp;
        //  cout << fixed << setprecision(30) << temp << endl;
        if (temp < minAngle)
        {
            minAngle = Abs(arr[i].first - arr[i + 1].first);
            mv1 = arr[i].second + 1; mv2 = arr[i + 1].second + 1;
        }
    }
    cout << mv1 << " " << mv2;
    return 0;
}