/*
ID: your_id_here
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    fin >> a >> b;
    int sum = 1;
    for(int i=0; i < a.length(); ++i)
    {
        // str to int
        sum *= a[i] - 'A' + 1;
    }
    int ma, mb;
    ma = sum % 47;

    sum =1;
    for(int i = 0; i < b.length(); ++i)
    {
        sum *= b[i] - 'A' + 1;
    }
    mb = sum % 47;

    if(ma == mb)
    {
        fout << "GO" << endl;
    }
    else
    {
        fout << "STAY" << endl;
    }
    
    
    return 0;
}