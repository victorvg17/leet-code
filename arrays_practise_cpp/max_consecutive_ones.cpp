#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(const vector<int>& nums) {
        int max_consec_ones = 0;
        int max_consec_ones_max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1 ){
                max_consec_ones++;
            }
            else{
                max_consec_ones = 0;
            }
            if (max_consec_ones > max_consec_ones_max) {
                max_consec_ones_max = max_consec_ones;
            }
        }
        return max_consec_ones_max;

    }
};

int main() {
  Solution sol;
  //sample input: [1,0,1,1,0,1]
  const vector<int> myints{1,0,1,1,0,1};
  int max_consec_ones = sol.findMaxConsecutiveOnes(myints);
  cout << "max_consec_ones: " << max_consec_ones << endl;
}
