/*
ID: sauhaar1
PROG: lgame
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#include <fstream>
#include <cstring>
#include <set>

using namespace std;


bool valid(string dictEntry, string myScrabble){
    int letters[26];
    memset(letters, 0, sizeof(letters));
    REP(i, 0, dictEntry.length())
        if(dictEntry[i] != ' ') // ignore spaces for dual words
            letters[dictEntry[i] - 'a']--;
    REP(i, 0, myScrabble.length())
        letters[myScrabble[i] - 'a']++;
    REP(i, 0, 26) if(letters[i] < 0) return false;
    return true;
}

int values[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
int points(string dictEntry){
    int points = 0;
    REP(i, 0, dictEntry.size())
        if(dictEntry[i] != ' ') // ignore spaces for dual words
            points += values[dictEntry[i] - 'a'];
    return points;
}

int main() {

    ofstream cout ("lgame.out");
    ifstream cin ("lgame.in");
    ifstream din ("lgame.dict");
    
    string scrabble;
    cin >> scrabble;

    int d = 0;
    string dictionary[40000];
    string temp;

    while(getline(din, temp) && temp != ".")
        if(valid(temp, scrabble))
            dictionary[d++] = temp;
    int newSize = d;
    REP(i, 0, d)
        REP(j, i, d)
            if(valid(dictionary[i]+" "+dictionary[j], scrabble))
                dictionary[newSize++] = dictionary[i]+" "+dictionary[j];
    d = newSize;

    int maxPoints = 0;
    set<string> winningWords;
    
    REP(i, 0, d){
        int myPoints = points(dictionary[i]);
        if(myPoints > maxPoints){
            maxPoints = myPoints;
            winningWords.clear();
            winningWords.insert(dictionary[i]);
        }else if(myPoints == maxPoints){
            winningWords.insert(dictionary[i]);
        }
    }

    cout << maxPoints << endl;
    for(set<string>::iterator iter = winningWords.begin(); iter != winningWords.end(); ++iter){
        cout << *iter << endl;
    }
    return 0;
}
