#include <iostream>
#include<vector>

using namespace std;

void insertionSort(vector<float> &A){

    for(int j = 1; j < A.size(); j++){
        int i = j - 1;
        float key = A[j];

        while(i >= 0 && key > A[i]){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

inline void printArray(const vector<float> &A){
    for(auto e: A){
        cout << e << ", ";
    }
}

int main() {
    vector<float> A = {2.1, -1.2, 0.3, 8.6, 4.2, 2.4, 9.01};
    insertionSort(A);
	printArray(A);
}