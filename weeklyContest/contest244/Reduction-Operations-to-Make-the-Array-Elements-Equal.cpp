//problem link -> https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
//Idea: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/discuss/1253877/Sort-and-Count
/*
We sort the array, and go right-to-left, from largest to smallest.

If the current number is the same as the one before it, we do nothing. If the number before is different, we need to update all numbers on the right (sz - j).
*/
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size(),curr=n-1;
        sort(begin(nums),end(nums));
        int ans =0;
        for(int i=n-1;i>0;i--){
            if(nums[i-1]!=nums[i]){
                ans+=(curr-i);
                curr=i-1;
            }
        } 
        return ans;   
    }
};
