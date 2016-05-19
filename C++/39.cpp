#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

using namespace std;
int main()
{
    long long best_perim = 0;
    long long num_solutions = 0;

    for(int perimeter = 4; perimeter <= 1000; perimeter++)
    {
        int solutions = 0;
        for(int a = 1; a < perimeter; a++)
            for(int b = 1; b < a && b+a+1 < perimeter; b++)
        {
            int c = perimeter - a - b;
            {
                if(a * a == b * b + c * c)
                {
                    cout << perimeter << ": " << a << " " << b << " " << c << endl;
                    solutions++;
                }
            }
        }
        if(solutions > num_solutions)
        {
            num_solutions = solutions;
            best_perim = perimeter;
        }
    }

    cout << "the best perimeter was " << best_perim << endl;
    cout << "with a count of " << num_solutions << endl;

    return 0;
}
