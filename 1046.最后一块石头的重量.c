/*
 * @lc app=leetcode.cn id=1046 lang=c
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
/**方法一：大顶堆（优先队列）
 * 思路：构造大顶堆，每次取两次顶操作
 * T:O(nlogn)
 * S:O(n)
 */

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b, *b = tmp;
    return;
}

void push(int *heap, int *heapSize, int x) {
    heap[++(*heapSize)] = x;
    for (int i = (*heapSize); i > 1 && heap[i] > heap[i >> 1]; i >>= 1) {
        swap(&heap[i], &heap[i >> 1]);
    }
    return;
}

void pop(int *heap, int *heapSize) {
    int tmp = heap[1] = heap[(*heapSize)--];
    int i = 1, j = 2;
    while (j <= (*heapSize)) {
        if (j != (*heapSize) && heap[j + 1] > heap[j]) ++j;
        if (heap[j] > tmp) {
            heap[i] = heap[j];
            i = j;
            j = i << 1;
        } else {
            break;
        }
    }
    heap[i] = tmp;
    return;
}

int top(int *heap) {
    return heap[1];
}

int lastStoneWeight(int* stones, int stonesSize){
    if(stonesSize == 0) return 0;
    if(stonesSize == 1) return stones[0];
    if(stonesSize == 2) return fabs(stones[0]-stones[1]);
    int heap[stonesSize+2], heapSize = 0;
    for(int i=0;i<stonesSize;i++){
        push(heap, &heapSize, stones[i]);
    }
    while(heapSize > 1){
        int max1 = top(heap);
        pop(heap, &heapSize);
        int max2 = top(heap);
        pop(heap, &heapSize);
        if(max1 > max2){
            push(heap, &heapSize, max1-max2);
        }
    }
    return heapSize == 1 ? heap[1] : 0;
}


// @lc code=end

