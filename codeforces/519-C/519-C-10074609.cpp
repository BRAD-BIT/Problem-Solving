#include<iostream>
#include<string>
#include<cstring>
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
    ll XP, NB; cin >> XP >> NB; ll sum = 0;
    while (1)
    {
        if (XP > NB)
        {
            if (XP >= 2 && NB >= 1){ sum++; XP -= 2; NB -= 1; }
            else break;
        }
        else
        {
            if (NB >= 2 && XP >= 1){ sum++; NB -= 2; XP -= 1; }
            else break;
        }
    }
    cout << sum << endl;
}