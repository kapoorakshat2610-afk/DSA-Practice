class Solution {
public:
    int commonFactors(int a, int b) {
        int gcdValue = findGCD(a, b);
    
    
    int count = 0;
    for (int i = 1; i <= gcdValue; i++) {
        if (gcdValue % i == 0) {
            count++;
        }
    }
    return count;
}


int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
    }
};