class Solution {
public:
    vector<int>funpse(vector<int>& heights)
    {
        int n=heights.size();
        vector<int> leftsmaller(n);
        std::stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                leftsmaller[i]=-1;
            }
            else{
                leftsmaller[i]=st.top();
            }
            st.push(i);
        }
        return leftsmaller;
    }
    vector<int>funnse(vector<int>& heights)
    {
        int n=heights.size();
        vector<int> rightsmaller(n);
        std::stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                rightsmaller[i]=n;
            }
            else{
                rightsmaller[i]=st.top();
            }
            st.push(i);
        }
        return rightsmaller;
    }    
    int largestRectangleArea(vector<int>& heights) {
      int n=heights.size();
      vector<int> nse=funnse(heights);
      vector<int> pse=funpse(heights);
      int maximum=0;
      for(int i=0;i<=n-1;i++)
      {
        maximum=max(maximum,heights[i]*(nse[i]-pse[i]-1));
      }
        return maximum;

    }
};