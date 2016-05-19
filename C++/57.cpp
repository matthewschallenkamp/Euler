#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include "BigInt.h"
#include "BigInt.cpp"

using namespace std;

struct frac
{
    BigInt num = 1, denom = 1;
};

ostream &operator<<(ostream &out, frac f)
{
    out << f.num << " / " << f.denom;
    return out;
}

frac reciprocal(frac f)
{
    auto temp = f.num;
    f.num = f.denom;
    f.denom = temp;
    return f;
}

frac operator+(frac f, long long a)
{
    //cout << "before " << f << endl;
    auto temp = (f.denom * a);
    //cout << "to add to top " << temp << endl;
    auto temp2 = temp + f.num;
    //cout << "added to top " << temp2 << endl;
    f.num = temp2;
    //cout << "assigned to top " << f << endl;
    return f;
}

frac frac_from_seq(vector<long long> seq)
{
    frac f;
    f.num = 0;
    f.denom = 1;
    for(int i = seq.size() - 1; i >= 0; i--)
    {
        //cout << "seq " << i << ": " << seq[i] << " | ";
        f = f + seq[i];
        //cout << f << " | ";
        f = reciprocal(f);
        //cout << f << endl;
    }
    f = reciprocal(f);
    //reduce(f);
    return f;
}
int main()
{
    //going for sqrt 2
    vector<long long> seq = {1};
    int c = 0;
    for(int i = 0; i < 1000; i++)
    {
        cout << i << endl;
        seq.push_back(2);
        frac f = frac_from_seq(seq);
        if(f.num.log10() > f.denom.log10()) c++;
    }
    cout << c << endl;
}
