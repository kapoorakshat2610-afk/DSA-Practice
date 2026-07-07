class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int indx=0;
        int count;
        char ch;
        int i;
        for(i=0;i<n;i++)
        {
            ch=chars[i];
            count=0;
            while(i < n && chars[i]==ch)
            {
                count++;
                i++;
            }
        if(count==1)
        {
            chars[indx++]=ch;
        }
        else{
            chars[indx++]=ch;
            string str=to_string(count);
            for(char dig:str)
            {
                chars[indx++]=dig;
            }
        }
        i--;
        }
        
        chars.resize(indx);
        return indx;
    }
};