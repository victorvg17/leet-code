class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int idx = 0;
        map<char, int> m1;
        map<char, int> m2;
        if (s1.size() > s2.size()) return false;
        for (int i=0; i < n1; i++){
            m1[s1[i]]++;  
        }
        
        for (int i=0; i<n2; i++) {
            m2[s2[i]]++;
            idx = i-n1;
            
            if (idx >= 0) {
                if (m2[s2[idx]] == 1) {
                    m2.erase(s2[idx]);
                }
                
                else m2[s2[idx]]--;   
            }
            
            if (m1 == m2) return true;
        }
        return false;
        
    }
};