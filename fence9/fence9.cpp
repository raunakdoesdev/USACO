/*
ID: sauhaar1
PROG: fence9
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!


#include <fstream>
#include <math.h>



using namespace std;

int main() {

    ofstream cout ("fence9.out");
    ifstream cin ("fence9.in");
    
    double n, m, p;
    int cows = 0;

    cin >> n >> m >> p;
    
    REP(i, 1, m){ // move down triangle vertically
        int left = floor(i * n / m) + 1, right;
        if( n == p) right = p - 1;
        else right = ceil(p + (n - p) * i / m) - 1;
        cows += right - left + 1;
    }

    cout << cows << endl;

    return 0;
}
