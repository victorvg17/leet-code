#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findNumbers(const vector<int>& nums) {
      int even_no_digits = 0;
      int curr_no_digits;
      for (int i = 0; i < nums.size(); i++) {
        curr_no_digits = findNumberOfDigits(nums[i]);
        if (curr_no_digits % 2 == 0) {
          even_no_digits++;
        }
      }
      return even_no_digits;
    }

private:
  int findNumberOfDigits(int num) {
    int no_digits = 0;
    cout << "for num: " << num << ", ";
    while(num != 0){
      no_digits++;
      num = num/10;
    }
    cout << "no_digits: " << no_digits << endl;
    return no_digits;
  }

};


int main() {
  Solution sol;
  //sample input: [12,345,2,6,7896]
  const vector<int> myints{12,345,2,6,7896};
  int even_no_digits = sol.findNumbers(myints);
  cout << "even_no_digits: " << even_no_digits << endl;
}
