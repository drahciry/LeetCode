int climbStairs(int n) {
    int prev1 = 1;
    int prev2 = 1;
    int result = prev2;

    for (int i = 2; i <= n; i++) {
        result = prev1 + prev2;
        prev2 = prev1;
        prev1 = result;
    };

    return result;
}