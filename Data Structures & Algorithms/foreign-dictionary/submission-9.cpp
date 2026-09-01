#include <vector>
#include <string>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::string foreignDictionary(const std::vector<std::string>& words) {
        // -1: character not present in words; >= 0: in-degree count
        std::vector<int> in_degree(26, -1);
        std::vector<std::vector<int>> adj(26);

        // 1. Register all unique characters present
        for (const auto& word : words) {
            for (const char ch : word) {
                in_degree[ch - 'a'] = 0;
            }
        }

        // 2. Build graph dependencies from adjacent word pairs
        const int num_words = static_cast<int>(words.size());
        for (int i = 1; i < num_words; ++i) {
            const std::string& w1 = words[i - 1];
            const std::string& w2 = words[i];

            // Prefix invalidation rule (e.g., "abcd" before "abc" is invalid)
            if (w1.size() > w2.size() && w1.rfind(w2, 0) == 0) {
                return "";
            }

            const size_t min_len = std::min(w1.size(), w2.size());
            for (size_t j = 0; j < min_len; ++j) {
                if (w1[j] != w2[j]) {
                    const int u = w1[j] - 'a';
                    const int v = w2[j] - 'a';
                    adj[u].push_back(v);
                    in_degree[v]++;
                    break; // Only the first differing character determines order
                }
            }
        }

        // 3. Kahn's BFS
        std::queue<int> q;
        int unique_chars = 0;
        for (int i = 0; i < 26; ++i) {
            if (in_degree[i] != -1) {
                ++unique_chars;
                if (in_degree[i] == 0) {
                    q.push(i);
                }
            }
        }

        std::string order = "";
        while (!q.empty()) {
            const int u = q.front();
            q.pop();
            order.push_back(static_cast<char>(u + 'a'));

            for (const int v : adj[u]) {
                if (--in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If order length does not match unique character count, a cycle exists
        return (order.size() == unique_chars) ? order : "";
    }
};