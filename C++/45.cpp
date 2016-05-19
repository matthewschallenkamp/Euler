#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;

long long triangle(long long n)
{
    return n*(n+1)/2;
}

long long pentagonal(long long n)
{
    return n*(3*n - 1)/2;
}

long long hexagonal(long long n)
{
    return n*(2*n - 1);
}

int main()
{
    int hex_index = 0, pent_index = 0;
    for(long long i = 286; i < 10000000; i++)
    {
        for(;hexagonal(hex_index) < triangle(i); hex_index++);
        for(;pentagonal(pent_index) < triangle(i); pent_index++);
        if(hexagonal(hex_index) == pentagonal(pent_index) &&
           triangle(i) == hexagonal(hex_index))
            cout << "The next hex/pentagonal triangle is " << triangle(i) << endl;
    }
    return 0;
}
