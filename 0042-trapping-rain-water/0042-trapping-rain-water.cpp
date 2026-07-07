class Solution {
public:
    int trap(vector<int>& height) {
    int n=height.size();
    int water=0;
    if(n==0)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {
      int leftmax=height[0];
      int rightmax=height[n-1];
       for(int l=0;l<=i;l++)
       {
          leftmax=max(leftmax,height[l]);
       }
       for(int r=i;r<n;r++)
       {
          rightmax=max(rightmax,height[r]);
       }
       int trap=(min(leftmax,rightmax)-height[i]);
       if(trap>0)
       {
        water=water+trap;
       }
    }
    return water;
    }
};