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
#define ll long long
int main()
{
    double r, x, y, z, w; cin >>r>> x >> y >> z >> w; double f = (sqrt(pow(x - z, 2.000) + pow(y - w, 2.000))) / (2 * r);
    cout << ceil(f) << endl;
}