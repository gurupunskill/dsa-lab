BFS(G,S):  

    for every vertex U in G except S:  
        U.d = infinity  
        U.color = White  
        U.P = NULL  
    
    //Since S has been "discovered"  
    S.color = GRAY  
    S.d = 0  
    S.P = NULL  

    Initialize an empty Queue Q  
    Enqueue(Q,S)  

    while(!isEmpty(Q)):  
        U = Dequeue(Q)  
        for every vertex V in the adjacency list of U, G.adj[U]:  
            if V.color = WHITE:  
                // V has been discovered  
                V.color = GRAY  
                V.d = U.d + 1  
                // Since V is a child of U  
                V.P = U  
                Enqueue(Q, V)
        U.color = BLACKs