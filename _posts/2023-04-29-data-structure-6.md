---
layout: post
title:  Data Structure Lecture 6
date:   2023-04-29 08:00:00
description: 
tags: Lecture_Notes 
categories: Data_Structure DFS BFS Graph
---

- [Graph](#graph)
  - [Construction: Adjacency List \& Adjacency Matrix](#construction-adjacency-list--adjacency-matrix)
  - [BFS: Breadth First Search](#bfs-breadth-first-search)
  - [DFS: Depth First Search](#dfs-depth-first-search)


# Graph

Generally, graphs can be catergorized as *undirected graph* and *directed graph*, in this chapter, we use unweighted undirected graph to illustrate most cases. :)

## Construction: Adjacency List & Adjacency Matrix

```java
public static class IndirectGraph{
        private static int numVertex;
        private static ArrayList<Integer>[] adjList;
        private static boolean[][] adjMatrix;

        public IndirectGraph(int numVertex) {
            this.numVertex = numVertex;

            adjMatrix = new boolean[numVertex][numVertex];

            adjList = new ArrayList[numVertex];

            for (int i=0; i<numVertex; i++){
                adjList[i] = new ArrayList<>();
            }
        }

        public static void addEdge(char c1, char c2){
            int v1 = c1 - 'A';
            int v2 = c2 - 'A';
            adjList[v1].add(v2);
            adjList[v2].add(v1);
            adjMatrix[v1][v2] = true;
            adjMatrix[v2][v1] = true;
        }

        public static void printAdjList(){
            System.out.println("Indirect Graph Adjacency List: ");
            for (int i=0; i<numVertex; i++){
                System.out.print("\n"+(char) ('A' + i)+": ");
                for (int j=0; j<adjList[i].size(); j++){
                    System.out.print((char) ('A'+adjList[i].get(j))+" ");
                }
            }
        }

        public static void printAdjMatrix(){
            System.out.println("\nIndirect Graph Adjacency Matrix: ");
            for (int i=0; i<numVertex; i++){
                System.out.print("\n"+(char) ('A' + i) + ": ");
                for (int j=0; j<numVertex; j++){
                    System.out.print(adjMatrix[i][j]? "1  " : "0  ");
                }
            }
        }
}
```

This is the graph we use:

{% include figure.html path="assets/img/graph.png" class="img-fluid rounded z-depth-1" %}

> power by draw.io :)

construction code:

```java
public static void main(String [] args){
    IndirectGraph indirectGraph = new IndirectGraph(7);
    [E]--------[B]--------[F]--------[C]
    |          |          |
    |          |          |
    |          |          |
    [G]--------[A]--------[D]
    indirectGraph.addEdge('A', 'B');
    indirectGraph.addEdge('A', 'D');
    indirectGraph.addEdge('A', 'G');
    indirectGraph.addEdge('B', 'E');
    indirectGraph.addEdge('B', 'F');
    indirectGraph.addEdge('C', 'F');
    indirectGraph.addEdge('D', 'F');
    indirectGraph.addEdge('E', 'G');
    indirectGraph.printAdjList();
    indirectGraph.printAdjMatrix();
}
```

## BFS: Breadth First Search

```java
public static void BFS(IndirectGraph graph, char start){
    //initialized to be false
    boolean [] visited = new boolean[graph.numVertex];
    //FIFO
    Queue<Integer> queue = new LinkedList<>();

    //add the next vertex(-ices) to visit in queue, in this case, 'A'
    visited[start - 'A'] = true;
    queue.add((int)start);

    while (!queue.isEmpty()){
        //(iteratively) read element(s) from the queue
        int vert = queue.poll();
        System.out.print( (char)vert + " ");

        //use adjacency list
        for (int i=0; i<graph.adjList[vert - 'A'].size(); i++){
            //[vert - 'A'] is the label of each adjList
            int num = graph.adjList[vert - 'A'].get(i);
            //if it is not visited, add to queue
            if(!visited[num]){
                visited[num] = true;
                queue.add(num+'A');
            }
        }
    }
}
```

🤔  This block of code could be beutify. In *adjList<>* and *queue<>*, values of the some vertex is different.

## DFS: Depth First Search

Implementation with Recursion

```java
public static void RecursiveUtilDFS(IndirectGraph graph, char start, boolean[] visited){
    visited[start - 'A'] = true;
    System.out.print(start + " ");

    Iterator<Integer>  i = graph.adjList[start - 'A'].listIterator();
    while(i.hasNext()){
        int n = i.next();
        if (!visited[n]) {
            RecursiveUtilDFS(graph, (char) (n + 'A'), visited);
        }
    }
}

public static void RecursiveDFS(IndirectGraph graph, char start){
    boolean [] visited = new boolean[graph.numVertex];
    RecursiveUtilDFS(graph, start, visited);
}
```

Implementation with Iteration

```java
public static void DFS(IndirectGraph graph, char start){
    boolean [] visited = new boolean[graph.numVertex];

    Stack<Integer> stack = new Stack<>();
    stack.push((int)start);

    while(!stack.isEmpty()){
        int vert = stack.pop();

        if(!visited[vert-'A']){
            visited[vert-'A'] = true;
            System.out.print((char) vert + " ");

            for (int i=0; i<graph.adjList[vert-'A'].size(); i++){
                int neighbor = graph.adjList[vert-'A'].get(i);
                if(!visited[neighbor]){
                    stack.push(neighbor+'A');
                }
            }
        }
    }
}
```