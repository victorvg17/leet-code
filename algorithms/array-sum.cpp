class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2);
        for (int i=0; i<nums.size()-1; i++) {
            answer[0] = i;
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[answer[0]] + nums[j] == target) {
                    answer[1] = j;
                    return answer;
                }
            }
        }
        return answer;
    }
};
