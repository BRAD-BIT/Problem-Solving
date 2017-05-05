#include<iostream>
#include<string>
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
#define PI 3.14159265358979323846
#define ll long long
int main()
{
    string s1, s2; cin >> s1 >> s2;
    if (s1.length() < s2.length()){ cout << "need tree" << endl; return 0; }
    if (s1.length() == s2.length())
    {
        sort(s1.begin(), s1.end()); sort(s2.begin(), s2.end());
        if (s1 == s2){ cout << "array" << endl; return 0; }
        else { cout << "need tree" << endl; return 0; }
    }
    else
    {
        string s3 = s1;
        for (int i = 0; i < s3.length(); i++)
        {
            if (s3[i] != s2[i]){ s3.erase(i, 1); i = -1; }
        }
        if (s3 == s2){ cout << "automaton" << endl; return 0; }
        sort(s1.begin(), s1.end()); sort(s2.begin(), s2.end());
        s3 = s1;
        for (int i = 0; i < s3.length(); i++)
        {
            if (s3[i] != s2[i]){ s3.erase(i, 1); i = -1; }
        }
        if (s3 == s2){ cout << "both" << endl; return 0; }
        cout << "need tree" << endl;
    }
}