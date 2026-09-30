class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = static_cast<int>(s.size());
        int width = static_cast<int>(words[0].size());
        int count = static_cast<int>(words.size());
        if (width * count > n) return {};
        unordered_map<string_view, int> ids;
        ids.reserve(words.size());
        vector<int> need;
        for (const string& word : words) {
            auto [it, inserted] = ids.try_emplace(string_view(word), static_cast<int>(need.size()));
            if (inserted) need.push_back(0);
            ++need[it->second];
        }
        vector<int> token(n - width + 1, -1);
        for (int i = 0; i + width <= n; ++i) {
            auto it = ids.find(string_view(s.data() + i, width));
            if (it != ids.end()) token[i] = it->second;
        }
        vector<int> result;
        for (int offset = 0; offset < width && offset + width * count <= n; ++offset) {
            vector<int> seen(need.size(), 0);
            int left = offset, used = 0;
            for (int right = offset; right + width <= n; right += width) {
                int id = token[right];
                if (id < 0) {
                    while (left < right) { --seen[token[left]]; left += width; }
                    left = right + width;
                    used = 0;
                    continue;
                }
                ++seen[id];
                ++used;
                while (seen[id] > need[id]) {
                    --seen[token[left]];
                    left += width;
                    --used;
                }
                if (used == count) result.push_back(left);
            }
        }
        return result;
    }
};