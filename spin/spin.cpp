/*
ID: sauhaar1
PROG: spin
LANG: C++
*/

#define REP(i, a, b) \
    for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>
#include <bitset>

using namespace std;

int main() {

    ofstream cout ("spin.out");
    ifstream cin ("spin.in");

    bitset<360> wedges[5]; // Array of degree of wheel, 1 if open, 0 if blocked
    int speed[5]; // Speed of each wheel

    REP(i, 0, 5){
        int numWedges;
        cin >> speed[i] >> numWedges;
        REP(j, 0, numWedges){
            int start, length;
            cin >> start >> length;
            REP(k, start, start + length + 1){
                wedges[i].set(k % 360 , 1);
            }
        }
    }

    REP(t, 0, 1000){
        if((wedges[0] & wedges[1] & wedges[2] & wedges[3] & wedges[4]).any()){
            cout << t << endl;
            return 0;
        }
        REP(i, 0, 5){
            bitset<360> temp = wedges[i];
            REP(k, 0, 360){
                wedges[i].set((k + speed[i]) % 360, temp.test(k));
            }
        }
    }
    
    cout << "none" << endl;

    return 0;
}
