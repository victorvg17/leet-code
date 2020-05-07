#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

    unsigned currentMax = 0;
unsigned arg_max = 0;
    unordered_map <int, int> tracker; //tracker : {number, count}
        //sweep through the vector
        for (auto i = nums.begin(); i != nums.end(); i++) {
        tracker[*i] += 1;
        }

        //get the key with max val
for(auto it = tracker.cbegin(); it != tracker.cend(); ++it ) {
   if (it->second > currentMax) {
       arg_max = it->first;
       currentMax = it->second;
   }
}
return arg_max;
}
};

int main() {
Solution sol;

int input[] = {2,2,1,1,1,2,2};
  std::vector<int> inp_vector (input, input + sizeof(input) / sizeof(int) );

// int input = {2,2,1,1,1,2,2};
int result = sol.majorityElement(inp_vector);
cout << "majority element: " << result << endl;
}
