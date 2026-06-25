class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n);
        vector<int> rightsum(n);

        //leftsum
        //leftsum.push_back(0);
        for(int i=0; i<n-1; i++){
            leftsum[i+1] = leftsum[i] + nums[i];
        }

        //rightsum
        rightsum[n-1] = 0;
        for(int i=n-1; i>0; i--){
            rightsum[i-1] = rightsum[i] + nums[i];
        }

        vector<int> result;
        for(int i=0; i<n; i++){
            result.push_back(abs(leftsum[i]-rightsum[i]));
        }

        return result;
    }
};


//optimal solution
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        int leftSum = 0;
        vector<int> ans;

        for (int num : nums) {
            int rightSum = totalSum - leftSum - num;
            ans.push_back(abs(leftSum - rightSum));
            leftSum += num;
        }

        return ans;
    }
};
