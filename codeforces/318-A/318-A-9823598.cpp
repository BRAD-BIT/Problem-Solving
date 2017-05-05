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
    long long  n, k,z; cin >> n >> k;
    if (k <= ceil(n / 2.000))z = 2 * k - 1;
    else z = (k - ceil(n / 2.0000)) * 2;
    cout << z << endl;
}