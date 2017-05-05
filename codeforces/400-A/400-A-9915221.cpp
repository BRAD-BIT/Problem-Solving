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
void help1(string s)
{
    int sum = 1; bool test1 = true, test2 = true;
    for (int i = 0; i < 12; i++){ if (s[i] == 'X'){sum++; break; }}
    for (int i = 0; i < 12; i++){ if (s[i] == 'O'){sum--; break; }}
    for (int i = 0; i < 6; i++){ if (s[i] == 'X'&&s[i + 6] == 'X'){ sum++; break;}}
    for (int i = 0; i < 12; i++){ if (i % 2 == 0){ if (s[i] == 'O')test1 = false; } else{ if (s[i] == 'O')test2 = false; } }if (test1 || test2)sum++;
    if ((s[0] == 'X'&&s[4] == 'X'&&s[8] == 'X') || (s[1] == 'X'&&s[5] == 'X'&&s[9] == 'X') || (s[2] == 'X'&&s[6] == 'X'&&s[10] == 'X') || (s[3] == 'X'&&s[7] == 'X'&&s[11] == 'X'))sum++;
    if ((s[0] == 'X'&&s[3] == 'X'&&s[6] == 'X'&&s[9] == 'X') || (s[1] == 'X'&&s[4] == 'X'&&s[7] == 'X'&&s[10] == 'X') || (s[2] == 'X'&&s[5] == 'X'&&s[8] == 'X'&&s[11] == 'X'))sum++;
    cout << sum << " ";
}
void help2(string s)
{
    bool test1 = true, test2 = true, test3 = true;
    for (int i = 0; i < 12; i++){ if (s[i] == 'X'){ cout<<"1x12 "; break; } }
    for (int i = 0; i < 6; i++){ if (s[i] == 'X'&&s[i + 6] == 'X'){cout<<"2x6 "; break; } }
    if ((s[0] == 'X'&&s[4] == 'X'&&s[8] == 'X') || (s[1] == 'X'&&s[5] == 'X'&&s[9] == 'X') || (s[2] == 'X'&&s[6] == 'X'&&s[10] == 'X') || (s[3] == 'X'&&s[7] == 'X'&&s[11] == 'X'))cout<<"3x4 ";
    if ((s[0] == 'X'&&s[3] == 'X'&&s[6] == 'X'&&s[9] == 'X') || (s[1] == 'X'&&s[4] == 'X'&&s[7] == 'X'&&s[10] == 'X') || (s[2] == 'X'&&s[5] == 'X'&&s[8] == 'X'&&s[11] == 'X'))cout<<"4x3 ";
    
    for (int i = 0; i < 12; i++){ if (i % 2 == 0){ if (s[i] == 'O')test1 = false; } else{ if (s[i] == 'O')test2 = false; } }if (test1 || test2)cout<<"6x2 ";
    for (int i = 0; i < 12; i++){ if (s[i] == 'O'){ cout << endl; return; break; } }
    cout << "12x1 " << endl;
}
int main()
{
    int n; cin >> n; string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        help1(s); help2(s);
    }
}