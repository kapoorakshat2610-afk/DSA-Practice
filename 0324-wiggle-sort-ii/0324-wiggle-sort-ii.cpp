class Solution {
public:

    int index(int i, int n)
    {
        return (1 + 2 * i) % (n | 1);
    }

    void wiggleSort(vector<int>& nums)
    {
        int n = nums.size();

        // Find median
        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        int median = *midPtr;

        int low = 0;
        int mid = 0;
        int high = n - 1;

        while(mid <= high)
        {
            if(nums[index(mid, n)] > median)
            {
                swap(nums[index(low, n)],
                     nums[index(mid, n)]);
                low++;
                mid++;
            }
            else if(nums[index(mid, n)] < median)
            {
                swap(nums[index(mid, n)],
                     nums[index(high, n)]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }
};