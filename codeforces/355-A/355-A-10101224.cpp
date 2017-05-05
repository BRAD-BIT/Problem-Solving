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
int main()
{
    int k, d;
    cin >> k >> d;
    if (k > 1 && d == 0){ cout << "No solution"; return 0; }
    cout << d;
    for (int i = 0; i < k-1;i++)cout << 0;
}