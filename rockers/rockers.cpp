/*
ID: sauhaar1
PROG: rockers
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#include <fstream>

using namespace std;

bool set(int bit, int num){
    return (bool)((1 << bit) & num);
}

int main() {

    ofstream cout ("rockers.out");
    ifstream cin ("rockers.in");
    
    int n,t,m; // n songs, t minutes per disk, m disks
    cin >> n >> t >> m;
    
    int song[n];
    
    REP(i, 0, n)
        cin >> song[i];

    int maxTotal = 0;

    REP(i, 0, 1 << n){ // brute force algorithm
        int curCapacity = 0;
        int curDisk = 1;
        int total = 0;

        REP(j, 0, n){
            if((1 << j) & i){ // if the song is chosen
                if(song[j] <= t - curCapacity){ // if the cur disk can fit the song
                    total++;
                    curCapacity += song[j];
                }else if(curDisk < m && song[j] <= t){ // if we can use another disk
                    curCapacity = song[j];
                    curDisk++;
                    total++;
                }else{ // if we are out of disks
                    break;
                }
            }
        }

        maxTotal = MAX(maxTotal, total);
    }

    cout << maxTotal << endl;
    return 0;
}
