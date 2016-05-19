#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


//how many n digit numbers are a n digit power?
//if x^n has n digits, x < 10 and x >= 1
//
using namespace std;

int digits(double n)
{
    long long count = 0;
    while ( n > 0.9 )
    {
        n /= 10;
        count++;
    }
    return count;
}

int main()
{
    long long total = -1;
    long long j = 1;
    for(long long i = 1; j != 0; i++ )
    {
        for(j = 1; j == digits(pow(i, j)); j++)
        {
            cout << i << " to the power of " << j << " was " << pow(i,j)
                << " with " << digits(pow(i, j)) << " digits" << endl;
            total++;
        }
        cout << i << " to the power of " << j << " was " << pow(i,j)
                << " with " << digits(pow(i, j)) << " digits" << endl;
        j--;
    }
    cout << "there were " << total << " numbers total" << endl;
    return 0;
}
