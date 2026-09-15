class Solution {
public:
    int searchInsert(vector<int>& nums, int tar) {
        int st=0;
        int end=nums.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==tar){
                return mid;

            }
            if(nums[mid]<tar) st = mid +1 ;
            if(nums[mid]>tar) end = mid -1 ;
        }
        return st;
    }
};