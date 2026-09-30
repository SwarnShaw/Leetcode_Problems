class Solution {
public:
    int min_p1 = 0;
    int max_p2 = 0;
    int d = 0;                       // d = length of best palindrome so far

    void help(const string& s, int p1, int p2){
        if(p1 < 0 or p2 == s.size())
            return;
        if(s[p1] == s[p2]){
            if(p2 - p1 + 1 > d){
                d = p2 - p1 + 1;
                min_p1 = p1;
                max_p2 = p2;
            }
            help(s, p1 - 1, p2 + 1);
        }
    }

    string longestPalindrome(string s) {
        int i = 0;
        while(i < s.size()){
            int p1 = i - 1;
            while(i + 1 < s.size() && s[i] == s[i+1]){
                i++;
            }
            int p2 = i + 1;
            if(p2 - p1 - 1 > d){     // the run of equal chars is itself a palindrome
                d = p2 - p1 - 1;
                min_p1 = p1 + 1;
                max_p2 = p2 - 1;
            }
            help(s, p1, p2);
            i++;
        }
        return s.substr(min_p1, max_p2 - min_p1 + 1);
    }
};