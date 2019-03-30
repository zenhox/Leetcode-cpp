class Solution {
public:
    int jump(vector<int>& nums) {
    	if (nums.size() <= 1)
    		return 0;
        vector<int> dp(nums.size(),0);
        int last_index = 0;
        dp[1] = 1;
        for(int i=2;i<nums.size();++i)
        {
            if(nums[last_index] + last_index >= i)
                dp[i] = dp[i-1];
            else
            {
                dp[i] = dp[i-1]+1;
                int max_index = -1;
                int max = -1;
                for(int j=last_index+1;j<i;++j)
                {
                    if(j+nums[j]>max)
                    {
                        max = j+nums[j];
                        max_index = j;
                    }
                }
                last_index = max_index;
            }
        }
        return dp[nums.size()-1];
    }
};