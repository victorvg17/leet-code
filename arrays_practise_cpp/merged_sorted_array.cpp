#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      for (int i=m; i<nums1.size(); i++) {
        nums1[i] = nums2[i-n];
      }
      sort(nums1.begin(), nums1.end());
    }
};

int main() {
  Solution sol;
  //sample input: [1,2,3,0,0,0], exp output: [1,2,2,3,5,6]
  vector<int> nums1{1,2,3,0,0,0};
  vector<int> nums2{2,5,6};
  int m = 3;
  int n = 3;
  sol.merge(nums1, m, nums2, n);

  cout << "output: " << endl;
  for (auto& val : nums1) {
    cout << val;
  }
  cout << endl;
}
