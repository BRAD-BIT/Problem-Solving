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
struct question
{
    string comp;
    long long num;
    char answer;
};
int main()
{
    int n;
    cin >> n;
    question *a = new question[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].comp >> a[i].num >> a[i].answer;
        if (a[i].answer == 'N')
        {
            if (a[i].comp == ">=")a[i].comp = "<";
            else
            if (a[i].comp == "<=")a[i].comp = ">";
            else
            if (a[i].comp == ">")a[i].comp = "<=";
            else
            if (a[i].comp == "<")a[i].comp = ">=";
            a[i].answer = 'Y';
        }
    }
    long long begin = -100000000000000000;
    long long end = 100000000000000000;
    for (int i = 0; i < n; i++)
    {
        if (a[i].comp == ">")
        {
            if (a[i].num+1>begin)begin = a[i].num + 1;
        }
        else
        if (a[i].comp == ">=")
        {
            if (a[i].num>begin)begin = a[i].num;
        }
        else
        if (a[i].comp == "<")
        {
            if (a[i].num-1 < end)end = a[i].num - 1;
        }
        else
        if (a[i].comp == "<=")
        {
            if (a[i].num < end)end = a[i].num;
        }
    }
    if (begin>end)cout << "Impossible";
    else
    {
        if (begin == -100000000000000000)cout << end;
        else cout << begin;
    }
}