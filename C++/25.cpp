#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    long long a = 1, b = 1, c = 1;
    int digits = 5;
    int i;
    for(i = 2; digits < 1000; i++)
    {
        //cout << i << ": " << a << endl;
        c = a;
        a = c + b;
        b = c;
        if(a >= 100000)
        {
            digits++;
            a /= 10;
            b /= 10;
        }
    }
    cout << "First one with " << digits << " digits was " << i;

    return 0;
}
