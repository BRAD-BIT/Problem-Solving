#include<iostream>
using namespace std;
int  lowestdivisible(int x, int y){int i = 1;while (i%x != 0 || i%y != 0){i++;}return i;}
int main()
{
    long long x, y, a, b; cin >> x >> y >> a >> b; int z = lowestdivisible(x, y);;
    cout << b / z - (a-1) / z;
}