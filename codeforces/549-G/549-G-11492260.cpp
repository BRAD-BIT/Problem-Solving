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
#include<functional>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<array>
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
struct person{ int money, indx; };
bool comp(person a, person b){ return a.money+a.indx < b.money+b.indx; }
person a[200007];
int main()
{
    int n; cin >> n; 
    for (int i = 0; i < n; i++){ cin >> a[i].money; a[i].indx = i; }
    sort(a, a + n, comp);
    for (int i = 0; i < n; i++)a[i].money += (a[i].indx - i);
    for (int i = 0; i < n-1; i++)if (a[i].money>a[i + 1].money){ cout << ":(\n"; return 0; }
    for (int i = 0; i < n; i++)cout << a[i].money << " "; cout << endl;
}