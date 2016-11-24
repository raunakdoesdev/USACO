/*
ID: sauhaar1
PROG: range
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MIN(a,b) (((a)<(b))?(a):(b)) // damn that's a lot of parentheses :P
#define MAX(a,b) (((a)>(b))?(a):(b)) // damn that's a lot of parentheses :P

#include <fstream>
#include <cstring>

using namespace std;


int main() {

    ofstream cout ("range.out");
    ifstream cin ("range.in");

    // Input

    int size; // size of field
    cin >> size;

    int eatable[size][size];

    string line;
    getline(cin, line);

    REP(i, 0, size){
        getline(cin, line);
        REP(j, 0, size)
            eatable[j][i] = ((line[j] == '1') ? 1 : 0);
    }

    // First compute the biggest square with a bottom-right corner at every possible location using dp
    
    int biggestSquare[size][size]; // Note, this is x,y
    
    REP(i, 0, size){ // x
        REP(j, 0, size){ // y
            int squaresLeft, squaresUp;

            for(squaresLeft = i; squaresLeft >= 0; squaresLeft--){ // count squares to the left
                if(!eatable[squaresLeft][j])
                    break;
            }
            squaresLeft = i - squaresLeft;

            for(squaresUp = j; squaresUp >= 0; squaresUp--){ // count squares to the left
                if(!eatable[i][squaresUp])
                    break;
            }
            squaresUp = j - squaresUp;

            int maxSquare = MIN(squaresLeft, squaresUp);

            if(i > 0 && j > 0)
                maxSquare = MIN(maxSquare, biggestSquare[i - 1][j - 1] + 1); // checks if the square is actually filled

            biggestSquare[i][j] = maxSquare;
        }
    }
    
    int total[size + 1]; // initialized empty

    memset(total, 0, sizeof(total));

    REP(i, 0, size) // count squares of each type
        REP(j, 0, size)
            REP(k, 2, biggestSquare[i][j] + 1)
                total[k]++;

    REP(i, 2, size + 1)
        if(total[i])
            cout << i << " " << total[i] << endl;

    return 0;
}
