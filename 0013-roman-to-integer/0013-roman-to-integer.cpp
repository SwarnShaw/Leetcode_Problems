class Solution {
public:
    int romanToInt(string s) {
        int hash[256] = {0};

        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;

        int ans = 0;

        for(int i = 0; i < s.length(); i++) {
            if(i + 1 < s.length() && hash[s[i]] < hash[s[i + 1]])
                ans -= hash[s[i]];
            else
                ans += hash[s[i]];
        }

        return ans;
    }
};