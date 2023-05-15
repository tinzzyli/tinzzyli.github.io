---
layout: post
title:  Data Structure Lecture 8
date:   2023-05-13 08:00:00
description: 
tags: Lecture_Notes 
categories: Data_Structure DynamicProgramming
---

[TOC]

# Dynamic Programming

The main idea behind dynamic programming is to break down a complex problem into smaller overlapping subproblems, solve those subproblems, and build up the solution by combining the results of the subproblems. DP aims to avoid redundant calculations by storing the solutions to subproblems and reusing them as needed. This approach can significantly improve the efficiency of algorithms for problems that exhibit optimal substructure and overlapping subproblems.

The two main techniques used in dynamic programming are:

1. Top-down approach (Memoization): This approach starts with the original problem and breaks it down into smaller subproblems. It uses memoization to store the solutions to subproblems and checks the memoization table before solving a subproblem to avoid redundant calculations. This approach often involves recursion to solve the subproblems.

2. Bottom-up approach: This approach builds the solution iteratively, starting from the base case or the smallest subproblem and gradually solving larger subproblems until the original problem is solved. It avoids recursion and solves each subproblem only once, storing the solutions in a table or array. This approach is more iterative and follows a tabulation technique.

## Climb Stairs

```java
public static int ClimbStairs(int num){
    // assume that one, two or three steps each time can be taken
    if(num == 1){
        return 1;
    }
    if(num == 2){
        return 3;
    }
    if(num == 3){
        return 4;
    }
    return ClimbStairs(num-1) + ClimbStairs(num-2) + ClimbStairs(num-3);
}
```

## Unique Path 1

```java
public static int UniquePath1(int m, int n){
    // solving problem 62 in leetcode.com
    // robot at top left, exit at bottom right, move 1 grid each move in an m*n grid
    // find how many unique path in total
    int [][] grid = new int [m][n];

    for(int i = 0; i < grid.length; i++){
        Arrays.fill(grid[i], 0);
    }

    Arrays.fill(grid[0], 1);

    for(int i = 0; i < grid.length; i++){
        grid[i][0] = 1;
    }

    for(int j = 1; j < grid.length; j++){
        for(int k = 1; k < grid[0].length; k++){
            grid[j][k] = grid[j-1][k] + grid[j][k-1];
        }
    }

    return grid[m-1][n-1];
}
```

## Unique Path 2

```java
public static int UniquePath2(int [][] grid){
    // the grid may contain obstacle that marked as 1, space marked as 0
    if(grid[grid.length-1][grid[0].length-1] == 1 || grid[0][0] == 1)
    {
        return 0;
    }

    int flag = 1;

    for(int i = 0; i < grid[0].length; i++){
        if(grid[0][i] == 1){
            flag = 0;
        }
        grid[0][i] = flag;
    }

    flag = 1;

    for(int i = 1; i < grid.length; i++){
        if(grid[i][0] == 1){
            flag = 0;
        }
        grid[i][0] = flag;
    }


    for(int j = 1; j < grid.length; j++){
        for(int k = 1; k < grid[0].length; k++){
            if(grid[j][k] == 1){
                grid[j][k] = 0;
            }
            else{
                grid[j][k] = grid[j - 1][k] + grid[j][k - 1];
            }
        }
    }

    return grid[grid.length-1][grid[0].length-1];
}
```

## Dungeon Game

```java
public static int DungeonGame(int [][] dungeon){
    //the least amount of damage to save the princess
    //HINT:
    //problem can also be solved by considering the least amount of health point to save the princess, which requires for extra space
    int row = dungeon.length;
    int col = dungeon[0].length;
    int MIN = Integer.MIN_VALUE;

    dungeon[row-1][col-1] = dungeon[row-1][col-1] < 0 ? dungeon[row-1][col-1] : 0;

    for(int i = row-1; i>=0; i--){
        for(int j=col-1; j>=0; j--){//iterators here are designed to be in-bound, but it needs to compare with its neighbor
            if(i==row-1 && j==col-1)
                continue;
            //dungeon[i][j] is the total damage at place i,j
            dungeon[i][j] = Math.max(i+1<row?dungeon[i+1][j]:MIN, j+1<col?dungeon[i][j+1]:MIN) +  dungeon[i][j];
            dungeon[i][j] = dungeon[i][j] < 0? dungeon[i][j] : 0 ;
        }
    }
    return -dungeon[0][0]+1;
}
```

## Rod Cutting

```java
public static int cutRod(int[] prices, int n) {
    int[] dp = new int[n + 1]; // dp[i] stores the maximum value for a rod of length i

    for (int i = 1; i <= n; i++) {
        int maxVal = Integer.MIN_VALUE;

        for (int j = 0; j < i; j++) {
            maxVal = Math.max(maxVal, prices[j] + dp[i - j - 1]);
        }

        dp[i] = maxVal;
    }

    return dp[n];
}
```

## Coin Combination

```java
public static int CoinCombination(int target){
    //unlike climbing stairs, 1 1 2 and 2 1 1 are considered to be the same solution
    //assumes that there are three types of coins, 1euro, 2euro, 5euro
    int[] dp = new int[target + 1];
    dp[0] = 1;
    //dp[NUM] -> count of total solution to achieve NUM amount of money
    int [] coins = {1, 2, 5};
    for(int coin : coins){
        for (int i = coin; i <= target; i++){
            dp[i] += dp[i-coin];
        }
    }
    return dp[target];
}
```

## Max SubArray

```java
public static int MaxSubArray(int [] table){
//      vanilla
    for(int i=1; i< table.length; i++){
        table[i] += table[i-1];
    }

    int res = Integer.MIN_VALUE;

    for(int i = 0; i< table.length; i++){
        for (int j = 0; j< i; j++){
            res = Math.max(res, table[i] - table[j]);
        }
    }
    return res;

//      improved
    int currentMax = 0;
    int allTimeMax = 0;
    for (int i = 1; i < table.length; i++){
        currentMax = Math.max(table[i], currentMax+table[i]);
        allTimeMax = Math.max(allTimeMax, currentMax);
    }

    return allTimeMax;
}
```