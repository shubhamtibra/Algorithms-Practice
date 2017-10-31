#include <iostream>
#include <vector>
using namespace std;

void print_matrix(const vector< vector<int> > &board){
    string str(60, '_');
    
    cout << str;
    cout << endl;
    for(auto e: board){
        for(auto j: e){
            cout << "|" << j << "\t";
        }
        cout << endl;
        cout << str;
        cout << endl;
    }
    return;
}

bool knight_tour(int n, int i, int j, int move, vector< vector<int> > &board){
    if ( i < 0 || i >= n || j < 0 || j >= n || board[i][j]) return false;
    board[i][j] = move;
    if (move == n*n) {
        print_matrix(board);
        return true;
    }
    
    
    if (knight_tour(n, i+2, j+1, move+1, board)) return true;
    if (knight_tour(n, i+1, j+2, move+1, board)) return true;
    if (knight_tour(n, i+2, j-1, move+1, board)) return true;
    if (knight_tour(n, i-1, j+2, move+1, board)) return true;
    if (knight_tour(n, i+1, j-2, move+1, board)) return true;
    if (knight_tour(n, i-2, j+1, move+1, board)) return true;
    if (knight_tour(n, i-2, j-1, move+1, board)) return true;
    if (knight_tour(n, i-1, j-2, move+1, board)) return true;
    board[i][j] = 0;
    return false;
    
}

int main() {
	int n;
	cin >> n;
	vector< vector<int> > board(n, vector<int>(n, 0));
	knight_tour(n, 0, 0, 1, board);
	return 0;
}