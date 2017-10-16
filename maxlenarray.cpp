#include <iostream>
#include <vector>

using namespace std;

int main() {
    
	int T;
	cin >> T;
	
	while(T--){
	    
	    int N;
	    cin >> N;
	    vector<int> A(N);
	    for(int i = 0; i < N; i++) cin >> A[i];
	    
	    vector< vector<int> > L(N, vector<int>(2, 0));
	    int max = 0;
	    L[0][0] = 1;
	    L[0][1] = 1;
	    for(int i = 1; i < N; i++){
	        if ( A[i-1] == A[i]){
	            L[i][0] = L[i-1][0] + 1;
	            L[i][1] = L[i-1][1] + 1;
	            cout << "Equal elements found: " << i+1 << ", " << L[i][0] << ", " << L[i][1] << endl;
	        }
	        else if (A[i-1] < A[i]){
	            L[i][0] = L[i-1][0] + 1;
	            L[i][1] = L[i][0];
	            cout << "Greater element found: " << i+1 << ", " << L[i][0] << ", " << L[i][1] << endl;
	        }
	        else{
	            L[i][0] = 1;
	            L[i][1] = L[i-1][1] + 1;
	            cout << "Smaller element found: " << i+1 << ", " << L[i][0] << ", " << L[i][1] << endl;
	        }
	        max = L[i][1] > max ? L[i][1] : max;
	    }
	    cout << max << endl;
	}
	return 0;
}
