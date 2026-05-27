//https://leetcode.com/problems/move-zeroes/
class Solution {

// 1 3 12 3 12
public:
    void moveZeroes(vector<int>& nums) {
        int ponteiro_rapido = 0, ponteiro_lento = 0;
        while (ponteiro_rapido<nums.size()){
            if (nums[ponteiro_rapido] != 0){
                nums[ponteiro_lento++]=nums[ponteiro_rapido];
            }
            ponteiro_rapido++;  
        }
        while (ponteiro_lento<nums.size()){
            nums[ponteiro_lento++] = 0;

        }
    }

};
