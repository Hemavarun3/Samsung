class Solution {
public:
    int dp[21][2*5001];
    int see(vector<int> &nums,int i,int diff)
    {
        if(i==nums.size())
        {
            return diff==0 ? 0 : -1e9;
        }
        else if(dp[i][diff+5001]!=-1)
        {
            return dp[i][diff+5001];
        }
        else
        {
            int a=see(nums,i+1,diff+nums[i])+nums[i];
            int b=see(nums,i+1,diff-nums[i]);
            int c=see(nums,i+1,diff);
            return dp[i][diff+5001]=max({a,b,c});
        }
    }
    int tallestBillboard(vector<int>& rods) {
        cout << pow(3,10) << endl;
        memset(dp,-1,sizeof(dp));
        return see(rods,0,0);
    }
};
