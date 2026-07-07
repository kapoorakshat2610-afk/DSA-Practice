class Solution {
public:
    bool isfreqsame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int s_len = s.length();
        int p_len = p.length();

        if (s_len < p_len) return result;

        int p_freq[26] = {0};
        int window_freq[26] = {0};

        // 1. Build frequency for string p and the first window of s
        for (int i = 0; i < p_len; i++) {
            p_freq[p[i] - 'a']++;
            window_freq[s[i] - 'a']++;
        }

        // 2. Check the very first window
        if (isfreqsame(p_freq, window_freq)) {
            result.push_back(0);
        }

        // 3. Slide the window across s
        for (int i = p_len; i < s_len; i++) {
            // Add the new character (right side)
            window_freq[s[i] - 'a']++;
            // Remove the old character (left side)
            window_freq[s[i - p_len] - 'a']--;

            if (isfreqsame(p_freq, window_freq)) {
                result.push_back(i - p_len + 1);
            }
        }

        return result;
    }
};