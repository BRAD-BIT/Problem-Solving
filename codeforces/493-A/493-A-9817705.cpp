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
#include <stdio.h>
#include<fstream>
using namespace std;
struct player
{
    int time;
    string team_name;
    int player_number;
    char foul;
};
int main()
{
    int n; string s1, s2; cin >> s1 >> s2 >> n; player *a = new player[n]; for (int i = 0; i < n; i++){ cin >> a[i].time >> a[i].team_name >> a[i].player_number >> a[i].foul; if (a[i].team_name == "h")a[i].team_name = s1; else a[i].team_name = s2; }
    int sumR = 0, sumY = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[j].player_number == a[i].player_number&&a[j].team_name == a[i].team_name)
            {
                if (a[j].foul == 'r')sumR++;
                else if (a[i].foul == 'y')sumY++;
            }
        }
        if ((sumR == 1||sumY == 2)){
            cout << a[i].team_name << " " << a[i].player_number << " " << a[i].time << endl;
        int z = a[i].player_number; string z1 = a[i].team_name;for (int v = 0; v < n; v++){if (a[v].player_number == z&&a[v].team_name == z1)a[v].foul = 'v';}}
        sumR = 0, sumY = 0;
    }
}