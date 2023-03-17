---
layout: post
title:  Data Structure Lecture 2
date:   2023-03-16 08:00:00
description: 
tags: Lecture_Notes 
categories: Data_Structure
---

# What is Recursion?

#### A function calls itself is recursion.

- direct recursion
  
```java
public static int fac(int n){
    if(n == 1){return 1;}
    return n*fac(n-1);
}
```

- indirect recursion
  
```java
public static void func1(){
    func2();
}

public static void func2(){
    func1();
}
```


# When to use Recursion?

#### Recursion originates in Mathematical Induction(MI)

MI
1. prove when n == 1, the proposition holds.
2. if when n == k the proposition holds, prove that the proposition holds for n == k+1.

Recursion
1. To solve n == k, we need to know the result of n == k-1
2. To solve n == k-1, we need to know the result of n == k-2..., this is a so-called bottom-up process.
3. Solve n == 1, then n == 2..., n == k

#### Fibonacci
```java
public static int Fib(int n){
    if (n == 1){return 1;}
    return Fib(n-1) + Fib(n-2);
}

public static int Fib_iter(int n){
    if (n < 3){return 1;}
    int fib0, fib1, fib2;
    
    for (int i=2; i<=n; i++) {
        
        
    }
    return fib2;
}
```

#### Factorial
```java
public static int Fac(int n){
    if (n == 1){return 1;}
    return n*Fac(n-1);
}
```

#### Hanoi Tower
```java
public static void Hanoi(char A, char B, char C, int n){
    if (n == 1){
        System.out.printf("move %d from %c to %c \n", n, A, C);
    }
    Hanoi(A, C, B, n-1);
    System.out.printf("move %d from %c to %c \n", n, A, C);
    Hanoi(B, A, C, n-1);
}
```

#### Quick Sort
```java
public static void quickSort(double[] a, int left, int right){
    if(left<=right){
        partition_index = partition(a, left, right);
        quickSort(a, left, partition_index-1);
        quickSort(a, partition_index+1, right);
    }
}

public static int partition(double[] a, int left, int right){
    int partition_index = left-1;
    for (int i = left; i < right; i++){
        if(a[i] < a[right]){
            partition_index++;
            swap(a, partition_index, i);
        }//if
    }//for loop
    partition_index++;
    swap(a, right, partition_index);
    return partition_index;
}

public static void swap(double[] a, int idx1, int idx2){
    double temp = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = temp;
}
```

# What is the differnece between Recursion and Iteration?

In a iteration, we proceed a loop from initial state to terminal state.

In a recursion, we have a tree-like structure, we first go to the bottom of it then execute the function bottom -> top.