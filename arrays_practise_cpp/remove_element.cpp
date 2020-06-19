#include <iostream>
#include <vector>
#include <algorithm>
#include <stdbool.h>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int count_val = count(nums.begin(), nums.end(), val);
      int j = nums.size()-1;
      bool if_done = false;

      for (int i=0; i < nums.size(); i++) {
        if(checkIfDone(nums, count_val, val) == true) {
          return nums.size() - count_val;
        }
        if (nums[i] == val) {
          while(nums[j] == val) {//find index where nums[i] can be swapped to.
            j--;
          }
          // swapValToEnd(nums, i, j);
          swap(nums[i], nums[j]);
          j = nums.size()-1;
          printStatus(nums, nums.size());
        }
      }
      return nums.size() - count_val;
    }

    void printStatus(const vector<int>& nums, int len) {
      cout << "len: " << len << " output: " << endl;
      for (int i=0; i<len; i++){
        cout << nums[i];
      }
      cout << endl;
    }

    bool checkIfDone(const vector<int>& nums, int count_val, int val) {
      if (count(nums.end()-count_val, nums.end(), val) >= count_val) {
        return true;
      }
      return false;
    }

};

int main() {
  Solution sol;
  //sample input: [0,1,2,2,3,0,4,2], exp output: 5
  vector<int> nums{0,1,2,2,3,0,4,2};
  int rem_val = 2;

  int len = sol.removeElement(nums, rem_val);

  cout << "***************************output***************************" << endl;
  sol.printStatus(nums, len);
}
