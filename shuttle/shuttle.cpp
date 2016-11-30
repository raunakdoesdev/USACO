/*
ID: sauhaar1
PROG: shuttle
LANG: C++
 */

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>
#include <vector>
#include <stdlib.h>
#include <climits>

using namespace std;

int length;
string goalState;
vector<int> steps;
bool killSwitch = false;

// -1 can only move to the right and 1 can only move to the left

bool dfs(string state, int blankSpace){
    if(killSwitch) return false;
    if(state == goalState){
        killSwitch = true;
        return true;
    }

    string tempState;

    if(blankSpace > 1 && state[blankSpace - 2] == 'W' && state[blankSpace - 1] == 'B'){
        tempState = state;
        tempState[blankSpace - 2] = ' '; 
        tempState[blankSpace] = 'W';

        bool works = dfs(tempState, blankSpace - 2);
        if(works){
            steps.push_back(blankSpace - 1);
            return true;
        }
    }

    if(blankSpace > 0 && state[blankSpace - 1] == 'W'){
        tempState = state;
        tempState[blankSpace - 1] = ' '; 
        tempState[blankSpace] = 'W';

        bool works = dfs(tempState, blankSpace - 1);

        if(works){
            steps.push_back(blankSpace);
            return true;
        }
    }

    if(blankSpace < length - 1 && state[blankSpace + 1] == 'B' ){
        tempState = state;
        tempState[blankSpace + 1] = ' '; 
        tempState[blankSpace] = 'B';

        bool works = dfs(tempState, blankSpace + 1);

        if(works){
            steps.push_back(blankSpace + 2);
            return true;
        }
    }

    if(blankSpace < length - 2 && state[blankSpace + 1] == 'W' && state[blankSpace + 2] == 'B'){
        tempState = state;
        tempState[blankSpace + 2] = ' '; 
        tempState[blankSpace] = 'B';

        bool works = dfs(tempState, blankSpace + 2);

        if(works){
            steps.push_back(blankSpace + 3);
            return true;
        }
    }

    return false;
}

int main() {

    ofstream cout ("shuttle.out");
    ifstream cin ("shuttle.in");

    int n;
    cin >> n;

    length = 1 + (2*n);

    string initialState = "";

    REP(i, 0, n){
        initialState += 'W';
        goalState += 'B';
    }

    initialState += ' ';
    goalState += ' ';

    REP(i, n + 1, 2*n + 1){
        initialState += 'B';
        goalState += 'W';
    }

    dfs(initialState, n); // should find the answer

    int ansNum = 0;
    for(int i = steps.size() - 1; i > -1; i--){
        if(ansNum != 0 && ansNum%20 == 0)
            cout << endl;
        else if(ansNum != 0)
            cout << " ";
        cout << steps[i];
        ansNum++;
    }

    cout << endl;
    return 0;
}
