#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//summing diagonal spirals

int main()
{
    long long c = 1;
    long long sum = 1;
    for(int side = 3; side <= 1001; side+= 2)
    {
        for(int i = 0; i < 4; i++)
        {
            c+= side-1;
            sum += c;
        }
    }
    cout << "the sum was " << sum;

    return 0;
}
