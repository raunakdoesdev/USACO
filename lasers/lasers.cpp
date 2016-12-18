/*
ID: sauhaar1
PROG: lasers
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>
#include <queue>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main() {

    ofstream cout ("lasers.out");
    ifstream cin ("lasers.in");

    int n = 0;
    cin >> n;
    int x[n+2], y[n+2];
    cin >> x[0] >> y[0];
    cin >> x[n+1] >> y[n+1];

    map<int, vector<int>* > xvals;
    map<int, vector<int>* > yvals;

    REP(i, 1, n+1){
        cin >> x[i];
        cin >> y[i];
    }

    REP(i, 0, n+1){
        if(xvals[x[i]] == NULL)
            xvals[x[i]] = new vector<int>({i});
        else
            xvals[x[i]]->push_back(i);

        if(yvals[y[i]] == NULL)
            yvals[y[i]] = new vector<int>({i});
        else
            yvals[y[i]]->push_back(i);
    }


    queue<pair<pair<int, bool>, int > > search;

    search.push(make_pair(make_pair(0, true), 0));
    search.push(make_pair(make_pair(0, false), 0));

    while(!search.empty()){
        int node = search.front().first.first;
        if(search.front().first.second){ // horizontal
            if(y[node] == y[n+1]){
                cout << search.front().second << endl;
                return 0;
            }

            for(vector<int>::iterator it = yvals[y[node]]->begin(); it !=  yvals[y[node]]->end(); it++)
                if(*it != node && *it != 0)
                    search.push(make_pair(make_pair(*it, false), search.front().second + 1));
        }else{
            if(x[node] == x[n+1]){
                cout << search.front().second << endl;
                return 0;
            }
            for(vector<int>::iterator it = xvals[x[node]]->begin(); it !=  xvals[x[node]]->end(); it++)
                if(*it != node && *it != 0)
                    search.push(make_pair(make_pair(*it, true), search.front().second + 1));
        }
        search.pop();
    }

    cout << "-1" << endl;

    return 0;
}
