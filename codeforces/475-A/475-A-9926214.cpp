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
struct unhappy{int stat,index;};
int main()
{
    string a[] = { "+------------------------+", "|#.#.#.#.#.#.#.#.#.#.#.|D|)", "|#.#.#.#.#.#.#.#.#.#.#.|.|", "|#.......................|", "|#.#.#.#.#.#.#.#.#.#.#.|.|)", "+------------------------+" };
    int n; cin >> n;
    int row = 1;
    while (n != 0)
    {
        if (a[1][row] == '#'){ n--; a[1][row] = 'O'; }
        else 
        if (a[2][row] == '#'){ n--; a[2][row] = 'O'; }
        else
        if (a[3][row] == '#'){ n--; a[3][row] = 'O'; }
        else
        if (a[4][row] == '#'){ n--; a[4][row] = 'O'; }
        else
            row += 2;
    }
    for (int i = 0; i < 6; i++)cout << a[i] << endl;
}