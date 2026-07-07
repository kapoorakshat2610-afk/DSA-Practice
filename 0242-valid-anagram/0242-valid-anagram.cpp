class Solution {
public:
    bool isAnagram(string s, string t) {
        // 1. If lengths differ, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        int freq[26] = {0};

        // 2. Count frequencies
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++; // Add for s
            freq[t[i] - 'a']--; // Subtract for t
        }

        // 3. If it's an anagram, all counts must be 0
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};