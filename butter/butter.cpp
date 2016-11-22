/*
ID: sauhaar1
PROG: butter
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define pii pair<int, int>

#include <fstream>
#include <algorithm>    // std::min
#include <set>    // std::min



using namespace std;

int numCows, numPastures, numPaths;
int cows[500]; // Pasture at which each cow is grazing
int path[802][802];
int total[802] = {0};

struct myOrder {
    bool operator() (const pii &a, const pii &b) {
        if (a.second!= b.second)
            return a.second < b.second;
        return a.first < b.first;
    }
};

void Dijkstra(int sourcePasture){
    int dist[numPastures];
    int used[numPastures];

    set<pii, myOrder > queue;

    dist[sourcePasture] = 0;
    
    REP(i, 1, numPastures + 1){
        dist[i] = path[sourcePasture][i];
        used[i] = 0;
    }

    queue.insert(pii(sourcePasture, 0));

    int cnt = 0;

    while(!queue.empty()){
        pii nearestNeighbor = *queue.begin();
        queue.erase(queue.begin());
        used[nearestNeighbor.first] = 1;
        cnt++;
        if(cnt==numPastures) break;
        REP(i, 1, numPastures + 1){
            if(dist[i]>=nearestNeighbor.second + path[nearestNeighbor.first][i] && path[nearestNeighbor.first][i] < 900000 && used[i]==0){
                dist[i] = nearestNeighbor.second + path[nearestNeighbor.first][i];
                queue.insert(pii(i, dist[i]));
            }
        }
    }

    REP(i, 1, numPastures + 1)
        total[i] += dist[i];
}

int main() {
    ofstream cout ("butter.out");
    ifstream cin ("butter.in");
    
    cin >> numCows >> numPastures >> numPaths;
    
    REP(i, 0, numCows)
        cin >> cows[i];
    REP(i, 1, numPastures + 1)
        REP(j, i+1, numPastures + 1)
            path[i][j] = path[j][i] = 900000;
    REP(i, 0, numPaths){
        int p1, p2, len;
        cin >> p1 >> p2 >> len;
        path[p1][p2] = min(path[p1][p2], len);
        path[p2][p1] = path[p1][p2];
    }
    REP(i, 1, numPastures + 1)
        path[i][i] = 0;
    
    int answer = 900000;

    REP(i, 0, numCows)
        Dijkstra(cows[i]);
    REP(i, 1, numPastures + 1){
        answer = min(answer, total[i]);
    }

    cout << answer << endl;

    return 0;
}
