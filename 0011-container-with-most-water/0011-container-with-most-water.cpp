class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp=0;
        int rp=height.size()-1;
        int water;
        int hp;
        int ans=0;
        int maxwater=0;
        while(lp<rp)
        {
            water=rp-lp;
            hp=min(height[lp],height[rp]);
            ans=water*hp;
            maxwater=max(maxwater,ans);
            height[lp]<height[rp]?lp++:rp--;


        }
        return maxwater;
    }
};