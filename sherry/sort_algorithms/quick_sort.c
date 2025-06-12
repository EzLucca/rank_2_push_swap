/*
https://www.runoob.com/w3cnote/quick-sort-2.html
快速排序（Quick Sort）是一种高效的排序算法，它使用分治法（Divide and Conquer）策略将一个数组分成较小的子数组来排序。下面是快速排序算法的详细步骤和Python实现。

快速排序 (Quick Sort)
算法步骤
选择基准：从数组中选择一个元素作为基准（pivot）。
分区：重新排列数组，使得所有比基准小的元素都在基准前面，所有比基准大的元素都在基准后面（相等的元素可以放在任一边）。这个过程称为分区（partitioning）。
递归排序：分别对基准前面的子数组和基准后面的子数组递归地应用上述步骤。
详细步骤
选择基准：
选择数组中的一个元素作为基准。基准的选择方法可以是选择第一个元素、最后一个元素、随机选择或者选择中间元素。

分区过程：
使用两个指针，一个从左向右扫描，一个从右向左扫描。左指针找到比基准大的元素，右指针找到比基准小的元素，然后交换它们的位置，直到两个指针相遇。最后，将基准元素放到正确的位置。

递归调用：
对基准左侧的子数组和右侧的子数组递归进行快速排序，直到子数组的长度为零或一（此时子数组已经有序）。
*/

// recursive solution
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

#if 0

typedef struct _Range {
    int start, end;
} Range;

Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void quick_sort(int arr[], const int len) {
    if (len <= 0)
        return; // 避免len等於負值時引發段錯誤（Segment Fault）
    // r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        int mid = arr[(range.start + range.end) / 2]; // 選取中間點為基準點
        int left = range.start, right = range.end;
        do {
            while (arr[left] < mid) ++left;   // 檢測基準點左側是否符合要求
            while (arr[right] > mid) --right; //檢測基準點右側是否符合要求
            if (left <= right) {
                swap(&arr[left], &arr[right]);
                left++;
                right--;               // 移動指針以繼續
            }
        } while (left <= right);
        if (range.start < right) r[p++] = new_Range(range.start, right);
        if (range.end > left) r[p++] = new_Range(left, range.end);
    }
}

#endif