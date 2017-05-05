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
    int n, k1, k2; cin >> n >> k1; queue<int>k11, k22; int a[100], b[100];

    vector<int>v1, v2, v3, v4;


    for (int i = 0; i < k1; i++){ int x; cin >> x; v1.push_back(x); a[i] = x; }
    cin >> k2;
    for (int i = 0; i < k2; i++){ int x; cin >> x; v2.push_back(x); b[i] = x; }
    int counter = 0;
    while (1)
    {
        counter++;
        if (v1[0] > v2[0])
        {
            v1.push_back(v2[0]);
            v1.push_back(v1[0]);
            v1.erase(v1.begin() );
            v2.erase(v2.begin() );
        }
        else
        {
            v2.push_back(v1[0]);
            v2.push_back(v2[0]);
            v1.erase(v1.begin() );
            v2.erase(v2.begin() );
        }
        if (v1.size() == 0){ cout << counter << " " << 2; return 0; }
        if (v2.size() == 0){ cout << counter << " " << 1; return 0; }
        if (v1.size() == k1&&v2.size() == k2)
        {
            bool test1 = 1, test2 = 1;
            for (int i = 0; i < k1; i++)
            {
                if (v1[i] != a[i])test1 = false;
            }
            for (int i = 0; i < k2; i++)
            {
                if (v2[i] != b[i])test2 = false;
            }
            if ((test1&&test2)){ cout << -1; return 0; }
        }
        if (counter == 1000000){ cout << -1; return 0; }
    }
}