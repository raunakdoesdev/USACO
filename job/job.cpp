/*
ID: sauhaar1
PROG: job
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#include <fstream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ofstream cout ("job.out");
    ifstream cin ("job.in");

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    int a[m1], b[m2];
    int aTime[m1], bTime[m2];

    REP(i, 0 , m1)
        cin >> a[i];
    REP(i, 0 , m2)
        cin >> b[i];
    
    vector<int> sortedATimes;

    memset(aTime, 0, sizeof(aTime)); 
    REP(i, 0, n){
        int minTime = INT_MAX, minIndex = -1;
        REP(j, 0, m1){
            if(aTime[j] + a[j] < minTime){
                minTime = aTime[j] + a[j];
                minIndex = j;
            }
        }
        aTime[minIndex] = minTime;
        sortedATimes.push_back(minTime);
    }
    
    int aFinishTime = 0;
    REP(i, 0, m1) aFinishTime = MAX(aFinishTime, aTime[i]);

    vector<int> sortedBTimes;

    memset(bTime, 0, sizeof(bTime)); 
    REP(i, 0, n){
        int minTime = INT_MAX, minIndex = -1;
        REP(j, 0, m2){
            if(bTime[j] + b[j] < minTime){
                minTime = bTime[j] + b[j];
                minIndex = j;
            }
        }
        bTime[minIndex] = minTime;
        sortedBTimes.push_back(minTime);
    }

    sort(sortedATimes.begin(), sortedATimes.end());
    sort(sortedBTimes.begin(), sortedBTimes.end());

    int totalMaxTime = 0;

    REP(i, 0, n){
        totalMaxTime = MAX(totalMaxTime, sortedATimes[i] + sortedBTimes[n - 1 - i]);
    }

    cout << aFinishTime << " " << totalMaxTime << endl;
    

    return 0;
}
