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
#include <iterator>
#include<list>
#include<stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    string a, x; cin >> a;
    map<string, int> map;
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        map[x] = i;
    }
    for (int j = 0; j < 80; j += 10)
    {
        cout << map[a.substr(j, 10)];
    }
}