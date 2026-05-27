// https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        // invariante: O intervalo entre lo e hi sempre tem um pico
        // vamos garantir isso guardando possíveis respostas
        // em lo e hi
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if (nums[mid] > nums[mid+1]){
                hi = mid; // aqui mid eh possivel pico
            }
            else {
                lo = mid+1; // aqui mid+1 eh possível pico
            }
        }
        return lo;
    }
};
