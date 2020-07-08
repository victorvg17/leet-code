#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
      int N = nums.size();
      if (N == 1){
        return nums[0];
      }
      sort(nums.begin(), nums.end());
      reverse(nums.begin(), nums.end());
      if (nums[0]==nums[1] || nums[1] == nums[2]){
        return nums[3];
      }
      if (nums[0]==nums[1] && nums[1] == nums[2]){
        return nums[]
      }
    }
};


int main() {
  Solution sol;
  //sample input: [2, 2, 3, 1], exp output: 1
  vector<int> nums{2, 2, 3, 1};

  vector<int> output = sol.sortArrayByParity(nums);
  cout << "***************************output***************************" << endl;
  sol.printStatus(output);
}
