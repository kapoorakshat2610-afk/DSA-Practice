class Solution {
public:
    string compressedString(string word) {
    int n = word.length();
    string result = ""; 
    int i;
    for (i = 0; i < n; i++) {
        char ch = word[i];
        int count = 0;

        // Your while loop logic is good! 
        while (i < n && word[i] == ch && count < 9) {
            count++;
            i++;
        }

        
        result += to_string(count);
        result += ch;

        
        i--; 
    }

    return result;
}
};