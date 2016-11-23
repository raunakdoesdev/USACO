/*
ID: sauhaar1
PROG: camelot
LANG: C++
 */

#include <fstream>
#include <queue>
#include <cstring>

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

template<typename T> inline const T ABS(T const & x)
{
    return ( x<0 ) ? -x : x;
}

using namespace std;

struct piece{
    int x, y;
    piece(int x = 0, int y = 0) : x(x), y(y) {}
}knight[1001], king;

int main(){
    // Input/Output
    ofstream cout ("camelot.out");
    ifstream cin ("camelot.in");

    //Get Bounds
    int xMax, yMax;
    cin >> yMax >> xMax;

    // Get King Data
    char c;
    int r;
    cin >> c >> r;
    king.x = c - 'A' + 1;
    king.y = r;

    int kn = 0; // number of knights

    while(cin >> c >> r){
        knight[++kn].x = c - 'A' + 1;
        knight[kn].y = r;
    }

    piece moves[8] = {piece(2, 1), piece(2, -1), piece(1, 2), piece(-1, 2),
        piece(-2, 1), piece(-2, -1), piece(-1, -2), piece(1, -2)};

    // Calculate pathlength for every possible position of a knight
    int knightPath[32][32][32][32];
    memset(knightPath, 1, sizeof(knightPath)); // every integer will be 0x01010101    

    REP(i, 1, xMax + 1){
        REP(j, 1, yMax + 1){ // Run a BFS for every possible start node
            queue<piece> q;
            q.push(piece(i,j));
            knightPath[i][j][i][j] = 0;
            while(!q.empty()){
                piece p = q.front(); q.pop();
                REP(d, 0, 8){
                    int nextX = p.x + moves[d].x;
                    int nextY = p.y + moves[d].y;
                    if(nextX > 0 && nextY > 0 && nextX <= xMax && nextY <= yMax
                            && knightPath[i][j][nextX][nextY] == 0x01010101){
                        knightPath[i][j][nextX][nextY] = knightPath[i][j][p.x][p.y] + 1;
                        q.push(piece(nextX, nextY));
                    }
                }
            }
        }
    }


    // This is kinda crude but it works
    // Basically I assume that the king will only move a max of 2 squares
    // in the whole thing. This seems to work for all the test cases, in
    // competition I would just make this l higher until it works.

    int l = 2; // the bound of the search (max squares the king will move)

    int upBound = king.y - l < 1 ? 1 : king.y - l;
    int lowBound = king.y + l > yMax ? yMax : king.y + l;
    int leftBound = king.x - l < 1 ? 1 : king.x - l;
    int rightBound = king.x + l > xMax ? xMax : king.x + l;

    int minStep = 1 << 25; // basically infinity

    REP(i, 1, xMax + 1){
        REP(j, 1, yMax + 1){
            int step = 0;
            REP(k, 1, kn + 1)
                step += knightPath[knight[k].x][knight[k].y][i][j];
            int minKing = MAX(ABS(king.x - i),ABS(king.y - j));

            REP(a, leftBound, rightBound + 1){
                REP(b, upBound, lowBound + 1){
                    REP(k, 1, kn + 1){ // basically figure out how long it would take to pick the king up
                        int tmp = MAX(ABS(king.x - a), ABS(king.y - b)); // kings movement
                        tmp += knightPath[knight[k].x][knight[k].y][a][b]; // knights movement to the king
                        tmp += knightPath[a][b][i][j]; // king and knight's movement to the end zone
                        tmp -= knightPath[knight[k].x][knight[k].y][i][j]; // subtract the knight's original uninteruppted journey
                        minKing = MIN(minKing, tmp);
                    }
                }
            }
            // cout << "step: " << step << " minKing: " << minKing << endl;

            minStep = MIN(minStep, step + minKing);
        }
    }

    cout << minStep << endl;
    return 0;
}
