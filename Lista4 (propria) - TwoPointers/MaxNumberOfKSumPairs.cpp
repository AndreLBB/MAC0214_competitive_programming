//https://leetcode.com/problems/max-number-of-k-sum-pairs/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if (nums.size()<=1) return 0;
        sort(nums.begin(), nums.end());
        if (nums[0]>=k) return 0;
        int quant = 0;
        int l = 0, r = nums.size()-1;
        while (r>0 && nums[r] > k){
            r--;
        }
        while (l<r){
            while(l<r &&nums[l]+nums[r]<k){
                l++;
            }
            while (r>l && nums[l]+nums[r]>k){
                r--;
            }
            if (l<r && nums[l]+nums[r]==k){
                quant++;
                l++;
                r--;
            }
        }
        return quant;
    }
};
