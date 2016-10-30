/*
ID: sauhaar1
PROG: fact4
LANG: C++
*/

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>

using namespace std;

int main() {

    int n; // will be calculating factorial of n

    ofstream cout ("fact4.out");
    ifstream cin ("fact4.in");

    cin >> n;
    
    int lastNonZeroDigit = 1; //last nonzero digit in factorial
    
    REP(i, 2, n+1){
        lastNonZeroDigit *= i;
        while(lastNonZeroDigit%10==0)
            lastNonZeroDigit /= 10;
        lastNonZeroDigit %= 10000;
    }
    
    cout << lastNonZeroDigit%10 << endl;
    return 0;
}
