/*
https://www.runoob.com/w3cnote/insertion-sort.html
插入排序 (Insertion Sort)
插入排序是一种简单直观的排序算法。它通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

算法步骤：

从第二个元素开始，假设第一个元素已经被排序。
取出下一个元素，在已经排序的元素序列中从后向前扫描。
如果已排序的元素大于新元素，则将已排序的元素向右移动一位。
直到找到已排序的元素小于或等于新元素的位置。
将新元素插入到该位置中。
重复上述步骤，直到所有元素都被排序。

*/

void insertion_sort(int arr[], int len){
        int i,j,key;
        for (i=1;i<len;i++){
                key = arr[i];
                j=i-1;
                while((j>=0) && (arr[j]>key)) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
        }
}