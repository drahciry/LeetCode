int searchInsert(int* nums, int numsSize, int target) {
    if (numsSize == 0) return 0;

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (target < nums[mid])
            right = mid - 1;
        else if (target > nums[mid])
            left = mid + 1;
        else
            return mid;
    }

    return (target > nums[left]) ? left + 1 : left;
}