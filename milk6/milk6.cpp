/*
ID: sauhaar1
PROG: milk6
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#include <fstream>
#include <cstring>
#include <utility>
#include <climits>
#include <set>

using namespace std;

typedef pair<int, int> sdp; // source destination pair
typedef pair<int, pair<sdp, int> > edge;

int adj[50][50];
ofstream cout ("milk6.out");
ifstream cin ("milk6.in");

int networkFlow(int source, int drain, int nodes) {
    
    int a[nodes][nodes];
    REP(i, 0, nodes)
        REP(j, 0, nodes)
            a[i][j] = adj[i][j];

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
                if(a[maxLoc][i] != INT_MIN){
                    if(flow[i] < MIN(maxFlow, a[maxLoc][i])){
                        prevNode[i] = maxLoc;
                        flow[i] = MIN(maxFlow, a[maxLoc][i]);
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
            a[nextNode][curNode] -= pathCapacity;
            a[curNode][nextNode] = (a[curNode][nextNode] == INT_MIN) ? pathCapacity : a[curNode][nextNode] + pathCapacity;
            curNode = nextNode;
        }
    }

    return totalFlow;
}

int main(){
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    
    REP(i, 0, numNodes + 1){
        REP(j, 0, numNodes + 1){
            adj[i][j] = INT_MIN;        
        }
    }
    
    int s, e, c;
    set<edge> edges;
    REP(i, 0, numEdges){
        cin >> s >> e >> c;
        if(adj[s][e] != INT_MIN) adj[s][e] += c;
        else adj[s][e] = c;
        edges.insert(edge(-c, make_pair(make_pair(s, e), i + 1)));
    }

    int flow = networkFlow(1, numNodes, numNodes+1);
    set<int> answer;
    int price = 0;

    for(set<edge>::iterator it=edges.begin(); it != edges.end(); it++){
        c = -(*it).first;
        s = (*it).second.first.first;
        e = (*it).second.first.second;

        adj[s][e] = (adj[s][e] == c) ? (INT_MIN) : (adj[s][e] - c);
        int newFlow = networkFlow(1, numNodes, numNodes+1);

        if(flow - newFlow == c){
            price += c;
            answer.insert((*it).second.second); 
            flow = newFlow;
        }else // revert
            adj[s][e] = (adj[s][c] == INT_MIN) ? (c) : (adj[s][e] + c);
    }
    cout << price << " " << answer.size() << endl;

    for(set<int>::iterator it=answer.begin(); it != answer.end(); it++)
        cout << (*it) << endl;
}
