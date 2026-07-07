class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i;
        int j;
        vector<int>result;
        for(i=0;i<nums1.size();i++)
        {
            for(j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    bool already = false;
                    for (int k = 0; k < result.size(); k++) {
                        if (result[k] == nums1[i]) {
                            already = true;
                            break;
                        }
                    }

                    // only push if not present yet
                    if (!already) {
                        result.push_back(nums1[i]);
                    }

                    // no need to keep checking nums2 for this nums1[i]
                    break;
                }

            }
        }
        return result;
    }
};