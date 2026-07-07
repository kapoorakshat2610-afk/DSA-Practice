class Solution {
public:
    void reverseString(vector<char>& s) {
        int str=s.size()-1;
        int start=0;
        int end=str;
        while(start<end){
            swap(s[start++],s[end--]);

        }   
         }
};