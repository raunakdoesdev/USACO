/*
ID: sauhaar1
PROG: buylow
LANG: C++11
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n, stocks[5000];

struct bigint{
    int len = 0;
    vector<int> d;
    bigint(int l = 0) : len(l), d(500, 0) {}
};

string print(bigint a){
    string s = "";
    for(int i = a.len - 1; i >= 0; i--)
        s += to_string(a.d[i]);
    return s;
}

bigint add(bigint A, bigint B){
    bigint C = bigint();
    int carry = 0;
    for(int i = 0; i < MAX(A.len, B.len); i++){
        C.d[i] = A.d[i] + B.d[i] + carry;
        carry = C.d[i] / 10;
        C.d[i] %= 10;
    }
    if(carry != 0){
        C.d[MAX(A.len, B.len)] = carry;
        C.len = MAX(A.len, B.len) + 1;
    }else{
        C.len = MAX(A.len, B.len);
    }
    return C;
}

int main() {

    ofstream cout ("buylow.out");
    ifstream cin ("buylow.in");
    
    cin >> n;
    REP(i, 0, n) cin >> stocks[i];

    if(n == 1){
        cout << "1 1" << endl;
        return 0;
    }

    int dp[n];
    bigint numdp[n];
    REP(i, 0, n){
        numdp[i] = bigint(1);
        numdp[i].d[0] = dp[i] = 1;
    }

    set<int> used;
    for(int i = n - 2; i >= 0; i--){
        int maxPrev = 0;
        bigint numMax = bigint(1);
        numMax.d[0] = 1;
        for(int j = i + 1; j < n; j++){
            if(stocks[j] < stocks[i]){
                if(dp[j] > maxPrev){
                    maxPrev = dp[j];
                    numMax = numdp[j];
                    used.erase(used.begin(), used.end());
                    used.insert(stocks[j]);
                }else if(dp[j] == maxPrev && used.find(stocks[j]) == used.end()){ // not used yet and same as max
                    numMax = add(numMax, numdp[j]);
                    used.insert(stocks[j]);
                }
            }
        }
        dp[i] = maxPrev + 1;
        numdp[i] = add(bigint(0),numMax);
    }

    int maxLen = 0;
    bigint numSols = 1;
    numSols.d[0] = 1;
    REP(i, 0, n){
        if(dp[i] > maxLen){
            maxLen = dp[i];
            numSols = numdp[i];
            used.erase(used.begin(), used.end());
            used.insert(stocks[i]);
        }else if(dp[i] == maxLen && used.find(stocks[i]) == used.end()){
            numSols = add(numSols, numdp[i]);
            used.insert(stocks[i]);
        }
    }

    cout << maxLen << " " << print(numSols) << endl;

    return 0;
}
