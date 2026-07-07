bool isPalindrome(int x)
{
    if(x<0)
    {
        return false;
    }
    int temp;
    temp=x;
    int count=log10(x)+1;
    int rev;
    long int sum=0;
    while(x!=0)
    {
        rev=x%10;
        sum=(sum*10)+rev;
        x=x/10;
    }
    x=temp;
    if(sum==x)
    {
        return true;
    } 
    else
    {
        return false;
    }
}   