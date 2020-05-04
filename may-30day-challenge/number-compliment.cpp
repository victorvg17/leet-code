#include <vector>
#include <math.h>
#include <iostream>

using namespace std;
class Solution {
public:

    void printVector(const vector <int>& myvector) {
      for (auto it = myvector.begin(); it != myvector.end(); ++it)
        cout << ' ' << *it;
      cout << endl;
    }
    void decToBinary(int num, vector <int>& bin) {
        //counter for binary vector
        // int i = 0;
        while (num > 0) {
            bin.push_back(num % 2);
            num = num / 2;
        }
    }

    void complimentBinary(vector <int>& bin) {
        for (int i = 0; i < bin.size(); i++) {
            bin[i] = (bin[i] == 1 ? 0 : 1);
        }
    }

    int binaryToDec(vector <int>& bin) {
        int dec = 0;
        for (int i = 0; i < bin.size(); i++) {
            dec += bin[i] * pow(2, i);
        }
        return dec;
    }

    int findComplement(int num) {
        vector <int> bin;
        decToBinary(num, bin);
        cout << "decToBinary op: " << endl;
        printVector(bin);
        complimentBinary(bin);
        cout << "complimentBinary op: " << endl;
        printVector(bin);

        int dec_compli = binaryToDec(bin);
        return dec_compli;
    }
};

int main() {
  Solution sol;
  int ans = sol.findComplement(5);
  cout << "answer: " << ans << endl;
}
