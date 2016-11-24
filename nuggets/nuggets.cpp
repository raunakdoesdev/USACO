/*
ID: sauhaar1
PROG: nuggets
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>

using namespace std;

int gcf(int a, int b) {
    return b == 0 ? a : gcf(b, a % b);
}

int main() {

    ofstream cout ("nuggets.out");
    ifstream cin ("nuggets.in");

    int MAX = 100000;
    
    int n;
    int largest = 0;
    cin >> n;
    
    int input[n];
    REP(i, 0, n)
        cin >> input[i];
    
    bool flag = true;

    REP(i, 0, n)
        REP(j, i + 1, n)
            if(gcf(input[i], input[j]) == 1)
                flag = false;
    if(flag){
        cout << 0 << endl;
        return 0;
    }

    bool canSum[MAX + 1];
    
    canSum[0] = true;

    REP(i, 1, MAX + 1){
        REP(j, 0, n){
            if(i - input[j] >= 0 && canSum[i - input[j]]){
                canSum[i] = true;
                break;
            }
        }
        if(!canSum[i])
            largest = i;
    }

    cout << largest << endl;

    return 0;
}

