//https://leetcode.com/problems/is-subsequence/
class Solution {
// aaaae
// e

public:
    bool isSubsequence(string s, string t) {
        bool eh = true;
        if (t.size() == 0 && s.size() != 0) return !eh;
        if (t.size() == 0 && s.size() == 0) return eh;
        if (s.size() == 0) return eh;
        int pr = 0, pl = 0;
        while (pr<t.size() && pl<s.size()){
            if (t[pr]==s[pl]){
                pl++;
            }
            pr++;
        }
        if (pl != s.size()){
            return false;
        }
        else return true;
    }
};
