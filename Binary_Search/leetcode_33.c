int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }

    int pivot = left;

    if (target >= nums[pivot] && target <= nums[numsSize - 1]) {
        left = pivot;
        right = numsSize - 1;
    } else {
        left = 0;
        right = pivot - 1;
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}