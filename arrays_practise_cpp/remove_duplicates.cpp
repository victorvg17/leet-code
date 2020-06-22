#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      auto last = unique(nums.begin(), nums.end());
      nums.erase(last, nums.end());
      printStatus(nums, nums.size());

      return nums.size();
    }

    int removeDuplicatesUsingDoublePtrs(vector<int>& nums) {
      int N = nums.size();
      if (N == 0){
        return 0;
      }
      int writePointer = 1;
      for (int i=1; i<N; i++){  //read pointer
        if(nums[i-1] != nums[i]){ //no duplication; increment writePointer
          nums[writePointer] = nums[i];
          writePointer++;
        }
      }

      return writePointer;
    }

    void printStatus(const vector<int>& nums, int len) {
      cout << "len: " << len << " output: " << endl;
      for (int i=0; i<len; i++){
        cout << nums[i];
      }
      cout << endl;
    }
};


int main() {
  Solution sol;
  //sample input: [0,0,1,1,1,2,2,3,3,4], exp output: 5
  vector<int> nums{0,0,1,1,1,2,2,3,3,4};

  int output = sol.removeDuplicatesUsingDoublePtrs(nums);
  cout << "***************************output***************************" << endl;
  sol.printStatus(nums, output);
}
