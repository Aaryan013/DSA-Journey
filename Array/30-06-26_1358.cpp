class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int answer = 0;
        vector<int> freq(3, 0);

        for(int right = 0; right < s.length() - 1; right++){
            freq[s[right] - 'a']++;

            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                freq[s[left] - 'a']--;
                left++;
            }

            answer += left;
        }

        return answer;
    }
};