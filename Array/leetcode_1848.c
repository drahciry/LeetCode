int getMinDistance(int* nums, int numsSize, int target, int start) {
    int diff = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            int myAbs = abs(i - start);
            diff = (diff < myAbs) ? diff : myAbs;
        }
    }
            
    return diff;
}