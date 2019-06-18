/*
ID: 
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#define maxn 11
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string f[maxn];
int money[maxn];
int num;
void update(string name, int a)
{
    for (size_t i = 0; i < num; i++)
    {
        if(f[i] == name)
        {
            money[i] += a;
            return;
        }
    }
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    fin >> num;
    for (size_t i = 0; i < num; i++)
    {
        fin >> f[i];
    }
    
    int m,n,e,r;
    string my, other;
    for (size_t i = 0; i < num; i++)
    {
        fin >> my;
        fin >> m >> n;
        e = n != 0 ? m / n : 0;
        update(my, -e * n);
        for (size_t k = 0; k < n; k++)
        {
            fin >> other;
            update(other, e);
        }
    }

    for (size_t i = 0; i < num; i++)
    {
        fout << f[i] << " " << money[i] << endl;
    }

    return 0;
}