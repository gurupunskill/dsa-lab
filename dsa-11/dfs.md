time
LINKED-LIST L
DFS (G,S):
    for every vertex U in G:
        U.color = WHITE
        U.P = NULL
    time = 0

    for every vertex U in G:
        if U.color = WHITE:
            DFS_VISIT(G,U)

/*
    This is similar to the BFS algorithm.
    Initialize COlor and P to all vertices, including source.
    Then If the Color is WHITE, do something.
*/

DFS_VISIT (G,U):
    time++
    U.d = time
    U.color = GRAY

    for every vertex V in the adjacency list of U, G.adj[U]:
        if V.color = WHITE:
            V.P = U
            DFS_VISIT (G,V)
    
    U.color = BLACK
    time++
    U.f = time
    // Adding modification for topological Sort
    L.push(U)

