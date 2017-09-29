#include<iostream>
#include<vector>

using namespace std;

void merge(vector<float> &A, int p, int q, int r){
	// temporary array to store the subarray A[p .. r]
	// this is one the reason merge sort is not recommended i.e. extra space requirement
	vector<float> B(r - p + 1, 0);
	for(int i = 0; i <= r-p; i++) B[i] = A[i+p];

	int j = 0;
	int k = q+1-p;
	for(int i  = p; i <= r; i++){
		if (j > q-p) A[i] = B[k++];
		else if (k > r-p) A[i] = B[j++];
		else if (B[k] > B[j]) A[i] = B[j++];
		else A[i] = B[k++];
	}
}

void mergesort(vector<float> &A, int p, int r){
	if (p == r) return;
	int q = (p+r)/2;
	mergesort(A, p, q);
	mergesort(A, q+1, r);
	merge(A, p, q, r);
}

inline void printArray(const vector<float> &A){
    for(auto e: A){
        cout << e << ", ";
    }
    cout<<endl;
}

int main() {
    vector<float> A = {2.1, -1.2, 0.3, 8.6, 4.2, 2.4, 9.01};
    mergesort(A, 0, 6);
	printArray(A);
	A.push_back(-33.2);
	mergesort(A, 0, 7);
	printArray(A);
}