int maxArea(int* height, int heightSize) {
    int start = 0;
    int end = heightSize - 1;
    int max_area = 0;

    while (start < end) {
        int current_width = (end - start);
        int current_height = MIN(height[start], height[end]);
        int current_area = (current_width * current_height);

        max_area = MAX(current_area, max_area);

        if (height[start] < height[end])
            start++;
        else
            end--;
    };

    return max_area;
}