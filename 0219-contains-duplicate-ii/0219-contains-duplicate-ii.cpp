class Solution {
public:
typedef struct {
    int value;
    bool occupied;
} HashEntry;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int numsSize=nums.size();
        if (numsSize <= 1 || k <= 0) return false;

    // To handle the "last test case" (usually large k), 
    // we cap the table size to avoid massive memory allocation.
    int tableSize = (numsSize < k) ? numsSize * 2 : k * 2;
    if (tableSize < 10) tableSize = 10; // Minimum size

    HashEntry* table = (HashEntry*)calloc(tableSize, sizeof(HashEntry));
    if (!table) return false; 

    for (int i = 0; i < numsSize; i++) {
        // 1. Remove the element that is now too far away (> k)
        if (i > k) {
            int outVal = nums[i - k - 1];
            unsigned int h = (unsigned int)outVal % tableSize;
            while (table[h].occupied) {
                if (table[h].value == outVal) {
                    table[h].occupied = false; // "Remove" it
                    break;
                }
                h = (h + 1) % tableSize;
            }
        }

        // 2. Search and Insert the current element
        int curVal = nums[i];
        unsigned int h = (unsigned int)curVal % tableSize;
        
        // Find an empty spot or the existing value
        while (table[h].occupied && table[h].value != curVal) {
            h = (h + 1) % tableSize;
        }

        if (table[h].occupied && table[h].value == curVal) {
            free(table);
            return true; // Found within distance k!
        }

        // Place the new value in the window
        table[h].value = curVal;
        table[h].occupied = true;
    }

    free(table);
    return false;
    }
};