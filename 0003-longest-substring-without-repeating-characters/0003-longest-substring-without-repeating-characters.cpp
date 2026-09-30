class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i=0,j=0,n = s.size();
        // this solution is based on last seen indices of char 'c'
        vector<int> mp(256,-1);
        while(j<n){
            if(mp[s[j]] != -1 && mp[s[j]] >= i){
                i = mp[s[j]] + 1;
            }
            ans = max(ans, j-i+1);
            mp[s[j]] = j;
            j++;
        }
        return ans;
    }
};