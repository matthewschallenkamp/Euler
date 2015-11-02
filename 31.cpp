#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

long long fill_pos(long long n, vector<long long> parts)
{
    static int indent = 0;

    //base cases
    if(parts.size() == 1)
        return 1;
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    int sum = 0;
    int rem = n - parts.back();

    sum = 0;
    sum += fill_pos(rem, parts);
    //with one of the first coin
    parts.pop_back();
    sum += fill_pos(n, parts);
    //with none of the first coin
    return sum;
}

int main()
{
    vector<long long> coinvals = {1,2,5,10,20,50,100,200};
    cout << "there are " << fill_pos(200, coinvals) << " possibilites for 200p"<< endl;
    return 0;
}
