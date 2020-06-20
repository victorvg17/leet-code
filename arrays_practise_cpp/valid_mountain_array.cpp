#include <vector>
#include <algorithm>
#include <stdbool.h>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
      int N = A.size();
      if (N < 3) {
        return false;
      }
      int v = 0;
      while(v+1 < N && A[v] < A[v+1]){
        v++;
      }
      if (v == N-1 || v== 0){
        return false;
      }

      while(v+1<N && A[v]>A[v+1]){
        v++;
      }
      return v == N-1;
    }
};

int main() {
  Solution sol;
  // sample input: [0,3,2,1], exp output: true
  vector<int> arr{0,1,2,3,4,5,6,7,8,9};

  bool is_present = sol.validMountainArray(arr);

  cout << "***************************output***************************" << endl;
  cout << "result: " << is_present << endl;
}
