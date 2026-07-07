bool checkPerfectNumber(int num) {
    int i;
    int j=0;
    for(i=1;i<=num/2;i++)
    {
        if(num%i==0)
        {
            j=j+i;

        }
    }
    if(j==num)
    {
        return true;
    }
    else{
        return false;
    }
    
    
}