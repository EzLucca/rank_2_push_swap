/*
基数排序 (Radix Sort)
基数排序是一种非比较型排序算法，适用于整数排序。它通过对每位数字进行排序来实现整体排序。基数排序从最低有效位（个位）开始，将数字分配到对应的桶中，然后收集并重新分配数字，逐位排序直到最高有效位。

算法步骤
确定最大位数：
找到数组中最大数字的位数，确定排序需要多少轮。例如，对于数字 170, 45, 75, 90, 802, 24, 2, 66，最大数字是 802，它有 3 位，因此需要进行 3 轮排序。

按位数进行排序：
从最低有效位（个位）开始，对数组进行排序。使用计数排序或桶排序来排序每一位的数字。

详细步骤
准备桶：
创建 10 个桶（0 到 9），每个桶对应一个数字（0-9）。

分配桶：
遍历数组中的每个数字，根据当前位的数字，将其放入对应的桶中。例如，对于个位数，如果数字是 170，它的个位数是 0，所以将其放入桶 0 中。

收集数字：
按桶的顺序（从 0 到 9）收集数字，重新排列数组。

移动到下一位：
移动到下一位（十位、百位等），重复上述分配桶和收集数字的过程。

重复直到最高有效位：
重复上述过程，直到处理完最高有效位。
*/

#include<stdio.h>
#define MAX 20
//#define SHOWPASS
#define BASE 10

void print(int *a, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
}

void radixsort(int *a, int n) {
  int i, b[MAX], m = a[0], exp = 1;

  for (i = 1; i < n; i++) {
    if (a[i] > m) {
      m = a[i];
    }
  }

  while (m / exp > 0) {
    int bucket[BASE] = { 0 };

    for (i = 0; i < n; i++) {
      bucket[(a[i] / exp) % BASE]++;
    }

    for (i = 1; i < BASE; i++) {
      bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
      b[--bucket[(a[i] / exp) % BASE]] = a[i];
    }

    for (i = 0; i < n; i++) {
      a[i] = b[i];
    }

    exp *= BASE;

#ifdef SHOWPASS
    printf("\nPASS   : ");
    print(a, n);
#endif
  }
}

int main() {
  int arr[MAX];
  int i, n;

  printf("Enter total elements (n <= %d) : ", MAX);
  scanf("%d", &n);
  n = n < MAX ? n : MAX;

  printf("Enter %d Elements : ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nARRAY  : ");
  print(&arr[0], n);

  radixsort(&arr[0], n);

  printf("\nSORTED : ");
  print(&arr[0], n);
  printf("\n");

  return 0;
}