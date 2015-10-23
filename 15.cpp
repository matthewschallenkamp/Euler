#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

long long paths(int x, int y)
{
    static vector<vector <long long> > v;
    if(x >= v.size())
        v.resize(x+1);
    for(auto &i : v)
        if(y >= i.size())
            i.resize(y+1, -1);
    if(x == 0 || y == 0)
        return 1;
    if(v[x][y] == -1)
    {
        v[x][y] = paths(x-1, y) + paths(x, y-1);
        cout << "got " << x << " " << y << " " << v[x][y] << endl;
    }
    return v[x][y];
}

int main()
{
    cout << "there are " << paths(20, 20) << " paths through a 20 20 grid";
    return 0;
}
