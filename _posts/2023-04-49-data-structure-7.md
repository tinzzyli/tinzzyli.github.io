---
layout: post
title:  Data Structure Lecture 7
date:   2023-04-29 18:00:00
description: 
tags: Lecture_Notes 
categories: Data_Structure Graph ShortestPath
---

# Shortest Path on UDG (UnDirected Graph)

The shortest path algorithm is a fundamental concept in graph theory that finds the most efficient route between two nodes in a graph. It has numerous applications, including navigation systems, network routing protocols, and resource allocation problems. The importance of this algorithm lies in its ability to solve optimization problems that involve finding the path with minimum cost or distance. By minimizing the number of steps or distance traveled, the algorithm can save time and resources. The shortest path algorithm is widely used in computer science, operations research, and transportation engineering.

To illustrate our algorithms, we need a weighted UDG:

{% include figure.html path="assets/img/shortestpath.png" class="img-fluid rounded z-depth-1" %}

> powerer by draw.io :)

## Weighted UDG

```java
public static void main(String [] args){

            A    B    C    D    E    F    G
    A   {   0,  12, INF, INF, INF,  16,  14}
    B   {  12,   0,  10, INF, INF,   7, INF}
    C   { INF,  10,   0,   3,   5,   6, INF}
    D   { INF, INF,   3,   0,   4, INF, INF}
    E   { INF, INF,   5,   4,   0,   2,   8}
    F   {  16,   7,   6, INF,   2,   0,   9}
    G   {  14, INF, INF, INF,   8,   9,   0}

    WeightedUDG wUDG = new WeightedUDG(7);
    wUDG.addWeight(0,1,12);
    wUDG.addWeight(1,2,10);
    wUDG.addWeight(2, 3, 3);
    wUDG.addWeight(2, 4, 5);
    wUDG.addWeight(3, 4, 4);
    wUDG.addWeight(0, 5, 16);
    wUDG.addWeight(1, 5, 7);
    wUDG.addWeight(2, 5, 6);
    wUDG.addWeight(4 ,5, 2);
    wUDG.addWeight(0, 6, 14);
    wUDG.addWeight(4, 6, 8);
    wUDG.addWeight(5, 6, 9);

    int [][] graph = wUDG.getWeightedUDG();

    int [] dist = DijkstraAlg(graph, 0);

    System.out.println(Arrays.toString(dist));
}

    public static class WeightedUDG{
    private static int numVert;
    private static int [][] weightedUDG;

    public WeightedUDG(int numVert){
        numVert = numVert;
        weightedUDG = new int[numVert][numVert];
        for (int i=0; i<numVert; i++){
            Arrays.fill(weightedUDG[i], Integer.MAX_VALUE);
        }
        for (int i=0; i<numVert; i++){
            weightedUDG[i][i] = 0;
        }
    }

    public static void addWeight(int vert1, int vert2, int weight){
        //index starts from 0
        //by default, the path to itself is zero
        if(vert1 != vert2){
            weightedUDG[vert1][vert2] = weight;
            weightedUDG[vert2][vert1] = weight;
        }
    }

    public static int[][] getWeightedUDG(){
        return weightedUDG;
    }
}
```

## Vanilla Dijkstra Algorithm

```java

```

## Dijkstra Algorithm with Priority Queue

```java
public static int [] DijkstraAlg(int [][] graph, int start){

    boolean [] visited;
    int [] distance;
    int [] prevVert;

    PriorityQueue<Integer> pq;

    visited = new boolean[graph.length];
    distance = new int[graph.length];
    prevVert = new int[graph.length];

    Arrays.fill(distance, Integer.MAX_VALUE);
    Arrays.fill(visited, false);
    Arrays.fill(prevVert, -1);

    pq = new PriorityQueue<>(graph.length, Comparator.comparingInt(a -> distance[a]));
    pq.offer(start);
    distance[start] = 0;


    while (!pq.isEmpty()){
        int u = pq.poll();
        visited[u] = true;

        //if (v == start){return distance;}

        if (!visited[u]){continue;}

        for (int v=0; v < graph.length; v++){
            if(graph[u][v] < Integer.MAX_VALUE && !visited[v] && distance[v] > distance[u] + graph[u][v] ){
                distance[v] = distance[u] + graph[u][v];
                pq.offer(v);
            }
        }
    }

    return distance;
}
```
