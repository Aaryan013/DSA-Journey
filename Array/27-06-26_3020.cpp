class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        int n = nums.size();

        for(int num : nums){
            mp[num]++;
        }
        
        int ans = 1;
        //handling 1
        if(mp.count(1)){
            if(mp[1] % 2 == 0){
                ans = max(ans, mp[1] - 1);
            }
            else 
                ans = max(ans, mp[1]);  
        }

        for(auto &[num, cnt] : mp){
            if(num == 1) continue;

            long long curr = num;
            int length = 0;

            while(true){
                if(!mp.count(curr)){
                    length--; //previous element becomes the center
                    break;
                }

                if(mp[curr] == 1){
                    length++; //current element
                    break;
                }

                length += 2; 

                if(curr > 1000000000LL / curr){
                    length--; //prevent overflow
                    break;
                } 

                curr = curr * curr;
            }

            ans = max(ans, length);
        }

        return ans;
    }
};