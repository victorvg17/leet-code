#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int>& sortedSquares(vector<int>& A) {
      convertToSquares(A);
      vector<int>& sorted_vect = sortSquaredVector(A);
      return sorted_vect;
    }

    void convertToSquares(vector<int>& A) {
      for (int i=0; i < A.size(); i++) {
        A[i] = A[i]*A[i];
      }
    }

    vector<int>& sortSquaredVector(vector<int>& sq_vect) {
      sort(sq_vect.begin(), sq_vect.end());
      return sq_vect;
    }
};

int main() {
  Solution sol;
  //sample input: [-7,-3,2,3,11], exp output: [4,9,9,49,121]
  vector<int> myints{-7,-3,2,3,11};
  vector<int> outputs = sol.sortedSquares(myints);

  for (auto& val : outputs) {
    cout << "value: " << val << endl;
  }

}
