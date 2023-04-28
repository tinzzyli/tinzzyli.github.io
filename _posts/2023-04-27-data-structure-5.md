---
layout: post
title:  Data Structure Lecture 5
date:   2023-04-28 08:00:00
description: 
tags: Lecture_Notes 
categories: Data_Structure BinarySearchTree DFS BFS
---

# Binary Search Tree(BST)

For an arbitrary node in a BST, all nodes (if there is any) in its left branch is smaller than itself, vice versa for its right hand side.

For an arbitrary node in a BST, its left child and right child are binary search trees, too.

BST is a data structure of high efficiency, insertion and deletion in BST has a $$O(log n)$$ time complexity.

However, a BST might be constructed imbalancedly, in which cases we introduce AVL tree and red-black tree.

## Build Tree

```java
static class TreeNode {
    int value;
    TreeNode left, right;

    public TreeNode(int value) {
        this.value = value;
        left = right = null;
    }
}

public static class BinaryTree {

    public BinaryTree() {

    }

    public static TreeNode buildTree() {
        TreeNode root = new TreeNode(6);
        root.left = new TreeNode(4);
        root.right = new TreeNode(8);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(7);
        root.right.right = new TreeNode(9);
        root.left.left.left = new TreeNode(1);
        root.left.left.right = new TreeNode(3);
//BST:
//                      6
//                    /   \
//                   4     8
//                  / \   / \
//                 2   5 7   9
//                / \
//               1   3
        return root;
    }
}

```

## Tree Maximum

```java
public static TreeNode treeMaximum(TreeNode root) throws Exception{
    if(root == null){
        throw new IllegalAccessException("Invalid tree: empty");
    }
    while(root.right != null){
        root = root.right;
    }
    return root;
}
```

## Tree Minimum

```java
public static TreeNode treeMinimum(TreeNode root) throws Exception{
    if(root == null){
        throw new IllegalAccessException("Invalid tree: empty");
    }
    while(root.left != null){
        root = root.left;
    }
    return root;
}
```

## isBST

```java
public static boolean isBST(TreeNode root) throws Exception {

    if(root == null){
        return true;
    }

    if(root.left != null && treeMaximum(root.left).value > root.value){
        // all nodes at the LHS of root should be SMALLER than root
        return false;
    }

    if(root.right != null && treeMinimum(root.right).value < root.value){
        // all nodes at the RHS of root should be GREATER than root
        return false;
    }

    else {
        return isBST(root.left) && isBST(root.right);
    }
}
```

## In Order Traversal of BST

```java
public static void inOrderTraversal(TreeNode root){

    if(root.left != null){
        inOrderTraversal(root.left);
    }

    System.out.print(root.value+" ");

    if(root.right != null){
        inOrderTraversal(root.right);
    }

    else {
        return;
    }
}
```

## Recursive and Iterative Search of BST

```java
public static TreeNode recursiveSearch (TreeNode root, int target) throws Exception{
    if(root == null){
        throw new IllegalAccessException("Invalid Tree: empty");
    }
    if(root.value == target){
        return root;
    }
    if(root.left != null && root.value > target){
        return recursiveSearch(root.left, target);
    }
    if(root.right != null && root.value < target){
        return recursiveSearch(root.right, target);
    }
    else {
        //when reaches a leaf node, stop recursion
        throw new Exception("target value not found");
    }
}
```

```java
public static TreeNode iterativeSearch(TreeNode root, int target) throws Exception{
    if(root == null){
        throw new IllegalAccessException("Invalid Tree: empty");
    }
    while(true){
        if(root.value == target){
            return root;
        }
        if(root.left != null && root.value > target){
            root = root.left;
            continue;
        }
        if(root.right != null && root.value < target){
            root = root.right;
            continue;
        }
        else{
            //when reaches a leaf node, stop iteration
            throw new Exception("target value not found");
        }
    }
}
```

## Successor and Predeccessor

```java
public static TreeNode findSuccessor(TreeNode node) throws Exception{
    //   In the context of a binary search tree (BST), the successor of a node
    // is defined as the node with the smallest key greater than the node's key.
    // In other words, it is the next node in the inorder traversal of the BST.

    //  Where is the successor?
    //  The successor must be in(if there is one) the right branch of the given node.
    //  -- In other words, it is the minimum value of the right branch

    if(node == null || node.right == null){
        throw new IllegalAccessException("Invalid Tree: empty or no successor can be found");
    }
    return treeMinimum(node.right);
}
```

```java
public static TreeNode findPredecessor(TreeNode node) throws Exception{
    if(node == null || node.left == null){
        throw new IllegalAccessException("Invalid Tree: empty or no predecessor can be found");
    }
    return treeMaximum(node.left);
}
```

🤔 Hmmm, we repeatedly use *treeMaximum( )* and *treeMinimum( )*, they are really useful!

## Tree Depth

```java
public static int treeDepth(TreeNode root){
    // when only one node, depth == 1
    if(root == null){
        return 0;
    }
    int left_depth = treeDepth(root.left);
    int right_depth = treeDepth(root.right);
    return left_depth > right_depth ? left_depth+1 : right_depth+1;
}
```

🤩 I would say tree depth is my favorite part in BST algorithms... neat.

## Insert and Delete Tree Node

```java
public static TreeNode insertNodeBST(TreeNode root, int key){
    if(root == null){
        // when reach a leaf node, return and new a TreeNode with input key value
        return new TreeNode(key);
    }
    if(root.value > key){
        root.left = insertNodeBST(root.left, key);
    }
    else {
        root.right = insertNodeBST(root.right, key);
    }
    return root;
}
```

😬 It is easy because there is a place for a new node, always!

```java
public static TreeNode deleteNodeBST(TreeNode root, int key) throws Exception {
    // THREE cases could have encountered when deleting a node
    // (1) No left child nor right child
    // (2) Has either left child or right child
    // (3) Has both
    if(root == null){
        return null;
    }

    if(root.value > key){
        root.left = deleteNodeBST(root.left, key);
    }
    else if(root.value < key){
        root.right = deleteNodeBST(root.right, key);
    }
    else {
        if(root.left == null && root.right == null){
            root = null;
        }
        else if(root.left == null){
            root = root.right;
        }
        else if(root.right == null){
            root = root.left;
        }
        else {
            TreeNode successor = findSuccessor(root);
            root.value = successor.value;
            root.right = deleteNodeBST(root.right, successor.value);
        }
    }

    return root;
}
```

🫥 Thoughest part huh? Consider (1), (2) and (3) case by case, not that hard tho.
