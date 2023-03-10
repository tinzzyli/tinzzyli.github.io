---
layout: post
title:  Data Structure Lecture 1
date:   2023-02-27 08:00:00
description: 
tags: DataStructure 
categories: Lecture-Notes
---

- [Introduction](#introduction)
- [Sorting Algorithms and Java Implementation](#sorting-algorithms-and-java-implementation)
    - [Bubble Sort](#bubble-sort)
    - [Selection Sort](#selection-sort)
    - [Insertion Sort](#insertion-sort)
    - [Shell Sort](#shell-sort)
    - [Merge Sort](#merge-sort)
    - [Quick Sort](#quick-sort)

# Introduction

|Name|Time-Complexity|Best Case|Worst Case|Space-Complexity|Stability|Type|Note|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|---|
|Bubble Sort|$$O(n^2)$$|$$O(n)$$|$$O(n^2)$$|$$O(1)$$|yes|In-place|---|
|Selection Sort|$$O(n^2)$$|$$O(n^2)$$|$$O(n^2)$$|$$O(1)$$|no|In-place|invariant complexity|
|Insertion Sort|$$O(n^2)$$|$$O(n)$$|$$O(n^2)$$|$$O(1)$$|yes|In-place|---|
|Shell Sort|$$O(nlog_2n)$$|$$O(nlog_2^2n)$$|$$O(n^2)$$|$$O(1)$$|no|In-place|a quicker insertion sort
|Merge Sort|$$O(nlog_2n)$$|$$O(nlog_2n)$$|$$O(nlog_2n)$$|$$O(n)$$|yes|Out-place|recursive|
|Quick Sort|$$O(nlog_2n)$$|$$O(nlog_2n)$$|$$O(n^2)$$|$$O(log_2n)$$|no|In-place|recursive|

# Sorting Algorithms and Java Implementation

### Bubble Sort

```markdown
# Pseudo Code
//maintain j as the right boundary of the window
for i = length(a) to 1 do 
    for j = 1 to i do
        //sort element from small to big
        if a[i] > a[i+1]
            swap position
```

```java
public class SortingAlgorithms {
    public static void main(String[] args) {
        BubbleSort();
    }

    public void BubbleSort(double[] a){
        double temp = 0.0;
        boolean swap;
        for(i = a.length - 1; i >= 0; i--){
            swap = false;
            for(j = 0; j < i, j++){
                if(a[j] >= a[j+1]){
                    // swap
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    swap = true;
                }
            }//loop j
            if(swap == false){
                // array is sorted, when no swap occurred in the last j loop
                break;
            }
        }//loop i
    }//bubble sort
}
```

### Selection Sort

```markdown
# Pseudo Code
init temp, min = null
for i = 1 to length(a) do
    //j loop in bubble sort
    min = i;
    for j = i+1 to length(a) do
        if a[j] > a[j+1]
            min = j+1
    //min is index of the smallest unsorted element
    if min != i
        swap position of a[i] and a[min]
```

```java
public class SortingAlgorithms {
    public static void main(String[] args) {
        SelectionSort();
    }

    public void SelectionSort(double[] a){
        double min, temp;
        for(i = 0; i < a.length - 1; i++){
            min = i;
            for(j = i + 1; j < a.length - 1; j++){
                //j is the left boundary of the window
                if(a[j] > a[j+1]){
                    min = j + 1;
                }
            }//j loop
            if(min != i){
                //find the smallest unsorted element then swap pos with the first unsorted element
                temp = a[i]
                a[i] = a[min]
                a[min] = temp
            }
        }//i loop
    }//selection sort
}
```

### Insertion Sort

```markdown
# Pseudo Code
init value, position = null
for i = 2 to length(a) do
    value = a[i]
    position = i
    //find where should a[i] be
    //use a[position-1] < value for descending 
    while position > 0 and a[position-1] > value
        //move element 1 step backward
        a[position] = a[position-1]
        position--
    //put value in the desired place
    a[position] = value
```

```java
public class SortingAlgorithms {
    public static void main(String[] args) {
        InsertionSort();
    }
    public void InsertionSort(double[] a){
        for(i = 1; i < a.length; i++){
            int value = a[i];
            int position = i;
            while(position > 0 && a[position-1] > value){
                a[position] = a[position-1];
                position--;
            }//while loop
            a[position] = value;
        }//i loop
    }//insertion sort
}
```

### Shell Sort

```markdown
# Pseudo Code
init gap
init temp
//gap value is arbitrary
for gap = a.length and gap >= 1 do
    gap = gap/2
    for i = gap to a.length do
        i++
        //if right < left, swap
        for j = i and j > gap and a[j] < a[j-gap]
            swap position of a[j] and a[j-gap]
            //iterate f
            j-=gap
```

```java
public class SortingAlgorithms {
    public static void main(String[] args) {
        ShellSort();
    }

    // Vanilla Shell Sort by Donald Shell
    public void ShellSort(double[] a){
        int temp;
        for(int gap = a.length; gap >= 1; gap /= 2){
            for(int i = gap; i < a.length; i++){
                for(int j = i; j >= gap && a[j] < a[j-gap]; j-=gap){
                    temp = a[j];
                    a[j] = a[j-gap];
                    a[j-gap] = temp;
                }//j loop
            }//i loop
        }//gap loop
    }//shell sort

    //O(1.5n) shell sort by Knuth
    public void KnuthShellSort(double[] a){
        int gap = 1;
        while(gap , a.length/3){
            gap = gap*3 + 1;
        }

        int temp;
        for(; gap >= 1; gap /= 3){
            for(int i = gap; i < a.length; i++){
                for(int j = i; j >= gap && a[j] < a[j-gap]; j-=gap){
                    temp = a[j];
                    a[j] = a[j-gap];
                    a[j-gap] = temp;
                }//j loop
            }//i loop
        }//gap loop
    }
}
```

### Merge Sort

```markdown
# Pseudo Code
init left = 0
init right = a.length - 1
init temp
while left < right do
    sort left half of the array
    sort right half of the array
    Merge()

Merge():
    init i = 0;
    for j = left in Left_half, k = middle in Right_half do
        temp[i] = min(Left_half[j], Right_half[k])
    \\now either one half is empty, put the rest element in array
    \\put elements back to a 
```

```java
public class SortingAlgorithms {
    public static void main(String[] args) {
        MergeSort();
    }
    public static void MergeSort(double[] a){
        double[] temp = new double[a.length];
        Split(a, temp, 0, a.length-1);
        System.out.println(Arrays.toString(a));
    }

    public static void Split(double[] a, double[] temp, int left, int right){
        if(left<right){
            int mid = (left + right)/2;
            Split(a, temp, left, mid);
            Split(a, temp, mid+1, right);
            Merge(a, temp, left, mid, right);
        }
    }

    public static void Merge(double[] a, double[] temp, int left, int mid, int right){
        int i = 0;
        int j = left;//left pointer
        int k = mid+1;//right pointer
        while (j <= mid && k <= right){
            temp[i++] = a[j] <= a[k] ? a[j++] : a[k++];
        }
        while(j<=mid){
            temp[i++] = a[j++];
        }
        while(k<=right){
            temp[i++] = a[k++];
        }
        for(int n=0; n<i; ++n){
            a[left+n] = temp[n];
        }
    }
}
```

### Quick Sort

```markdown
# Pseudo Code
init left, right = 1, a.length
def quick_sort
    if  left < right
        pivot_index = partition(a, left, right)
        quick_sort(a, left, pivot_index - 1)
        quick_sort(a, pivot_index + 1, right)

def partition
    init p = left-1 
    for i = left to right-1
        if(a[i] < a[right])
            p++
            swap(i, p)
    p++
    swap(right, p)
            
```

```java
public class SortingAlgorithms {
    public static void main(String[] args) {
        QuickSort();
    }

    public static void QuickSort(double[] a, int left, int right){
        if(left < right){
            int Partition_index = Partition(a, left, right);
            QuickSort(a, left, Partition_index-1);
            QuickSort(a, Partition_index+1, right);
        }

    }//quick sort

    public static int Partition(double[] a, int left, int right){
        int p = left-1;
        for (int i = left; i < right; i++){
            //the interval [p+1, i] is where the smaller numbers in
            if (a[right] > a[i]){
                //we assume pivot is the smallest element in a sub-array
                p++;
                Swap(a, i, p);
                //move smaller elements to left side

            }
        }
        p++;
        Swap(a, right, p);
        return p;
    }//partition

    public static void Swap(double[] a, int idx1, int idx2){
        double temp = a[idx1];
        a[idx1] = a[idx2];
        a[idx2] = temp;
    }//swap
}
```
