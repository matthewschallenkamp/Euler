#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> digitize(int n);
int factorial(int n);
int sum_factorials(vector<int> v);


int main()
{
    vector<int> v;
    int total = 0;
    int step;
    for(int i = 1; i < 1000000; i++)
    {
        //cout << "here" << endl;
        v.clear();
        v.push_back(i);
        step = sum_factorials(digitize(i));
        //cout << "Chaining from " << i;
        while((find(v.begin(), v.end(), step) == v.end()))
        {
            //cout << "did not find " << step << endl;
            v.push_back(step);
            step = sum_factorials(digitize(step));
        }
        if(v.size() == 60)
            total++;
        //cout << " gave " << v.size() << " stones" << endl;
    }
    cout << "there is a total of " << total << " chains with length 60" << endl;
    return 0;
}

int sum_factorials(vector<int> v)
{
    //cout << "summing" << endl;
    int total = 0;
    for(int i = 0; i < v.size(); i++)
        total += factorial(v.at(i));
    return total;
}

int factorial(int n)
{
    //cout << "factoring" << endl;
    int total = 1;
    for(int i = 1; i <= n; i++)
        total *= i;
    return total;
}

vector<int> digitize(int n)
{
    //cout << "digitizing" << endl;
    vector<int> v;
    while(n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    return v;
}
