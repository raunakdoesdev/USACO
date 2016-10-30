/*
ID: sauhaar1
PROG: stamps
LANG: C++
*/

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>

using namespace std;

int stamps[50];
int dp[2000000]; // index is sum of stamps, value is num stamps used

int main() {
    ofstream cout ("stamps.out");
    ifstream cin ("stamps.in");

    int n, k;
    cin >> k >> n;

    REP(i, 0, n){
        cin >> stamps[i];
    }

    REP(i, 1, k*10000 + 1){
        dp[i] = k*10000;
        REP(j, 0, n){
            if(stamps[j] <= i)
                if(dp[i] > dp[i - stamps[j]])
                    dp[i] = dp[i - stamps[j]] + 1;
        }
        if(dp[i]>k) {
            cout << i - 1 << endl;
            break;
        }
    }

    return 0;
}
