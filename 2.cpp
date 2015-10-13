#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


//how many n digit numbers are a n digit power?
//if x^n has n digits, x < 10 and x >= 1
//
using namespace std;


//sum of even fibonaccis under 4 mill
int main()
{
    long long total = 0;
    long long a = 1,b = 1,c = 1;
    while(b < 4000000)
    {
        c = b;
        b = a + b;
        a = c;
        cout << "fib " << b << endl;
        if(b % 2 == 0)
        {
            total += b;
        }
    }
    cout << "the total was " << total;
    return 0;
}
