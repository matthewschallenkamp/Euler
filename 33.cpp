#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long totient(long long a, long long b)
{
    //cout << "b " << b << endl << "a " << a << endl;
    if(b == 0)
        return a;
    return totient(b, a % b);
}

int main()
{
    long long ttop = 1, tbot = 1, tot;

    //ok, so we have a middle digit, a top and a bottom
    //this gives us the 3 forms t/b =
    //10m+t/10m+b
    //10t+m/10b+m
    //10m+t/10b+m
    //10t+m/10m+b
    //which then gives the forms
    //t(10m+b) or t(10b+m)
    //==
    //b(10m+t) or b(10t+m)
    //and we will say top < bot to remove duplicates

    for(int mid = 1; mid < 10; mid++)
    {
        for(int bot = 1; bot < 10; bot++)
        {
            for(int top = 1; top < bot; top++)
            {
                if(((top*(10*bot + mid)) == (bot*(10*mid + top)))
                    || ((top*(10*mid + bot)) == (bot*(10*mid + top)))
                    || ((top*(10*bot + mid)) == (bot*(10*top + mid)))
                    || ((top*(10*mid + bot)) == (bot*(10*top + mid))))
                {
                    if(top != bot)
                    {
                        cout << top << "  " << mid << "  " << bot << endl;
                        ttop *= top;
                        tbot *= bot;
                        cout << ttop << "  " << tbot << endl;
                    }
                    tot = totient(ttop, tbot);
                    tbot /= tot;
                    ttop /= tot;
                }
            }
        }
    }

    cout << "the solution was " << tbot << endl;


    return 0;
}
