/*
ID: sauhaar1
PROG: kimbits
LANG: C++
*/

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>

using namespace std;

int main() {
    ofstream cout ("kimbits.out");
    ifstream cin ("kimbits.in");

    int N, // number of bits
        L; // max bits on
    long long I; // which bit string to print

    cin >> N >> L >> I;
    
    long long numBins[32][32]; // Number of possible binaries with index1 digits
                               // and index2 set bits

    REP(i, 0, N+1){
        numBins[i][0] = 1;
        numBins[0][i] = 1;
    }

    REP(i, 1, N+1)
        REP(j, 1, L+1)
            numBins[i][j] = numBins[i-1][j] + numBins[i-1][j-1];
    
    string answer = string(N, ' ');
    int setBitsLeft = L;
    
    REP(i, 0, N){
        int len = N - i;
        int numBinsPossible = numBins[len - 1][setBitsLeft]; // number of binaries possible
        if(numBinsPossible < I){
            answer[i] = '1';
            setBitsLeft--;
            I -= numBinsPossible;
        }else answer[i] = '0';
    }

    cout << answer << endl;

    return 0;
}
