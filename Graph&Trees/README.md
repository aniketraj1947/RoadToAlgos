#   Graph/Trees

## Here are few tips for solving questions which involves Graph/Tree Data Structures

 1.  This is the most dreaded category of competitive programming where beginners struggle to even solve the basic questions. Before looking at the tips, make sure that you're comfortable with the following terms :

    a. Graph - nodes and edges
    b. Path and Cycle
    c. Simple Path
    d. Connectivity and Components of a graph
    e. Tree
    f. Weighted Graphs
    g. Neighbours and Degree - in and out
    h. Regular Graph
    i. Colorings

2.  Let's first look at how you should represent a graph in your code. The most popular and effecient way in most of the cases is the adjacency list.

    `vector<int> adj[N];`

    `adj[2].push_back(4);`

    For a weighted graph, you may use, `vector<pair<int,int>> adj[N]`. Also, you may use 2D array Matrix Representation if `n^2` does not matter in your case. Sometimes, you may need to use `vector<pair<int,int>> edges` and fill edges as `edges.push_back(make_pair(3,4))`.

3.  Now that we're comfortable with atleast the representation of a graph and how you should accept the input. Let's look at how you should traverse a general graph.

4.  **Depth-First Search (DFS) - O(n+m)** : You'd mostly use DFS in most of your graph questions. It begins at a starting node, and proceeds to all other nodes that are reachable from the starting node using the edges of the graph. 

    Implementation : First we'll have `vector<int> adj[N];` and `bool visited[N]`. We'll call `dfs(u)` and it will begin dfs at `u` in the below function.
    <code>

        void dfs(int s) {

            if (visited[s]) return;

            visited[s] = true;

            // process node s

            for (auto u: adj[s]) {

                dfs(u);

            }

        }
    </code>

5.  **Breadth First Search(BFS) - O(n+m)**  : It visits the nodes in increasing order of their distance from the starting node. Thus, we can calculate the distance from the starting node to all other nodes using breadth-first search. However, breadth-first search is more difficult to implement than depth-first search. Here we maintain the following 3 variables :
    <code>
        queue<int> q;

        bool visited[N];

        int distance[N];
    </code>

    New nodes are always added to the end of the queue, and the node at the beginning of the queue is the next node to be processed.

    <code>
        visited[x] = true;

        distance[x] = 0;

        q.push(x);

        while (!q.empty()) {

            int s = q.front(); q.pop();

            // process node s

            for (auto u : adj[s]) {

                if (visited[u]) continue;

                visited[u] = true;

                distance[u] = distance[s]+1;

                q.push(u);

            }

        }

    </code>

6. **Application :** The first basic 3 application that we can solve now is : Connectivity Check, Finding Cycles, Bipartite Check. If you run DFS on a node and you get all nodes visited, that means the graph is connected. Also, you can find number of components? Look at the problems to understand how to find cycles and check bipartiteness on a graph.

7.  **Shortest Path :** To find the shortest path from a node x to all other nodes, we may either use Dijkstra Algorithm with complexity O(n + mlogm) but it won't work with negative edge weights. For negative edge weights, we may use BellmanFord Algorithm but then the complexity would be O(nm). To find shortest distance between all pairs of nodes, we may use Floyd-Warshall Algorithm using dp in O(n^3).

8.  **Tree Algorithms :** The best and general way to traverse a tree is to run a dfs() at a random node and since trees are always connected and acyclic, you'll visit each node of the tree. Look the code below :

    <code>
        void dfs(int s, int e) {

            // process node s

            for (auto u : adj[s]) {

                if (u != e) dfs(u, s);

            }

        }

    </code>

    As you can see, The function is given two parameters: the current node s and the previous node e. The purpose of the parameter e is to make sure that the search only moves to nodes that have not been visited yet. Try to visualize a dry run of the above recursion.

9.  **Application of Tree Traversal :** Let's start with a simple question : Calculate in O(n) time for each node of a rooted tree the number of nodes in its subtree. Check out : CountNodesInSubTree.cpp . It turns out that depth-first search can be used to both check if a directed graph contains a cycle and, if it does not contain a cycle, to construct a topological sort.

10. **Binary Trees :** Full Binary Tree means every node has either 0 or 2 nodes. A complete binary tree has all the levels filled except for the last level and the last level has all its nodes as much as to the left. Perfect Binary Tree means all internal nodes have 2 children and all the leaf nodes are at the same level. 

10. **Important :** Pre and Post numbers are widely used in graph algorithms. For example, they can be used to find out whether a particular node lies in the sub-tree of another node. To find whether u lies in the sub-tree of v or not we just compare the pre and post number of u and v. If pre[u] > pre[v] and post[u] < post[v] then u lies in the sub-tree of v otherwise not. You can see above example for more clarification.

10. **Topological Sort :** A topological sort is an ordering of the nodes of a directed graph such that if there is a path from node a to node b, then node a appears before node b in the ordering.


11. **Important Queries in a Tree :** Now this is the heart of this part. The Tree queries like : *What is the kth ancestor of a node?* OR *What is the sum of the values of nodes in a subtree of a node?* OR *What is the sum of values on a path between two nodes?* OR *What is the **Lowest Common Ancestor (LCA)** of two given nodes?*

11. **Q1. Find the kth ancestor, ancestor(x,k) in O(log k) :** For one node, it'd take O(k) but after preprocessing in O(n log n) time, we can get the query *ancestor(x,k)* in O(log k) time.  
