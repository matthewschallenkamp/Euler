#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

vector<int> digits(int n)
{
    vector<int> m;
    while(n > 0)
    {
        m.push_back(n % 10);
        n /= 10;
    }
    return m;
}

int number(vector<int> m)
{
    int n = 0;
    while(m.size())
    {
        n *= 10;
        n += m.back();
        m.pop_back();
    }
    return n;
}

bool same_digits(long long a, long long b)
{
    vector<int> da = digits(a), db = digits(b);
    for(auto take : da)
    {
        bool found = 0;
        for(auto &from : db)
        {
            if(take == from)
            {
                found = 1;
                from = -1;
                break;
            }
        }
        if(!found)
            return 0;
    }
    for(auto test : db)
    {
        if(test != -1)
            return 0;
    }
    return 1;
}

int main()
{
    bool found = 0;
    for(long long num = 1; !found; num++)
    {
        bool works = 1;
        for(int multiple = 2; multiple < 7; multiple++)
        {
            if(!same_digits(num, num*multiple))
                works = 0;
        }
        if(works)
        {
            found = true;
            cout << "found it " << num;
        }
    }
    return 0;
}
