#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int N = nums.size();
      int wp = 0;
      for(int rp=0; rp<N; rp++){ //read pointer
        if (nums[rp] != 0){
          nums[wp] = nums[rp];
          wp++;
        }
      }
      for(int j=wp; j<N; j++){
        nums[j] = 0;
      }
    }

    void printStatus(const vector<int>& nums) {
      cout << "len: " << nums.size() << " output: " << endl;
      for (auto it=nums.begin(); it != nums.end(); it++){
        cout << ' ' << *it;
      }
      cout << endl;
    }

};

int main() {
  Solution sol;
  //sample input: [0,1,0,3,12], exp output: [1,3,12,0,0]
  vector<int> nums{0,1,0,3,12};

  sol.moveZeroes(nums);
  cout << "***************************output***************************" << endl;
  sol.printStatus(nums);
}
