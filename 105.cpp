#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool set_diff(set<int> s, int diff = 0, bool took_one = 0)
{
    if(s.size() == 0)
        return (diff == 0) && took_one;
    int item = *(s.begin());
    s.erase(s.begin());
    return set_diff(s, diff - item, 1) || set_diff(s, diff + item, 1) || set_diff(s, diff, took_one );
}

int total(set<int> &s)
{
    int t = 0;
    for(auto i : s)
        t += i;
    return t;
}

bool set_half_greater(set<int> s)
{
    int tot = 0;
    int item = *(s.begin());
    s.erase(s.begin());
    tot += item;
    //first item to the start
    while(s.size() >= 2)
    {
        item = *(s.begin());
        s.erase(item);
        tot += item;
        item = *(s.rbegin());
        s.erase(item);
        tot -= item;
        if(tot <= 0)
            return false;
    }
    return true;
}

int main()
{
    ifstream fin;
    fin.open("p105_sets.txt");
    if(!fin)
        cout << "ERROR!" << endl;
    set<int> s;
    char delim;
    int temp, tot = 0, n = 0;
    while(fin >> temp)
    {
        n++;
        s.clear();
        s.insert(temp);
        while(fin.peek() == ',')
        {
            fin >> delim >> temp;
            s.insert(temp);
        }

        cout << n << endl;
        cout << "set_diff " << set_diff(s) << endl;
        cout << "set_half_greater " << set_half_greater(s) << endl;
        if(!set_diff(s) && set_half_greater(s))
        {
            cout << "set " << n << " was good" << endl;
            tot += total(s);
        }

    }
    cout << "the total of good sets elements was " << tot << endl;
    return 0;
}

