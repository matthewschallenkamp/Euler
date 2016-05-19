#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip>
#include "BigInt.h"


#define LOG2(X) ((unsigned) (8*sizeof (ull) - __builtin_clzll((X)) - 1))

using namespace std;

typedef unsigned long long ull;

inline ull l2(ull n)
{
    return LOG2(n);
}

const ull modulo = 987654321;

ull P(ull p)
{
    //cout << p << " = " << bitset<sizeof(ull) * 8>(p) <<  endl;
    ull masked = 0x5555555555555555 & p;
    //cout << masked << " = " << bitset<sizeof(ull)* 8>(masked) <<  endl;
    ull other = 0xAAAAAAAAAAAAAAAA;
    //cout << other << " = " << bitset<sizeof(ull) * 8>(other) <<  endl;
    return p - ((masked + other) % (1 << (l2(p))));
}

ull s(ull p)
{
    ull tot = 0;
    for(ull i = 1; i <= p; i++)
    {
        //if(!(i % 10000000))
          //  cout << i << endl;
        tot += P(i);
    }
    return tot;
}

ull ipow(ull num, ull pow)
{
    if(pow <= 0)
        return 1;
    ull part = ipow(num, pow/2);
    return part * part * ((pow % 2) ? num : 1);
}

ull spow2(ull power)
{
    if(power <= 1)
        return 4;
    ull top = (2 * spow2(power - 1)) % modulo;
    ull platform = (1 << (power - 1)) * (1 << (power - 1 + (power % 2))) % modulo;
    return top + platform % modulo;
}

ull spow_halfofnext(ull power)
{
    if(power <= 1)
        return 4;
    ull platform = (1-(power % 2)) * (1 << (power)) * (1 << (power));
    return (spow2(power) + platform) % modulo;
}

ull spow(ull num)
{
    ull power = l2(num+1) - 1;
    ull total = 0, total2 = 0, i;
    while(power >= 1)
    {
        total += spow2(power);
        total %= modulo;
        power--;
    }
    power = l2(num+1);
    i = ipow(2, power);
    if(num > ((ipow(2, power) * 3) / 2))
    {
        //cout << "did the half thing " << endl;
        i *= 3;
        i /= 2;
        total += spow_halfofnext(power-1);
        total %= modulo;
    }
    //cout << "power two part " << total << endl;
    //cout << "starting " << i << endl;
    for(; i <= num; i++)
    {
        if(!(i % 100000000))
            cout << i << endl;
        total2 += P(i);
        total2 %= modulo;
    }
    //cout << "other part " << total2 <<endl;
    return (total + total2 + 1) % modulo;
}

int main()
{
    /*
    for(long long p2 = 2; p2 < 100000000; p2 *= 2)
    {
        cout << "n * n+1 / 4 = " << p2 * (p2+1) / 4 << endl;
        cout << "S(" << p2-1 << ") = " << s(p2-1) << endl;
        cout << "S(" << p2 << ") = " << s(p2)<< endl;
        cout << "S(" << p2+1 << ") = " << s(p2+1)<< endl << endl;
    }*//*
    ull sp2 = 1;
    for(ull i = 2; i < 1000000; i++)
    {
        if(!(i % 1000))
            cout << i << endl;
        ull sp = spow(i);
        sp2 += P(i);
        sp2 %= modulo;
        if(sp != sp2)
        {
            cout << "ERROR!" << endl;
            cout << sp << " != " << sp2 << endl;
        }
    }*/

    cout << spow(1000000000000000000) << endl;

    //cout << "the total was " << tot << endl;

    return 0;
}

