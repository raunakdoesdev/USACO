/*
ID: sauhaar1
PROG: stall4
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#include <fstream>
#include <cstring>
#include <climits>

using namespace std;

int adj[500][500];
ofstream cout ("stall4.out");
ifstream cin ("stall4.in");

int networkFlow(int source, int drain, int nodes) {

    int totalFlow = 0, maxFlow, maxLoc, prevNode[nodes], flow[nodes];
    bool visited[nodes];

    while(true){
        memset(prevNode, -1, sizeof(prevNode));
        memset(visited, 0, sizeof(visited));
        memset(flow, 0, sizeof(flow));
        flow[source] = INT_MAX;
        while(true){
            maxFlow = 0;
            maxLoc = INT_MIN;
            REP(i, 0, nodes){
                if(flow[i] > maxFlow && !visited[i]){
                    maxFlow = flow[i];
                    maxLoc = i;
                }
            }
            if(maxLoc == INT_MIN || maxLoc == drain)
                break;
            visited[maxLoc] = true;
            REP(i, 0, nodes){
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
        int pathCapacity = flow[drain];
        totalFlow += pathCapacity;
        int curNode = drain, nextNode;
        while(curNode != source){
            nextNode = prevNode[curNode];
            adj[nextNode][curNode] -= pathCapacity;
            adj[curNode][nextNode] = (adj[curNode][nextNode] == INT_MIN) ? pathCapacity : adj[curNode][nextNode] + pathCapacity;
            curNode = nextNode;
        }
    }

    return totalFlow;
}

int main(){


    int n, m;
    cin >> n >> m;

    REP(i, 0, n+m+2)
        REP(j, 0, n+m+2)
            adj[i][j] = INT_MIN;

    REP(i, 1, n+1)
        adj[0][i] = 1;
    REP(i, n+1, n+m+1)
        adj[i][n+m+1] = 1;
    REP(i, 0, n){
        int temp1, temp2;
        cin >> temp1;
        REP(j, 0, temp1){
            cin >> temp2;
            adj[i + 1][n+temp2] = 1;
        }
    }

    cout << networkFlow(0, n+m+1, n+m+2) << endl; 
}





