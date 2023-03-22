---
layout: post
title:  Data Structure Lecture 3
date:   2023-02-27 08:00:00
description: 
tags: Lecture_Notes 
categories: Data_Structure Heap
---

# Heap Algorithms

Heap is in fact an array, it has a structure as below:

|index|0|1|2|3|4|5|6|7|8|9|
|---|---|---|---|---|---|---|---|---|---|---|
|value|31|14|15|19|26|53|58|97|93|23|

![pic1](https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/_images/BinArray.png)

Heap is a binary-tree-like data structure as it it shown in the picture above [<sup>1</sup>](#refer-anchor-1). As indexed from $0$ to $arr.length-1$, the relationship between parent node and children nodes can be demostrated as:
$$ $$
$$ left\_child = parent * 2 + 1 $$
$$ right\_child = parent * 2 + 2 $$
$$ parent = \lfloor(child-1)/2\rfloor$$

To better understand Heap, we do 7 steps from easy to hard:

- Max-Heapify
- Build-Max-Heap
- HeapSort
- Heap-Extract-Max
- Heap-Maximum
- Max-Heap-Increase-Key
- Max-Heap-Insert

## Max Heapify

MaxHeapify is a recursion process. **Assumed that the left branch and right branch of node $i$ are max heaps**, calling MaxHeapify at $i$ would move $i$ from top to a proper position recursively. Please pay attention to the terminal state of the recursion.

Note that:

- Index out of range check should go first

```java
public static void MaxHeapify(double[] a, int parent_idx, int heapSize){
    int left_child_idx = 2*parent_idx + 1;
    int right_child_idx = 2*parent_idx + 2;
    int larger_idx = parent_idx;

    //note that here you compare left/right child with the LARGER INDEX, not the parent index
    if(left_child_idx < heapSize && a[left_child_idx] > a[larger_idx]){
        larger_idx = left_child_idx;
    }

    if(right_child_idx < heapSize && a[right_child_idx] > a[larger_idx]){
        larger_idx = right_child_idx;
    }
    //either of the if will be executed

    if(larger_idx != parent_idx){
        swap(a, larger_idx, parent_idx);
        MaxHeapify(a, larger_idx, heapSize);
    }
}
```

## Build Max Heap
When iteratively called MaxHeapify on each node from $\lfloor arr.length/2\rfloor$ to $0$, the array is now a max heap.

Note that:
1. **Iteration starts from $\lfloor arr.length/2\rfloor$ to $0$.**
2. $i$ value decreases in the iteration.
```java
public static void BuildMaxHeap(double[] a){
    int heapSize = a.length;
    //mind the boundary of i
    for(int i = (int)(Math.floor(a.length/2)); i>=0; i--){
        MaxHeapify(a, i, heapSize);
    }//end for loop
}
```

## Heap Sort
By re-use the codes above, we can swap the $0^{th}$ element and the $arr.length-1^{th}$ element, detached the last element, then do Build Max Heap at $0^{th}$ node.

This can work because the character of Max Heap: the first element is the biggest. We use a for loop to iteratively detach the biggest element in the array, a ascending sorted array can be formed.

Note that:

- the array **MUST** be a Max Heap before swap, and this rule works for **every** function mentioned below.

```java
public static void HeapSort(double[] a){
    //int heapSize = a.length;
    //BuildMaxHeap(a);
    for(int i = a.length-1; i>=0; i--){
        swap(a, i, 0);
        //heapSize--;
        //you can explicitly define a heapSize to make codes clearer

        //note that max-heap-sort is in ascending order
        MaxHeapify(a, 0, i);
    }//end for loop
}//heap sort
```

## Heap Extract Max
To remove the biggest element(of course you can also return it), we simply do:
```java
a[0] = a[a.length-1];
```
Then MaxHeapify the array
Note that:

- To detach the element, you need to do **HeapSize--**
```java
public static void HeapExtractMax(double[] a) {
    //BuildMaxHeap(a);
    a[0] = a[a.length-1];
    MaxHeapify(a, 0, a.length-2);
}//extract max element
```
## Max Heap Increase Key
Increasing the value of a node **will ONLY** affect its parent node and its parent's parent...

Be careful: Key value must be large than current value.
```java
public static int getParentIndex(int currIndex){
    return (int) Math.floor((currIndex-1)/2);
}

public static void MaxHeapIncreaseKey(double[] a, int i, double value){
    
    if(value > a[i]) {
        a[i] = value;
        //BuildMaxHeap(a);
        //compare with its parent node, if a[parent] < a[current] then swap
        while (i > 0 && a[i] > a[getParentIndex(i)]) {
            swap(a, i, getParentIndex(i));
            i = getParentIndex(i);
        }//end while loop
    }//end if
}
```

## Max Heap Insert
Tricky: re-use code MaxHeapIncreaseKey

Note that:

- Implementation below copy the original array, which means modifications are made on the new array, be careful.
```java
public static void MaxHeapInsert(double[] a, double value){
    double[] heap = new double[a.length+1];
    System.arraycopy(a, 0, heap, 0, a.length);
    heap[heap.length-1] = -Double.MAX_VALUE;
    MaxHeapIncreaseKey(heap, heap.length-1, value);
}
```

## TimeComplexity Analysis
|Max Heapify|Build Max Heap|Increase Key|Heap Sort|Extract Max|Heap Insert|
|:---:|:---:|:---:|:---:|:---:|:---:|
|$O(log\ n)$|$O(n)$|$O(log\ n)$|$O(nlog\ n)$|$O(log\ n)$|$O(log\ n)$|

Homework: Prove the tighter bound of the time complexity of Build Max Heap.


<div id="refer-anchor-1"></div>

[1] picture sourced from [OpenDSA](https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/_images/BinArray.png).

<div id="refer-anchor-1"></div>

[2] When I wrote this post, I found this [handout](https://courses.csail.mit.edu/6.006/fall10/handouts/recitation10-8.pdf) from CSAIL really helpful.