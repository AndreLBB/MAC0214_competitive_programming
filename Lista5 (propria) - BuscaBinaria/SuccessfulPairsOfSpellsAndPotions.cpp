//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        
        // spell * potion >= success
        // spell >= success / potion

        vector<int> pairs(spells.size());
        for (int i = 0;i<spells.size();i++){
            auto it  = lower_bound(potions.begin(), potions.end(), ((double)success)/spells[i]);
            if (it == potions.end()){
                pairs[i] = 0;
            }
            else{
                int indice = it - potions.begin();
                pairs[i] = potions.size()-1 - indice + 1;
            }
        }
        return pairs;
        
    }
};
