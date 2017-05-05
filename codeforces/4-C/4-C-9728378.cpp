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
    map<string, int> contact;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (!contact[s])
        {
            cout << "OK" << endl;
            contact[s] = 1;
        }
        else
        {
            cout << s << contact[s] << endl;
            contact[s]++;
        }
    }
}