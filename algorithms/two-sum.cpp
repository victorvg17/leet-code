class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> db; // val: index
      int diff;
      vector<int> answer(2);
      for (int i=0; i<nums.size(); i++) {
        diff = target - nums[i];
        if (db.find(diff) != db.end()) {
          answer[0] = db.find(diff)->second;
          answer[1] = i;
          return answer;
        }
        db[nums[i]] = i;
      }
      return answer;
    }
};
