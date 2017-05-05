#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include <functional>
#include <sstream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    double long n;
    cin >> n;
    double long sum = 0;
    for (int i = 0; i < n; i++)
    {
        double long na;
        cin >> na;
        sum = sum + (na / 100);
    }
    double long f = (sum / n) * 100;
    cout << (sum / n) * 100;
}