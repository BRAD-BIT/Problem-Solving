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
    double n, x, y; cin >> n >> x >> y;
    if (ceil(((y / 100)*n) - x) > 0)cout << ceil(((y / 100)*n) - x) << endl; else cout << 0;
}