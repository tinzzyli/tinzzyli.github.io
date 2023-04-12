---
layout: post
title:  Data Structure Lecture 4
date:   2023-04-11 08:00:00
description: 
tags: Lecture_Notes 
categories: Data_Structure BinaryTree LinkedList
---
- [Stack and Queue](#stack-and-queue)
  - [Stack](#stack)
  - [Queue](#queue)
- [Sentinel-based Circular Linked List](#sentinel-based-circular-linked-list)
- [Binary Tree](#binary-tree)

# Stack and Queue

By using array to implement stack and queue, we have a better understanding towards data structures.

## Stack

To implement a stack using an array in Java, the key points include creating an array, initializing a top pointer to -1, and implementing push(), pop(), and isEmpty() methods. Common mistakes include forgetting to increment/decrement the top pointer, accessing an out-of-bounds index, and not checking for stack overflow/underflow conditions. It's also important to handle exceptions when the stack is empty or full.

Generally, a stack should contain following attributes/functions:

- int: top
- int: maxSize
- int[]: arr
- boolean isFull()
- boolean isEmpty()
- void push()
- int pop()

Noted that:

1. initialize top = -1 when new an instance of stack

```java
//===================================================Stack================================================//
static class Stack{
    //initialize top = -1 when new an instance of stack
    private int top;
    private int maxSize;
    private int[] arr;
    private Stack(int top, int maxSize){
        this.top = top;
        this.maxSize = maxSize;
        arr = new int[maxSize];
    }

    private boolean isFull(){
        return top==maxSize-1? true: false;
    }

    private boolean isEmpty(){
        return top==-1? true: false;
    }

    private void push(int value) throws Exception {
        if(isFull()){
            throw new Exception("push failed: stack is full!");
        }
        else{
            arr[++top] = value;
        }
    };

    private int pop() throws Exception{
        if(isEmpty()){
            throw new Exception("pop failed: stack is empty!");
        }
        else{
            return arr[top--];
        }
    };
}
//===================================================Stack================================================//
```

## Queue

Circular queue using arrays in Java can be implemented using an array and two pointers, front and rear. Key points include initializing the queue, enqueue and dequeue operations, checking for queue full or empty, and implementing circular behavior using modular arithmetic. Common mistakes include not properly updating pointers, incorrectly checking for queue full or empty, and not handling edge cases like when front and rear pointers overlap.

Generally, a queue contains following attributes/functions:

- int: head
- int: tail
- int: maxSize
- int[] : arr

- boolean isFull()
- boolean isEmpty()
- void enqueue()
- int dequeue()

Noted that:

1. EXTREMELY IMPORTANT: initialize head == tail == 0
2. so that when head == tail -> EMPTY
3. head + 1 == tail -> FULL

```java
//===================================================Queue================================================//
static class Queue{
    // head and tail are initialized to be 0
    // enqueue: tail += 1
    // dequeue: head -= 1
    private int head;
    private int tail;

    private int maxSize;
    private int[] arr;

    private Queue(int head, int tail, int maxSize) {
        this.head = head;
        this.tail = tail;
        this.maxSize = maxSize;
        arr = new int[maxSize];
    }

    //TWO key points:
    //1. how to define empty/full queue
    //2. how to deal with index change when: (a) enqueue with tail == maxsize-1 (b) dequeue when head == 0
    private boolean isFull(){
        return (tail+1) % maxSize == head ? true: false;
    }

    private boolean isEmpty(){
        return tail == head? true: false;
    }

    //define:
    //1. when tail+1 == head is full; when tail == head is empty, in this case, the actual maxsize is maxsiez-1 because an vacant space is left out to distinguish FULL & EMPTY
    //2.
    private void enqueue(int value) throws Exception{
        //!!!the actual size of queue is maxSize - 1
        if(isFull()){
            throw new Exception("cannot enqueue: queue is full!");
        }
        else {
            arr[tail] = value;
            tail = (tail + 1) % maxSize;
            //System.out.println(Arrays.toString(arr));
        }
    }

    private int dequeue() throws Exception{
        if(isEmpty()){
            throw new Exception("cannot dequeue: queue is empty!");
        }
        int ret = arr[head];
        arr[head] = -1;
        head = (head + 1) % maxSize;
        //System.out.println(Arrays.toString(arr));
        return ret;
    }
}
//===================================================Queue================================================//
```

# Sentinel-based Circular Linked List

A sentinel-based circular linked list is a linked list data structure that uses a special sentinel node to mark the end of the list. Key points of implementing this include properly initializing the sentinel node, correctly handling insertions and deletions at the beginning and end of the list, and ensuring that the list stays circular by correctly updating the last node's next pointer to point back to the first node.

Common mistakes include forgetting to initialize the sentinel node, incorrectly updating the last node's next pointer, and failing to properly handle insertions and deletions at the beginning and end of the list. Additionally, it's important to ensure that the list is properly freed from memory when it is no longer needed to avoid memory leaks.

Generally, a sentinel circular linked-list is made up with *class ListNode* with attributes/functions:

- int: key
- ListNode: next
- int getKey()

and *class SentinelLinkedList* with attributes/functions:

- ListNode: sentinelNode
- void insertNode()
- void removeNode()

```java
//================================================Linked List============================================//
static class ListNode{
    private int key;
    private ListNode next;

    //why implement a sentinel-based linked list?
    private ListNode(int key){
        this.key = key;
        this.next = null;
    }

    private int getKey(){
        return this.key;
    }

    private void updateKey(int value){
        this.key = value;
    }
}

static class SentinelLinkedList{
    ListNode sentinelNode = new ListNode(-1);
    private int length = 0;
    private SentinelLinkedList(){
        sentinelNode.next = sentinelNode;
    }

    private ListNode findPos(int pos) throws Exception{
        if(pos>length){
            throw new Exception("cannot do insert/remove: index "+pos+" out of range "+length+"!");
        }
        //when i=0, insert right after sentinelNode
        ListNode curNode = sentinelNode;
        for(int i=0; i<pos; i++){
            curNode = curNode.next;
        }
        return curNode;
    }

    private void insert(int key, int pos) throws Exception {
        //insert a node after the pos^{th} node
        ListNode curNode = findPos(pos);
        ListNode newNode = new ListNode(key);
        newNode.next = curNode.next;
        curNode.next = newNode;
//            if(pos == length){
//                newNode.next = sentinelNode;
//            }
        length++;
    }

    private void remove(int pos) throws Exception{
        //remove the node after current node
        ListNode curNode = findPos(pos);
        if(curNode.next != sentinelNode){
            curNode.next = curNode.next.next;
        }
        else {
            throw new Exception("current node "+pos+" is the last node in linked list!");
        }
        length--;

    }

    private int getLength(){
        return length;
    }
}
//================================================Linked List============================================//
```

# Binary Tree

Implementing a binary tree involves defining a node class, setting up pointers between nodes, and implementing operations like insertion, deletion, and traversal. Common mistakes include forgetting to handle null cases, not correctly updating pointers during insertion or deletion, and inefficient traversal algorithms. Recursive solutions can also lead to stack overflow errors if not properly implemented. It's important to thoroughly test the implementation to ensure correct functionality.

Generally, a binary tree contains *class TreeNode* with attributes/functions:

- char: key
- TreeNode: left_child
- TreeNode: right_child
- char getKey()

and *class BinaryTree* with attributes/functions:

- void buildTree()
- void preOrderTraversal()
- void inOrderTraversal()
- void postOrderTraversal()

```java
//================================================Binary Tree============================================//
static class TreeNode {
    private char key;
    private TreeNode l_child;
    private TreeNode r_child;
    private TreeNode(char key){
        this.key = key;
        this.l_child = null;
        this.r_child = null;
    }

    private char getKey(){
        return this.key;
    }
}

static class BinaryTree {
    private BinaryTree(){

    }
    private TreeNode buildTree(){
        TreeNode root = new TreeNode('F');
        root.l_child = new TreeNode('B');
        root.l_child.l_child = new TreeNode('A');
        root.l_child.r_child = new TreeNode('D');
        root.l_child.r_child.l_child = new TreeNode('C');
        root.l_child.r_child.r_child = new TreeNode('E');
        root.r_child = new TreeNode('G');
        root.r_child.r_child = new TreeNode('I');
        root.r_child.r_child.l_child = new TreeNode('H');

        return root;
    }

    private void preOrderTraversal(TreeNode root){
        if(root != null){
            System.out.print(root.getKey()+" ");
            preOrderTraversal(root.l_child);
            preOrderTraversal(root.r_child);
        }
    }

    private void inOrderTraversal(TreeNode root){
        if(root != null){
            inOrderTraversal(root.l_child);
            System.out.print(root.getKey()+" ");
            inOrderTraversal(root.r_child);
        }
    }

    private void postOrderTraversal(TreeNode root){
        if(root != null){
            postOrderTraversal(root.l_child);
            postOrderTraversal(root.r_child);
            System.out.print(root.getKey()+" ");
        }
    }
}
//================================================Binary Tree============================================//
```
