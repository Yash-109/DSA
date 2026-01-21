class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());  // bruteforce

        // optimized
        int n=nums.size();
        int count0 = 0, count1 = 0, count2 = 0;

        for(int i=0;i<n;i++)  // O(n)
        {
            if(nums[i]==0) count0++;
            else if(nums[i]==1) count1++;
            else count2++;
        }

        // O(n)
        int indx=0;
        for(int i=0;i<count0;i++)
        {
            nums[indx++] = 0;
        }

         for(int i=0;i<count1;i++)
        {
            nums[indx++] = 1;
        }

         for(int i=0;i<count2;i++)
        {
            nums[indx++] = 2;
        }

        // optimal:
        
    }
};