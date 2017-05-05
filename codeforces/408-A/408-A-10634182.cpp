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
int main()
{
    int n; cin >> n; int a[107]; int min = 500000000000000;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < a[i]; j++)
        {
            int a; cin >> a;
            sum += a * 5 + 15;
        }
        if (min>sum)min = sum;
    }
    cout << min << endl;
}