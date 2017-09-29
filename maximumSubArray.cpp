#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// custom data type to store the subarray indices with maximum sum and the sum itself
typedef pair< pair<int, int>, float> myPair;

// to sort the pairs using the maximum sum
bool custom_compare(const myPair &a, const myPair &b){
	return a.second > b.second;
}

myPair maximumSumCross(const vector< float> &A, int p, int q, int r){
	float lsum = A[q], maxleft = A[q];
	float rsum = A[q+1], maxright = A[q+1];
	int leftindex = q, rightindex = q+1;
	for(int i = q-1; i >= p; i--){
		lsum += A[i];
		if (maxleft < lsum){
			maxleft = lsum;
			leftindex = i;
		}
	}
	for(int i = q+2; i <= r; i++){
		rsum += A[i];
		if (maxright < rsum){
			maxright = rsum;
			rightindex = i;
		}
	}
	return make_pair(make_pair(leftindex, rightindex), maxright + maxleft);
}

myPair maximumSubArray(const vector<float> &A, int p, int r){
	// base case: array size is 1
	if(p == r){
		if(A[p] >= 0) return make_pair(make_pair(p, r), A[p]);
		else return make_pair(make_pair(-1, -1), 0);
	}

	int q = (p+r)/2;
	myPair left = maximumSubArray(A, p, q);
	myPair right = maximumSubArray(A, q + 1, r);
	myPair mid = maximumSumCross(A, p, q, r);
	vector<myPair> B = {left, right, mid};
	sort(B.begin(), B.end(), custom_compare);
	if (B[0].second > 0) return B[0];
	else return make_pair(make_pair(-1, -1), 0);
}

inline void printmyPair(const myPair &A, vector<float> B){
	if (A.first.first < 0) cout << "Empty Array";
    else cout << "((" << B[A.first.first] << ", " << B[A.first.second] << "), " << A.second << ")";
    cout<<endl;
}

int main() {
    vector<float> A = {-2.1, -1.2, -0.3, -8.6, -4.2, -2.4, -9.01};
    printmyPair(maximumSubArray(A, 0, 6), A);
}