class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
           int m=matrix.size();
           int n=matrix[0].size();
           int row=0;
           int column=n-1;
           while(column>=0&&row<m)
           {
            if(target==matrix[row][column])
            {
                return true;
            }
            else if(target<matrix[row][column])
            {
                column--;
            }
            else{
                row++;
            }
           }
           return false;
    }
};