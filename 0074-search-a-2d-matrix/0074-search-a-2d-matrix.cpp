class Solution {
public:
    bool searchinrow(vector<vector<int>>& matrix, int target,int row)
    { int n=matrix[0].size();
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(matrix[row][mid]==target)
        {
            return true;
        }
        else if(target>matrix[row][mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //BS ON TOTAL NO.OF ROWS
        int m=matrix.size(),n=matrix[0].size();
        int startrow=0 ,endrow=m-1;
        while(startrow<=endrow)
        {
            int midrow=startrow+(endrow-startrow)/2;

            if(target>=matrix[midrow][0]&&target<=matrix[midrow][n-1])
            { //found the row=>BS on this row
            return searchinrow(matrix,target,midrow);
            }
            else if(target>=matrix[midrow][n-1])
            { //down=>right
            startrow=midrow+1;
            }
            else{ //up=>left
            endrow=midrow-1;
            }
        }
        return false;
    }
};