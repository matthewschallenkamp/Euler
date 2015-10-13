#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <gmp.h>

using namespace std;

void pilesm(int n, int m, mpz_t &out);
long long piles(long long n);
set<multiset<long long> > splits(long long s, long long n);

int main()
{
    int i;
    //long long n;
    mpz_t n;
    mpz_init(n);
    mpz_set_si(n, 1);
    set<multiset<mpz_t> > sms;

    for (i = 500; n != 0; i++)
    {
        cout << endl << "testing: " << i;
        pilesm(i,i, n);
        cout << " gave ";
        //n = piles(i);
        //cout << n;
        //n%=1000000;
        gmp_printf ("%Zd", n);
        mpz_mod_ui(n, n, 1000000);
    }
    return 0;
}
/*
i need to find the number of possible piles you can make out of something size n

strategy: max pile size
if we say the max pile size is top
then first we divide it mpz_to piles of size top, and a remainder
1 = 1
2 = 2
3 = 3
4 = 5
5 = 7

basing on how many splits there are
if there is 0, one possibility
if there is 1, then there is n-1
if there is 2, then there is sum 1..n-2 = n-1*n-2/2




1 2 3 5 7 11 17
*/
//splits - max method
void pilesm(int n, int m, mpz_t &out)
{
    mpz_t total;
    mpz_init (total);
    static mpz_t v[4000][4000];
    static bool init = true;
    static int big_call = 10;
    if(init)
    {
        for(int i = 0 ; i < 4000; i++)
            for(int j = 0; j < 4000; j++)
            {
                mpz_init(v[i][j]);
                mpz_set_ui(v[i][j], -1);
            }
        init = false;
    }
    if (n > big_call)
    {
        for(int i = 0; i < n-3; i++)
        {
            mpz_clear(v[n-3-i][i]);
         //   cout << "unset " << n-3-i << " " << i << endl;
        }
        big_call++;
    }

    if(mpz_cmp_ui(v[n][m], -1) != 0)
    {
        mpz_set(out, v[n][m]);
        return;
    }

    if(n <= 1)
    {
        mpz_set_si(out, 1);
        return;
    }
    if(m > n)
    {
        pilesm(n, n, v[n][m]);
        return;
    }
    for(int i = 1; i <= m; i++)
    {
        //calls are to:
        //n...n-max on x
        //i ..m on y
        pilesm(n - i, i, v[n-i][i]);
        //cout << "set " << n-i << " " << i << endl;
        mpz_add(total, total, v[n-i][i]);
    }
    mpz_set(v[n][m], total);
    mpz_set(out, total);
    return;
}

//splits - number method

set<multiset<long long> > splits(long long s, long long n)
{
    set<multiset<long long> > ms, tempsms;
    multiset<long long> tempms;
    if(s == 0)
    {
        tempms.insert(n);
        ms.insert(tempms);
    }
    else if(s >= n)
    {}
    else for(int splitpos = 1; splitpos < n; splitpos++)
    {
        tempsms = splits(s - 1, n - splitpos);
        for(auto &i : tempsms)
        {
            tempms = i;
            tempms.insert(splitpos);
            ms.insert(tempms);
        }
    }
    return ms;
}

long long piles(long long n)
{
    if( n == 0)
        return 0;
    if(n == 1)
        return 1;
    long long total (0);
    for(int s = 0; s < n; s++)
    {
        //push each possibility of combinations onto the set
        total += splits(s, n).size();
    }
    return total;
}

