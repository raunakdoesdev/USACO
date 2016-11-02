/*
ID: sauhaar1
PROG: msquare
LANG: C++11
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>
#include <string>
#include <string.h>
#include <queue>          // std::queue
#include <map>

using namespace std;

class Square{
    public:
        string square;
        string history;
        int counter;
        
        Square(string sq, string hist, int count);

        Square* transformA(void);
        Square* transformB(void);
        Square* transformC(void);
};

Square::Square( string sq, string hist, int count){
    square = sq;
    history = hist;
    counter = count;
}

Square* Square::transformA(void){
    string sq(square);

    sq[0] = square[7];
    sq[7] = square[0];
    sq[1] = square[6];
    sq[6] = square[1];
    sq[2] = square[5];
    sq[5] = square[2];
    sq[3] = square[4];
    sq[4] = square[3];

    if(counter % 60 == 0 && counter != 0)
        return new Square(sq, history + "\nA", counter + 1); 
    return new Square(sq, history + 'A', counter + 1);
}

Square* Square::transformB(void){
    string sq(square);

    sq[0] = square[3];
    sq[1] = square[0];
    sq[2] = square[1];
    sq[3] = square[2];
    sq[4] = square[5];
    sq[5] = square[6];
    sq[6] = square[7];
    sq[7] = square[4];

    if(counter % 60 == 0 && counter != 0)
        return new Square(sq, history + "\nB", counter + 1); 
    return new Square(sq, history + 'B', counter + 1);
}

Square* Square::transformC(void){
    string sq(square);
    sq[5] = square[2];
    sq[6] = square[5];
    sq[1] = square[6];
    sq[2] = square[1];
    if(counter % 60 == 0 && counter != 0)
        return new Square(sq , history + "\nC", counter + 1); 
    return new Square(sq , history + 'C', counter + 1); 
}


int main() {

    ofstream cout ("msquare.out");
    ifstream cin ("msquare.in");
    
    char c;
    string goal = "";

    REP(i, 0, 8){
        cin >> c;
        goal+=c;
    }

    Square *start = new Square("12345678","", 0);
    
    queue<Square*> q;
    map<string, bool> seen;

    q.push(start);

    while (!q.empty()){
        Square* sq = q.front();

        q.pop();

        if(seen[sq->square])
            continue;

        seen[sq->square] = true;

        if(strcmp(goal.c_str(), sq->square.c_str()) == 0){
            cout << sq->counter << endl << sq->history << endl;
        }

        q.push(sq->transformA());
        q.push(sq->transformB());
        q.push(sq->transformC());

        delete sq;
    }

    return 0;
}
