/*
ID: sauhaar1
PROG: heritage
LANG: C++
*/

#define REP(i, a, b)     for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!

#include <fstream>
#include <string>

using namespace std;

struct node{
    char val;
    node* left;
    node* right;
    node(char val, node* left = NULL, node* right = NULL)
        : val(val), left(left), right(right){}
};

node* makeTree(string in, string pre){
    if(in.size() == 1)
        return new node(in[0]);
    else if(in.size() == 0)
        return NULL;

    // find character for root node
    char root;
    int rootPos = 100;
    int inPos = 0;
    REP(i, 0, in.size()){
        int loc = pre.find(in[i]);
        if(loc < rootPos){
            rootPos = loc;
            root = pre[loc];
            inPos = i;
        }
    }
    
    return new node(root, makeTree(in.substr(0,inPos), pre),makeTree(in.substr(inPos + 1, in.size() - inPos - 1), pre));
}

string post(node* tree){
    if(tree == NULL)
        return "";
    if(tree->left == NULL && tree->right == NULL)
        return string(1, tree->val);
    return post(tree->left) + post(tree->right) + string(1,tree->val); 
}


int main() {

    ofstream cout ("heritage.out");
    ifstream cin ("heritage.in");
    
    string in, pre;

    getline(cin, in);
    getline(cin, pre);

    cout << post(makeTree(in, pre)) << endl;

    return 0;
}
