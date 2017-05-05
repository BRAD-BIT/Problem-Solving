#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<functional>
#include<sstream>
#include<stack>
#include<queue>
#include<bitset> 
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    int a[5][5]; int b[] = { 0, 1, 2, 3, 4 }; for (int i = 0; i < 5; i++)for (int j = 0; j < 5; j++)cin >> a[i][j];
    int k = 120;
    int max = 0, sum = 0;
    while (k != 0)
    {
        sum = a[b[0]][b[1]] + a[b[2]][b[3]] + a[b[1]][b[2]] + a[b[3]][b[4]] + a[b[2]][b[3]] + a[b[3]][b[4]] + a[b[1]][b[0]] + a[b[3]][b[2]] + a[b[2]][b[1]] + a[b[4]][b[3]] + a[b[3]][b[2]] + a[b[4]][b[3]];
        if (max < sum)max = sum;
        next_permutation(b, b + 5);
        k--;
    }
    cout << max << endl;
}