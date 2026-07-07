class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.length();
        int i;
        string ans="";
        for( i=0;i<n;i++)
        {
            string word="";
            while(i < n && s[i] !=' ')
            {
                word+=s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(word.length()>0)
            {
                ans+=" "+word;
            }

        }
        return ans.substr(1);
    }
};