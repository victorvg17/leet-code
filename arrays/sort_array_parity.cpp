#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
      int N = A.size();
      int bkup = 0;
      int ep = 0; //even pointer
      if (N <= 1){  //extreme cases
        return A;
      }
      for(int rp=0; rp<N; rp++) {
        if(A[rp]%2 == 0){
          bkup = A[ep];
          A[ep] = A[rp];
          A[rp] = bkup;

          ep++;
        }
      }
      return A;
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
  //sample input: [3,1,2,4], exp output: [2,4,3,1]
  vector<int> nums{3,1,2,4};

  vector<int> output = sol.sortArrayByParity(nums);
  cout << "***************************output***************************" << endl;
  sol.printStatus(output);
}
