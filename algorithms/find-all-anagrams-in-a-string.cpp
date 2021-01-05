class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> s_count(26, 0);
        vector<int> p_count(26, 0);
        vector<int> res;
        if (s.size() < p.size()) return res;
        
        for (int i=0; i<m; i++) {
            p_count[p[i]-'a']++;
            s_count[s[i]-'a']++;
        }
        
        if (p_count == s_count) res.push_back(0);
        
        for (int i=m; i <n; i++) {
            s_count[s[i]-'a']++;
            s_count[s[i-m]-'a']--;
            if (p_count == s_count){
                res.push_back(i-m+1);
            }
        }
        return res;
    }
};