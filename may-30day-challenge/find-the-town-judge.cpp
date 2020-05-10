#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
      map<int, vector<int> > trust_map;
      for (auto ppl : trust) {
        vector<int> villager = trust_map[ppl[0]];
        if (find(villager.begin(), villager.end(), ppl[1]) == villager.end()){
          trust_map[ppl[0]].push_back(ppl[1]);
        }
        // cout << "for ppl[" << ppl[0] << "], size:" << trust_map[ppl[0]].size() << endl;
      }
      // cout << "trust_map size: " << trust_map.size() << endl;

      
      return 0;
    }
};

int main() {
  Solution sol;
  vector<vector<int>> trust = {{1,3}, {1,4}, {2,3}, {2,4}, {4,3}};
  int ans = sol.findJudge(4, trust);
  cout << "answer: " << ans << endl;
}
