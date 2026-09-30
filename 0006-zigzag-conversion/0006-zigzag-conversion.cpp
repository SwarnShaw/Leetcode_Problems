class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int currentrow = 0;
        bool goingDown = true;
        string result = "";

        if (numRows == 1) {
            return s;
        }
        
        for(int i = 0; i < s.length(); i++) {
            rows[currentrow] += s[i];

            if(currentrow == numRows - 1) {
                goingDown = false;
            } else if(currentrow == 0) {
                goingDown = true;
            } 

            if(goingDown == true) {
                currentrow++;
            } else {
                currentrow--;
            }
        }
        for (int i =0; i < rows.size(); i++) {
            result += rows[i];
        }
        return result;
    }
};