bool isPerfectSquare(int num) {
    if (num < 0) {
        return false; // Negative numbers cannot be perfect squares
    }
    if (num == 0 || num == 1) {
        return true; // 0 and 1 are perfect squares
    }

    int left = 1, right = num / 2; // Set the search range
    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevent overflow
        long long square = (long long)mid * mid; // Use long long to prevent overflow
        if (square == num) {
            return true; // Found the perfect square
        } else if (square < num) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return false; // Not a perfect square
}
