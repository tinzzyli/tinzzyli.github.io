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
    - [Insertion Sort and Shell Sort](#insertion-sort-and-shell-sort)
        - [Insertion Sort](#insertion-sort)
        - [Shell Sort](#shell-sort)
    - [Merge Sort](#merge-sort)
    - [Quick Sort](#quick-sort)
    - [Radix Sort and Count Sort](#radix-sort-and-count-sort)
        - [Radix Sort](#radix-sort)
        - [Count Sort](#count-sort)

# Introduction

|Name|Time-Complexity|Best Case|Worst Case|Space-Complexity|Stability|Type|Note|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|---|
|Bubble Sort|$$O(n^2)$$|$$O(n)$$|$$O(n^2)$$|$$O(1)$$|yes|In-place|---|
|Selection Sort|$$O(n^2)$$|$$O(n^2)$$|$$O(n^2)$$|$$O(1)$$|no|In-place|invariant complexity|
|Insertion Sort|$$O(n^2)$$|$$O(n)$$|$$O(n^2)$$|$$O(1)$$|yes|In-place|---|
|Shell Sort|
|Merge Sort|$$O(nlog_2n)$$|$$O(nlog_2n)$$|$$O(nlog_2n)$$|$$O(n)$$|yes|Out-place|recursive, quick|
|Quick Sort|

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

### Insertion Sort and Shell Sort

##### Insertion Sort

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

##### Shell Sort

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
    
    public void MergeSort(double[] a){
        double temp = new double[a];
        Sort(a, temp, 0, a.length-1);
    }

    private void Sort(double[] a, double[] temp, int left, int right){
        //when left == right, there is one element in each sub-array, sorted
        if(left < right){
            int middle = (left + right)/2;
            Sort(a, temp, left, middle);
            Sort(a, temp, middle+1, right);
            Merge(a, temp, left, middle, right);
        }//sort
    }

    private void Merge(double[] a, double[] temp, int left, int middle, int right){
        int i = 0;
        int j = left;
        int k = middle+1;
        //Recursion is executed from bottom to top!!
        //exit while loop when either the left half or the right half is empty
        while(j<=middle && k<=right+1){
            temp[i++] = a[j] < a[k] ? a[j++] : a[k++];
        }
        //only one of the following while loop will be executed
        while(j<=middle){
            temp[i++] = a[j++];
        }
        while(k<=right+1){
            temp[i++] = a[k++];
        }
        //put back to a
        for(i = 0; i < k; i++){
            a[left+i] = temp[i];
        }
    }//merge
}
```

### Quick Sort

```markdown
# Pseudo Code
for i = 1 to a.length do
    pivot = a[i]
```

```java
public class SortingAlgorithms {
    public static void main(String[] args) {
        QuickSort();
    }

    public void QuickSort(double[] a, left, right){
        if(left < right){
            int index = Partition(a, left, right);
            QuickSort(a, left, index-1);
            QuickSort(a, index+1, right);
        }
    }//quick sort

    public int Partition(double[] a, left, right){
        int pivot = left;
        int index = pivot + 1;
        for(int i = index; i <= right; i++){
            //ascending
            if(a[i] < a[pivot]){
                Swap(a, i, index);
                index++;
            }
        }
        Swap(a, pivot, index-1);
        return index-1;
    }// partition

    public void Swap(double[] a, int idx1, int idx2){
        int temp = a[idx1];
        a[idx1] = a[idx2];
        a[idx2] = temp;
    }// swap
}
```

### Radix Sort and Count Sort

##### Radix Sort

##### Count Sort
