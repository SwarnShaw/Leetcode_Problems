class Solution {
private:
    void generate(int open, int close, int n, vector<string>& ans, string& curr) {

        if(curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        
        if(open < n) {
            curr += '(';
            generate(open + 1, close, n, ans, curr);
            curr.pop_back();
        }

        
        if(close < open) {
            curr += ')';
            generate(open, close + 1, n, ans, curr);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;

        generate(0, 0, n, ans, curr);

        return ans;
    }
};