// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maior_area =0;
        int area_atual = 0;
        while (l<r){
            area_atual = (r-l) * min(height[l], height[r]);
            if (area_atual>maior_area){
                maior_area = area_atual;
            }
            if (height[l]>=height[r]){
                r--;
            }
            else l++;

        }
        return maior_area;
    }
};
