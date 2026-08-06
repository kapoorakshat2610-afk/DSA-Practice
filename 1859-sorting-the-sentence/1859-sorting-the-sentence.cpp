class Solution {
public:
    string sortSentence(string s) {
    vector<string> words(10);
    stringstream ss(s);
        string word;

        while (ss >> word)
        {
            int pos = word.back() - '0'; 
            word.pop_back();            
            words[pos] = word;          
        }

        string ans;

        for (int i = 1; i < 10; i++)
        {
            if (words[i] != "")
            {
                if (!ans.empty())
                    ans += " ";

                ans += words[i];
            }
        }

        return ans;
    }
};