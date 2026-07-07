class Solution {
public:
bool isfreqsame(int freq1[],int freq2[])
{
    for(int i=0;i<26;i++)
    {
        if(freq1[i]!=freq2[i])
        {
            return false;
        }
    }
return true;
}
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            freq[s1[i]-'a']++;
        }
        int size=s1.length();
        for(int i=0;i<s2.length();i++)
        {
            int winind=0;
            int indx=i;
            int winfrq[26]={0};
            while(winind<size&&indx<s2.length())
            {
                winfrq[s2[indx]-'a']++;
                winind++;
                indx++;

            }
            if(isfreqsame(freq,winfrq))
            {
                return true;
            }
        }
        return false;
    }
};