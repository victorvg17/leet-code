#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
      int N = arr.size();
      int max_val = 0;

      for (int i=N-1; i>=0; i-- ){
        if (arr[i] > max_val){
          max_val = arr[i];
        }
        arr[i] = max_val;
      }

      //add -1 at the end
      arr.push_back(-1);
      arr.erase(arr.begin());
      return arr;
    }

    void printStatus(const vector<int>& nums, int len) {
      cout << "len: " << len << " output: " << endl;
      for (auto it=nums.begin(); it != nums.end(); ++it){
        cout << ' ' << *it;
      }
      cout << endl;
    }
};


int main() {
  Solution sol;
  // sample input: [17,18,5,4,6,1], exp output: [18,6,6,6,1,-1]
  vector<int> arr{17,18,5,4,6,1};

  vector <int> output = sol.replaceElements(arr);

  cout << "***************************output***************************" << endl;
  sol.printStatus(output, output.size());
}
