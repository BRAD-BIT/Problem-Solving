#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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

int main()
{
    //R_W;
    int n; cin >> n;
    if (n == 1){ cout << 1 << endl << 1; return 0; }
    if (n == 2){ cout << 1 << endl << 1; return 0; }
    if (n == 3){ cout << 2 << endl << 1 << " " << 3; return 0; }
    if (n == 4){ cout << 4 << endl << 3 << " " << 1 << " " << 4 << " " << 2; return 0; }
       cout << n << endl;
        int a = 1; int b = 2;
        for (int i = 0; i < n; i++)
        {
            if (n % 2 == 0)
            {
                if (i < n / 2){ cout << a << " "; a += 2; }
                else{ cout << b << " "; b += 2; }
            }
            else
            {
                if (i < n / 2+1){ cout << a << " "; a += 2; }
                else{ cout << b << " "; b += 2; }

            }
        }
}