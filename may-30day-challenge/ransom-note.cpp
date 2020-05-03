#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char const &c:ransomNote) { //for each letter in ransomNote, check in magazine
            size_t found = magazine.find(c);
            if (found != string::npos) {
                //erase letter at found position
                magazine.erase(found, 1);
            }
            else {
                return false;
            }
        }
        return true;

    }
};
