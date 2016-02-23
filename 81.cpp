#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include "BigInt.h"

using namespace std;

long long min_ignore_zeros(long long a, long long b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    return min(a,b);
}

int main()
{
    string i, m;
    ifstream fin;
    //ofstream fout;
    //fout.open("out.out");
    fin.open("p081_matrix.txt");
    long long matrix[81][81] = {}; //one larger than we need so the zeroes are easy.
    for(int i = 0; i < 80; i++)
    {
        for(int j = 0; j < 80; j++)
        {
            fin >> matrix[i][j];
        }
    }

    for(int sum = 160 - 3; sum >= 0; sum--)
    {
        /*for(int i = 0; i < 80; i++)
        {
            for(int j = 0; j < 80; j++)
            {
                fout << matrix[i][j] << " ";
            }
            fout << endl;
        }
        fout << endl << endl;*/
        for(int x = 0; x <= sum; x++)
        {
            int y = sum - x;
            if((x < 80) && (y < 80))
            {
                matrix[x][y] += min_ignore_zeros(matrix[x+1][y], matrix[x][y+1]);
            }
        }
    }

    cout << "the shortest path was " << matrix[0][0] << endl;

    return 0;
}

