/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
      unordered_set<ListNode *> h_map;
      ListNode* runner = head;
      while (runner != nullptr) {
        if (h_map.find(runner) != h_map.end()) {
          return true;
        }
        h_map.insert(runner);
        runner = runner->next;
      }
      return false;
    }
};
