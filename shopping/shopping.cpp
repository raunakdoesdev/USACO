/*
ID: sauhaar1
PROG: shopping
LANG: C++
 */

// I CANNOT APOLOGIZE FOR THE PUNNY CODE :P
// Note that this program assumes you cannot use multiple of the same offer

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>
#include <cstring>
#include <algorithm>    // std::min

using namespace std;

struct Offers{
    int obj[6]; // quantity of each object
    int p; 
}offer[200];

int codex = 0;
int code[1001];

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
        cin >> cart[productIndex];

        // create an offer, that is the base price of an item
        cin >> offer[numOffers + i].p; 
        offer[numOffers + i].obj[productIndex] = 1; // Just 1 of the object
    }

    int dynamo[6][6][6][6][6];

    memset(dynamo, 127, sizeof(dynamo)); // fills array dynamo up to max size
    dynamo[0][0][0][0][0] = 0; // base case

    REP(i, 0, numObjects + numOffers){
        int n1 = offer[i].obj[1];
        int n2 = offer[i].obj[2];
        int n3 = offer[i].obj[3];
        int n4 = offer[i].obj[4];
        int n5 = offer[i].obj[5];

        REP(a1, 0, cart[1] - n1 + 1)
        REP(a2, 0, cart[2] - n2 + 1)
        REP(a3, 0, cart[3] - n3 + 1)
        REP(a4, 0, cart[4] - n4 + 1)
        REP(a5, 0, cart[5] - n5 + 1)
            dynamo[a1+n1][a2+n2][a3+n3][a4+n4][a5+n5] =
                min(dynamo[a1+n1][a2+n2][a3+n3][a4+n4][a5+n5],
                        dynamo[a1][a2][a3][a4][a5] + offer[i].p);
    }

    cout << dynamo[cart[1]][cart[2]][cart[3]][cart[4]][cart[5]] << endl;

    return 0;
}
