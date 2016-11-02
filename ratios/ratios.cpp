/*
ID: sauhaar1
PROG: ratios
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define REPL(i, a, b)     for (i = int(a); i < int(b); i++) // a to b, and variable i is already declared!

#include <fstream>

using namespace std;

int feed[4][3];

int findGoldenRatio(int totalAmount[3]){
    int golden;
    
    REP(i,0,3)
        if(feed[0][i] && totalAmount[i] % feed[0][i] != 0)
            return 0;

    if(feed[0][0] != 0)
        golden = totalAmount[0]/feed[0][0];
    else if(feed[0][1] != 0)
        golden = totalAmount[1]/feed[0][1];
    else if(feed[0][2] != 0)
        golden = totalAmount[2]/feed[0][2];
    else
        golden = 0;

    if(feed[0][0] * golden != totalAmount[0] ||
        feed[0][1] * golden != totalAmount[1] ||
        feed[0][2] * golden != totalAmount[2])
        return 0;

    return golden;
}

int main() {

    ofstream cout ("ratios.out");
    ifstream cin ("ratios.in");

    REP(i,0,4)
        REP(j,0,3)
            cin >> feed[i][j];

    int amount[3]; // How much of each type of feed we will be summing up.
    
    int goldenRatio = -1, minSum = 500;
    int finalAmount[3];

    REPL(amount[0],0,100)
    REPL(amount[1],0,100)
    REPL(amount[2],0,100){
        int totalAmount[3] = {0,0,0}; // How much of each component for the golden ratio
        REP(i,0,3)
            REP(j,0,3)
                totalAmount[j]+=feed[i+1][j]*amount[i];
        int ratio = findGoldenRatio(totalAmount);
        int sum = amount[0]+amount[1]+amount[2];
        if(sum < minSum && ratio){
            goldenRatio = ratio;
            minSum = sum;
            REP(i, 0 , 3)
                finalAmount[i] = amount[i];
        }
    }

    if(goldenRatio == -1)
        cout << "NONE" << endl;
    else{
        REP(i, 0, 3)
            cout << finalAmount[i] << " ";
        cout << goldenRatio << endl;
    }

    return 0;
}
