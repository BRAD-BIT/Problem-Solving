//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<regex>
#include<stdlib.h>
#include<math.h>
#include<ctime>
using namespace std;
#define R_(s)      freopen(s, "r", stdin)
#define W_(s)      freopen(s, "w", stdout)
#define R_W        R_("input.txt"),W_("output.txt")
#define PI         3.14159265358979323846
#define ll         long long
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1
using namespace std;
int mm[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
void add_day(ll &day, ll &month, ll &year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)mm[1] = 29;
    day++;
    if (day > mm[month - 1])
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1; year++;
        }
    }
    mm[1] = 28;
}
int main()
{
    string date1, date2; cin >> date1 >> date2; if (date1 > date2)swap(date2, date1);
    ll year1 = stoll(date1.substr(0, 4));
    ll year2 = stoll(date2.substr(0, 4));
    ll month1 = stoll(date1.substr(5, 6));
    ll month2 = stoll(date2.substr(5, 6));
    ll day1 = stoll(date1.substr(8, 9));
    ll day2 = stoll(date2.substr(8, 9));
    ll ans = 0;
    while (1)
    {
        if (day1 == day2&&month1 == month2&&year1 == year2)break;
        add_day(day1, month1, year1); ans++;
    }
    cout << ans << endl;
}