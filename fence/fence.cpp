/*
ID: sauhaar1
PROG: fence
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define BREP(i, a, b)     for (int i = int(a); i > int(b); i--) // a to b, and variable i is local!

#include <fstream>

using namespace std;

int adj[501][501], degree[501], circuitPos = 0, circuit[1025], numEdges;
void findCircuit(int node){
    if(!degree[node]) // No neighbors left
        circuit[circuitPos++] = node; // note that ++ returns value before increment
    else{
        REP(i, 1, 501) if(adj[node][i] > 0){
            adj[node][i]--, adj[i][node]--; // Removes edge
            degree[node]--, degree[i]--;
            findCircuit(i); // Recursion
        }
        circuit[circuitPos++] = node;
    }
    
}

int main() {

    ofstream cout ("fence.out");
    ifstream cin ("fence.in");

    cin >> numEdges;

    REP(i, 0, numEdges){
        int a, b;
        cin >> a >> b;
        degree[a]++, degree[b]++;
        adj[a][b]++, adj[b][a]++;
    }

    bool foundLoop = true;
    REP(i, 1, 501){
        if(degree[i]%2){ // if an odd degree, should be starting node
            findCircuit(i);
            foundLoop = false;
            break;
        }
    }
    if(foundLoop){
        REP(i, 1, 501){
            if(degree[i])
                findCircuit(i);
        }
    }

    BREP(i, numEdges, -1)
        cout << circuit[i] << endl;

    return 0;
}
