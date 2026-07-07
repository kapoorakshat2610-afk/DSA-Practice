int findLucky(int* arr, int arrSize) {
    int i;
    int j;
    int lucky=-1;
    for(i=0;i<arrSize;i++)
    {
        int count=0;
        for(j=0;j<arrSize;j++)
        {
            if(arr[i]==arr[j])
            {
                count ++;
            }
        }
        if((arr[i]==count)&&(arr[i]>lucky)){
        lucky=arr[i];
        }
    }
    return lucky;
}    