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
    int n, sum = 0; cin >> n; int *a = new int[n]; for (int i = 0; i < n; i++){ cin >> a[i]; if (a[i] == i)sum++; }
    if (sum == n){ cout << sum << endl; return 0; }
    for (int i = 0; i < n; i++)
    {
        if (a[i]!=i)
        {
            if (a[a[i]] == i){ cout << sum + 2 << endl; return 0; }
        }
    }
    cout << sum + 1 << endl;
}