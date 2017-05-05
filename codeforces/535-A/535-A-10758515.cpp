#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
using namespace std;
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
vector<string>vv;
int main()
{
    string a[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    string a2[] = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    int n; cin >> n;
    if (n == 0)cout << a[0] << endl;
    else
    if (n % 10 == 0)cout << a2[(n / 10) - 1] << endl;
    else
    if (n < 10)cout << a[n] << endl;
    else
    if (n < 20)cout << a[n-1] << endl;
    else
    cout << a2[((n - n % 10) / 10) - 1] << "-" << a[n % 10] << endl;
}