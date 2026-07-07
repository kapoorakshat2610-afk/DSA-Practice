int findClosest(int x, int y, int z) {
    int i;
    int j;
    i=abs(x-z);
    j=abs(y-z);
    if(i<j){
        return 1;
    }
    else if(j<i){
        return 2;

    }
    else{
        return 0;
    }

    
}