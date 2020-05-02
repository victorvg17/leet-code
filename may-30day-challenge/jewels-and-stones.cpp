#include <string>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int no_jewel = 0;
        for (char const &c:S) { //for each stone, check if it's a jewel
            size_t found = J.find(c);
            if (found != string::npos) {
                no_jewel++;
            }
        }
        return no_jewel;

    }
};
