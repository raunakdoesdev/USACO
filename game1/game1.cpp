/*
ID: sauhaar1
PROG: game1
LANG: C++
 */

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#include <fstream>
#include <cstring>

using namespace std;

int cards[100];
int speed[100][100];

// First Person Score
// ----------------------------------------------------------------
// Let efps be the final score for player1 on player2's turn
// Let fps be the final score for player1 on player1's turn
// 
// fps(n, m) = max{efps(n+1,m)+cards[n], efps(n,m-1)+cards[m]}
// efps(n, m) = min{fps(n+1,m),fps(n,m-1)}
// 
// If we use the definition of efps to implement fps we get:
// 
// fps(n, m) = max{min{fps(n+2,m),fps(n+1,m-1)} + cards[n]
//                 min{fps(n+1, m-1), fps(n, m-2)} + cards[m]}
// 
// So we can use this definition to build a recursive function to
// recursively calculate the first player's score. Using the 
// following base cases:
// 
// fps(n, m) = cards[n] if fps(n = m)
// fps(n, m) = 0 if fps(n > m)
// ----------------------------------------------------------------
// Returns best possible score for the first player
// assuming a super smart second player.

int fps(int n, int m){
    if(speed[n][m] != -1) return speed[n][m];
    if(n == m) return cards[n];
    if(n > m) return 0;
    return speed[n][m] = MAX( MIN(fps(n+2,m),fps(n+1,m-1)) + cards[n], MIN(fps(n+1,m-1),fps(n,m-2)) + cards[m]); 
}

int main() {

    ofstream cout ("game1.out");
    ifstream cin ("game1.in");

    int numCards;
    cin >> numCards;
    
    int sum = 0;
    REP(i, 0, numCards){
        cin >> cards[i];
        sum += cards[i];
    }
    memset(speed, -1, sizeof(speed));
    int x = fps(0, numCards - 1);
    cout << x << " " << sum - x << endl;

    return 0;
}
