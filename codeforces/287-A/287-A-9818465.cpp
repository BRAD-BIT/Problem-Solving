#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include <stdio.h>
#include<fstream>
using namespace std;
int main()
{
    char x; int sum[18] = { 0 };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> x;
            if (i == 0 || i == 1)
            {
                if (j == 0 || j == 1){ if (x == '.')sum[0]++; else sum[1]++; }
                if (j == 1 || j == 2){ if (x == '.')sum[2]++; else sum[3]++; }
                if (j == 2 || j == 3){ if (x == '.')sum[4]++; else sum[5]++; }
            }
            if (i == 1 || i == 2)
            {
                if (j == 0 || j == 1){ if (x == '.')sum[6]++; else sum[7]++; }
                if (j == 1 || j == 2){ if (x == '.')sum[8]++; else sum[9]++; }
                if (j == 2 || j == 3){ if (x == '.')sum[10]++; else sum[11]++; }
            }
            if (i == 2 || i == 3)
            {
                if (j == 0 || j == 1){ if (x == '.')sum[12]++; else sum[13]++; }
                if (j == 1 || j == 2){ if (x == '.')sum[14]++; else sum[15]++; }
                if (j == 2 || j == 3){ if (x == '.')sum[16]++; else sum[17]++; }
            }
        }
    }
    if (sum[0] == 3 || sum[0] == 4 || sum[1] == 3 || sum[1] == 4){ cout << "YES" << endl; return 0; }
    if (sum[2] == 3 || sum[2] == 4 || sum[3] == 3 || sum[3] == 4){ cout << "YES" << endl; return 0; }
    if (sum[4] == 3 || sum[4] == 4 || sum[5] == 3 || sum[5] == 4){ cout << "YES" << endl; return 0; }
    if (sum[6] == 3 || sum[6] == 4 || sum[7] == 3 || sum[7] == 4){ cout << "YES" << endl; return 0; }
    if (sum[8] == 3 || sum[8] == 4 || sum[9] == 3 || sum[9] == 4){ cout << "YES" << endl; return 0; }
    if (sum[10] == 3 || sum[10] == 4 || sum[11] == 3 || sum[11] == 4){ cout << "YES" << endl; return 0; }
    if (sum[12] == 3 || sum[12] == 4 || sum[13] == 3 || sum[13] == 4){ cout << "YES" << endl; return 0; }
    if (sum[14] == 3 || sum[14] == 4 || sum[15] == 3 || sum[15] == 4){ cout << "YES" << endl; return 0; }
    if (sum[16] == 3 || sum[16] == 4 || sum[17] == 3 || sum[17] == 4){ cout << "YES" << endl; return 0; }
    cout << "NO" << endl;
}