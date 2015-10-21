#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

//naive
int divisors(int n)
{
    int div = 1;
    for(int i = 2; i < sqrt(n); i++)
    {
        if(n % i == 0)
            div++;
    }
    return 2*div;
}


int main()
{
    long long triangle = 1;
    int div = 0;
    for(int i = 2; div < 500; i++)
    {
        triangle += i;
        div = divisors(triangle);
    }
    cout << "the triangle was " << triangle << " with " << div << " divisors" << endl;
    return 0;
}
