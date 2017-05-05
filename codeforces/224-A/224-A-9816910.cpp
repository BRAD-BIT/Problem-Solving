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
    double a1, a2, a3; cin >> a1 >> a2 >> a3; cout << 4 * (sqrt(((a1*a2) / a3)) + (a1 / sqrt(((a1*a2) / a3))) + (a2 / sqrt(((a1*a2) / a3)))) << endl;
}