#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef pair<char, int> pci;
bool comp(pci a, pci b){return a.second < b.second;}
int main()
{
    string A, B, C, D; cin >> A >> B >> C >> D;
    vector<pci> vec(4);
    vec[0] = make_pair('A', A.length() - 2);
    vec[1] = make_pair('B', B.length() - 2);
    vec[2] = make_pair('C', C.length() - 2);
    vec[3] = make_pair('D', D.length() - 2);
    sort(vec.begin(),vec.end(), comp);
    if (2 * vec[0].second <= vec[1].second && 2 * vec[2].second > vec[3].second)    cout << vec[0].first;
    else if (2 * vec[2].second <= vec[3].second && 2 * vec[0].second > vec[1].second)cout << vec[3].first;
    else cout << 'C';

}