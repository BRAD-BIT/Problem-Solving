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
    string s; int x; cin >> s; if (s.length() == 1){ x = s[0] + 48; }else{ x = s[s.length() - 1] + s[s.length() - 2]*10 + 2 * 48; }
    if (x % 4 == 0)cout << 4; else cout << 0;
}