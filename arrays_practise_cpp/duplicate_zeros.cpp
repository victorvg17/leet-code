#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
      for (int i = 0; i < arr.size();) {
        if (arr[i] == 0) {
          shiftRightAddZero(arr, i);
          i = i+2;
          continue;
        }
        i = i+1;
      }
    }

    void shiftRightAddZero(vector<int>& arr, int idx) {
      int cs = arr.size();
      for (int i = cs-1; i >= idx; i--) {
        arr[i+1]= arr[i];
      }
      arr[idx] = 0;
    }
};


int main() {
  Solution sol;
  //sample input: [1,0,2,3,0,4,5,0], exp output: [1,0,0,2,3,0,0,4]
  vector<int> myints{1,0,2,3,0,4,5,0};
  sol.duplicateZeros(myints);

  cout << "value: ";
  for (auto& val : myints) {
    cout << val;
  }
  cout << endl;

}
