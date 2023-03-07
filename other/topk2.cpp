#include <stdio.h>
#include <stdlib.h>

// 定义取最大N个数
#define TOP_K 6
int heap[6];

// 交换数据
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// 调整最小堆
void min_heapify(int arr[], int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
    {
        if (son + 1 <= end && arr[son] > arr[son + 1])
            son++;
        if (arr[dad] < arr[son])
            return;
        else
        {
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

// 建立最小堆
void buid_heap(int heap[])
{
    int i;
    for (i = TOP_K / 2; i >= 0; i--)
    {
        min_heapify(heap, i, TOP_K - 1);
    }
}

// 8,8,8,9,9,9
int main()
{
    int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1};
    int len = (int)sizeof(arr) / sizeof(*arr);
    int i;

    // 堆赋值
    for (i = 0; i < TOP_K; i++)
    {
        heap[i] = arr[i];
    }

    buid_heap(heap); // 建立最小堆

    // 循环遍历整个数组
    for (i = TOP_K + 1; i <= len; i++)
    {
        if (arr[i] > heap[0]) // 只有大于根节点才处理
        {
            heap[0] = arr[i];
            min_heapify(heap, 0, TOP_K - 1); // 向下调整堆
        }
    }

    // 打印最大key个数
    for (i = 0; i < TOP_K; i++)
    {
        printf("%d\n", heap[i]);
    }
}