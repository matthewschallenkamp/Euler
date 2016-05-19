#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

//1, 0, 0, 0, 0, 1, th prime

int main()
{
    for(int a = 1; a < 1000 -1; a++)
        for(int b = a; b < 1000; b++)
    {
        if(((a * a) + (b * b)) == (1000 - a - b) * (1000 - a - b))
            cout << "A triplet was " << a << " " << b << " " << (1000 - a - b) << " = " << (1000 - a - b) *a *b << endl;
    }
    return 0;
}
