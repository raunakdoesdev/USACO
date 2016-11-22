/*
ID: sauhaar1
PROG: shopping
LANG: C++
*/

// I CANNOT APOLOGIZE FOR THE PUNNY CODE :P


#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>

using namespace std;

struct Offers{
    int obj[6]; // quantity of each object
    int p; 
}

int decode(int encoded){ // returns index of the element
    if(!code[encoded])
        code[encoded] = ++codex; // get it? code index = codex :P
    return code[encoded];
}


int main() {

    ofstream cout ("shopping.out");
    ifstream cin ("shopping.in");

    int numOffers;
    cin >> numOffers;

    REP(i, 0, numOffers){
        int numProducts;
        cin >> numProducts;

        REP(j, 0, numProducts){
            int productID;
            cin >> productID;
            cin >> offer[i].obj[decode(productID)];
        }
        cin >> offer[i].p;
    }

    int numObjects;

    cin >> numObjects;

    int cart[6]; // things to shop for

    REP(i, 0, numObjects){
        int productID;
        cin >> productID;
        int productIndex = decode(productID);
        cin >> cart[productIndex]
    }
    
    int dynamo[6][6][6][6][6][6];

    return 0;
}
