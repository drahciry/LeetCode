/*
 * Problem: Median Of Two Sorted Arrays (LeetCode 4)
 * Time Complexity: O(M + N) - M is num1 size and N is num2 size
 * Memory Complexity: O(M + N)
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if ((nums1Size == 0) && (nums2Size == 0)) return 0.0;

    int newSize = nums1Size + nums2Size;
    int mid = newSize / 2;
    int merged[newSize];
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size)
        if (nums1[i] <= nums2[j])
            merged[k++] = nums1[i++];
        else if (nums2[j] < nums1[i])
            merged[k++] = nums2[j++];

    while (i < nums1Size)
        merged[k++] = nums1[i++];

    while (j < nums2Size)
        merged[k++] = nums2[j++];

    return (newSize % 2 == 0) ? (merged[mid] + merged[mid - 1]) / 2.0 : merged[mid];
}