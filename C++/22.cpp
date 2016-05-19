#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

long long stringval(string s)
{
    long long sum = 0;
    for(char c : s)
    {
        sum += c - 'A' + 1;
    }
    return sum;
}

int main()
{
    //note that i changed names.txt, removing "" and turning , into spaces
    ifstream fin;
    /*while(1)
    {
        string s;
        cin >> s;
        cout << stringval(s) << endl;
    }
    */fin.open("names.txt");
    if(!fin.is_open())
        return 0;
    string str;
    vector<string> s;
    while(fin >> str)
        s.push_back(str);
    sort(s.begin(), s.end());
    long long sum = 0;
    for(int i = 1; i <= s.size(); i++)
    {
        sum += stringval(s[i-1]) * i;
    }
    cout << "the sum was" << sum;
    return 0;
}
