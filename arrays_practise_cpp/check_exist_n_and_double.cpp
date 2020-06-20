#include <vector>
#include <algorithm>
#include <stdbool.h>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      for (int i=0; i<arr.size(); i++){
        int val = arr[i];
        for (int j=i+1; j<arr.size(); j++){
          if (arr[i] == 2*arr[j] || 2*arr[i] == arr[j]){
            return true;
          }
        }
      }
      return false;
    }

    bool checkIfExistWithHasMap(vector<int>& arr) {
      map<int, int> m;
      if (arr.size() == 0 || arr.size() < 2) return false;
      for (int i=0; i<arr.size(); i++) {
        if (m.count(2*arr[i]) || (arr[i]%2==0 && m.count(arr[i]/2)) ){
          return true;
        }
        else{
          m.insert({arr[i], i});
        }
      }
      return false;
    }

    void printStatus(const vector<int>& nums, int len) {
      cout << "len: " << len << " output: " << endl;
      for (int i=0; i<len; i++){
        cout << nums[i] << " ";
      }
      cout << endl;
    }
};

int main() {
  Solution sol;
  // sample input: [10,2,5,3], exp output: true
  // vector<int> arr{10,2,5,3};
  vector<int> arr{7,1,14,11};
  // vector<int> arr{0, 0};

  bool is_present = sol.checkIfExistWithHasMap(arr);

  cout << "***************************output***************************" << endl;
  cout << "result: " << is_present << endl;
  sol.printStatus(arr, arr.size());
}
