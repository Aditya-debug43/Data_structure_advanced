void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    quickSort(nums, 0, numsSize - 1);
    int fix = 0;
    int left = 1;
    int sum = 0;
    int negativedis = INT_MAX;
    int positivedis = INT_MAX;
    int right = numsSize - 1;
    while (fix <= numsSize - 3) {
        if (fix > 0 && nums[fix] == nums[fix - 1]) {
            fix++;
            left = fix + 1;
            right = numsSize - 1;
            continue;
        }
        int temp1;
        int temp2;
        while (left < right) {
            sum = nums[left] + nums[right] + nums[fix];
            if (sum > target) {
                temp1 = sum - target;
                right--;
                positivedis = min(positivedis, temp1);
            } else {
                temp2 = target - sum;
                left++;
                negativedis = min(negativedis, temp2);
            }
        }
        fix++;
        left = fix + 1;
        right = numsSize - 1;
    }
    if (negativedis < positivedis)
        return target - negativedis;
    else
        return target + positivedis;
}
