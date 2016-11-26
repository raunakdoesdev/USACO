/*
ID: sauhaar1
PROG: ditch
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#include <fstream>
#include <cstring>
#include <climits>

using namespace std;

int main() {

    ofstream cout ("ditch.out");
    ifstream cin ("ditch.in");

    int n, m; // n = num edges, m = num nodes
    cin >> n >> m;

    int adj[m+1][m+1]; // adjacency matrix with weights

    REP(i, 0, m+1)
        REP(j, 0, m+1)
            adj[i][j] = INT_MIN;

    REP(i, 0, n){
        int s, e, c;
        cin >> s >> e >> c;
        adj[s][e] = (adj[s][e] == INT_MIN) ? c : adj[s][e] + c;
    }

    int totalFlow = 0, maxFlow, maxLoc, prevNode[m+1], flow[m+1];
    bool visited[m+1];

    while(true){
        memset(prevNode, -1, sizeof(prevNode));
        memset(visited, 0, sizeof(visited));
        memset(flow, 0, sizeof(flow));
        flow[1] = INT_MAX;
        while(true){
            maxFlow = 0;
            maxLoc = INT_MIN;
            REP(i, 1, m+1){
                if(flow[i] > maxFlow && !visited[i]){
                    maxFlow = flow[i];
                    maxLoc = i;
                }
            }
            if(maxLoc == INT_MIN || maxLoc == m)
                break;
            visited[maxLoc] = true;
            REP(i, 1, m+1){
                if(adj[maxLoc][i] != INT_MIN){
                    if(flow[i] < MIN(maxFlow, adj[maxLoc][i])){
                        prevNode[i] = maxLoc;
                        flow[i] = MIN(maxFlow, adj[maxLoc][i]);
                    }
                }
            }
        }
        if(maxLoc == INT_MIN) // no path
            break;
        int pathCapacity = flow[m];
        totalFlow += pathCapacity;
        int curNode = m, nextNode;
        while(curNode != 1){
            nextNode = prevNode[curNode];
            adj[nextNode][curNode] -= pathCapacity;
            adj[curNode][nextNode] = (adj[curNode][nextNode] == INT_MIN) ? pathCapacity : adj[curNode][nextNode] + pathCapacity;
            curNode = nextNode;
        }
    }

    cout << totalFlow << endl;

    return 0;
}
