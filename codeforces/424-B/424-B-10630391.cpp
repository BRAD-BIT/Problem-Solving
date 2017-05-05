#include<algorithm>
#include<stdlib.h>
#include<iterator>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>
#include<ctime>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
struct city{ long double distance;ll people; };
bool comp(city a, city b)
{
    return a.distance < b.distance;
}
int main()
{
    int n, s; cin >> n >> s; city a[1007];
    for (int i = 0; i < n; i++)
    {
        int x, y, k; cin >> x >> y >> k;
        a[i].people = k; a[i].distance = sqrt(x*x + y*y);
    }
    sort(a, a + n, comp);
    int sum = s;
    for (int i = 0; i < n; i++)
    {
        sum += a[i].people;
        if (sum >= 1000000){ cout << fixed << setprecision(10) << a[i].distance << endl; return 0; }
    }
    cout << -1 << endl;
}