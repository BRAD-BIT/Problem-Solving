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
struct team{ int x, y;};
team a[100000] = { 0 }; team b[100000];
int main()
{
    int n; cin >> n; for (int i = 0; i < n; i++){ cin >> b[i].x >> b[i].y;a[b[i].x - 1].x++; a[b[i].y-1].y++;}
    for (int i = 0; i < n; i++)
    {
        int home = (n - 1) + a[b[i].y-1].x;
        int away = 2*(n - 1) - home;
        cout << home << " " << away << endl;
    }
}