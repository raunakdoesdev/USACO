/*
ID: sauhaar1
PROG: fence6
LANG: C++
*/

#include <fstream>
#include <cstring>
#include <queue>

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MIN(a, b) (((a)<(b)) ? (a) : (b))
#define MAX_N 100

using namespace std;

struct line{
    int len;
    bool adj[2][MAX_N + 1];
}pasture[MAX_N + 1];

struct vis{
    bool v[MAX_N + 1];
    vis(){
        memset(v, 0, sizeof(v));
    }
};

int n;

int minPerim = 1 << 20;

void dfs(int originalFence, int originalSide, int lastEdge, int currentEdge, int perimeter, vis visited){
    if(pasture[originalFence].adj[!originalSide][currentEdge]){ // if we are rerouted to the start
        minPerim = MIN(minPerim, perimeter + pasture[currentEdge].len);
        return;
    }

    if(visited.v[currentEdge]++)
        return;
    
    int whichSide = (currentEdge == originalSide) ? originalSide : ((pasture[currentEdge].adj[0][lastEdge]) ? 1 : 0); // which side to search

    perimeter += pasture[currentEdge].len;

    REP(i, 1, n + 1)
        if(pasture[currentEdge].adj[whichSide][i] && i != originalSide)
            dfs(originalFence, originalSide, currentEdge, i, perimeter, visited);
}


int main() {

    ofstream cout ("fence6.out");
    ifstream cin ("fence6.in");
    
    int id, len, lft, rht, tmp;

    cin >> n;

    REP(i, 1, n + 1){
        cin >> id >> len >> lft >> rht;
        pasture[id].len = len;
        memset(pasture[id].adj, 0, sizeof(pasture[id].adj)); // clear adjacency matrix
        REP(j, 0, lft){
            cin >> tmp;
            pasture[id].adj[0][tmp] = true;
        }
        REP(j, 0, rht){
            cin >> tmp;
            pasture[id].adj[1][tmp] = true;
        }
    }

    REP(i, 1, n+1)
        dfs(i, 0, -1, i, 0, vis());

    cout << minPerim << endl;

    return 0;
}
