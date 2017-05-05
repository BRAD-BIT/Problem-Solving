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
using namespace std;
int main()
{
    int n; cin >> n;
    if (n == 1 || n == 2)cout << -1;else{for (int i = n; i>0; i--){cout << i << " ";}}
}