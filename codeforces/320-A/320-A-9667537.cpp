#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
#include <bitset> 
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool test = true;
    int z = s.length();
    for (int i = 0; i < z; i++)
    {
            if (s[i] == '1'&&s[i + 1] == '4'&&s[i + 2] == '4')i = i + 2;
            else
            if (s[i] == '1'&&s[i + 1] == '4')i = i + 1;
            else
            if (s[i] == '1')i = i;
            else test = false;
        
    }
    if (test)cout << "YES";
    else cout << "NO";
}