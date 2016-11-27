/*
ID: sauhaar1
PROG: race3
LANG: C++11
 */

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) 

#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int n = 0; // total number of arrows
int numPaths = 0;
int adj[50][50];
int visitCount[50];
bool visited2[50];
long long thehammer = 0;

ofstream cout ("race3.out");
ifstream cin ("race3.in");

void dfs(int start, bool visited[],int end){
    if(start == end){
        if(thehammer > 1000000){
            cout << "0\n0\n";
            exit(0);
        }else{
            thehammer++;
        }
        REP(i, 0, n){
            if(visited[i] && i != end)
                visitCount[i]++; // increments the visits for each visited node
        }
        numPaths++; // every path will end at the end
        return;
    }

    bool die = true;
    REP(i, 0, n){
        if(adj[start][i] != 0 && i != start && !visited[i]){
            // cout << start << " --> " << i << endl;
            visited[i] = true;
            visited2[i] = true;
            dfs(i, visited, end);
            visited[i] = false;
        }
    }
}

int main() {

    int temp;

    while(cin >> temp && temp != -1){
        if(temp == -2){
            n++;
            continue;
        }
        adj[n][temp] = 1;
    }

    bool test = true;
    REP(i, 0, n){
        if(adj[i][n-1])
            test = false;
    }

    bool visited[n];
    memset(visited, 0, sizeof(visited));
    visited[0] = true;
    memset(visitCount, 0, sizeof(visitCount));
    thehammer = 0;
    dfs(0, visited, n-1);

    int manditoryPoints = 0;

    string s = "";
    bool mandatory[n];

    memset(mandatory, 0, sizeof(mandatory));

    REP(i, 0, n){
        if(visitCount[i] == numPaths && i != 0 && i != n - 1){
            manditoryPoints++;
            mandatory[i] = true;
            s += " " + to_string(i);
        }
    }

    cout << manditoryPoints << s << endl;


    int count = 0;
    s = "";

    REP(i, 1, n - 1){ // run dfs on every two courses
        if(!mandatory[i])
            continue;

        memset(visited, 0, sizeof(visited));
        memset(visited2, 0, sizeof(visited));
        memset(visitCount, 0, sizeof(visitCount));
        visited2[0] = true;
        visited[0] = true;
        thehammer = 0;

        dfs(0,visited,i); 

        bool visited1[n];
        memset(visited1, 0, sizeof(visited1));

        REP(j, 0, n)
            visited1[j] = visited2[j]; 

        memset(visited, 0, sizeof(visited));
        memset(visitCount, 0, sizeof(visitCount));
        memset(visited2, 0, sizeof(visited));
        visited2[i] = true;
        visited[i] = true;
        thehammer = 0;

        dfs(i, visited, n - 1);

        bool course = true;

        REP(j, 0, n){
            if(visited1[j] && visited2[j] && j != i){
                course = false;
                break;
            }
        }

        if(course){
            count++;
            s += " " + to_string(i);
        }
    }

    cout << count << s << endl;
    return 0;
}
