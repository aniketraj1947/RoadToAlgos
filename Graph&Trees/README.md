#   Arrays

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

4.  Depth-First Search (DFS) - O(n+m) : You'd mostly use DFS in most of your graph questions. It begins at a starting node, and proceeds to all other nodes that are reachable from the starting node using the edges of the graph. 

    Implementation : First we'll have `vector<int> adj[N];` and `bool visited[N]`. We'll call `dfs(u)` and it will begin dfs at `u` in the below function.

    `void dfs(int s) {` <br/>
        `if (visited[s]) return;` <br/>
        `visited[s] = true;`<br/>
        `// process node s`<br/>
        `for (auto u: adj[s]) {`<br/>
            `dfs(u);`<br/>
        `}`<br/>
    `}`<br/>

5.  Breadth First Search :

