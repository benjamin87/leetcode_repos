/*
ID: 
TASK: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#define maxn 11
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n;
int ans[7]; // 0 - Sat
int m[12] = {31,31,28,31,30,31,30,31,31,30,31,30};

bool is_leap(int y)
{
    if(y % 100 == 0)
    {
        return y % 400 == 0;
    }
    else
    {
        return y % 4 == 0;
    }
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    fin >> n;
    
    int day = 4;    // 1899/12/13 was Wed
    int rd,d;
    for (size_t i = 1900; i <= 1900 + n - 1; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            d = m[j];
            if(j == 2 && is_leap(i))
            {
                d++;
            }
            rd = d % 7;
            day += rd;
            day %= 7;
            ++ans[day];
        }
    }

    for (size_t i = 0; i < 6; i++)
    {
        fout << ans[i] << " ";
    }
    fout << ans[6] << endl;
    
    return 0;
}