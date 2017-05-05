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
#include<list>
#include <stdio.h>
#include<fstream>
using namespace std;
#define PI 3.14159265358979323846
int main()
{
    double u = .00001;
    double n, R, r; cin >> n >> R >> r;
    double y = asin(r / (R - r));
    double x = (R - r) * 2 * y;
    if (r > R)cout << "NO";
    else
    if (x*n <= (2 * PI*(R-r)+u)||(n==1&&r>R-r))cout << "YES" << endl;
    else cout << "NO" << endl;
}