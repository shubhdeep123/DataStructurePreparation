#include<iostream>
using namespace std;

void DFS(int **graph, int v, bool *visited, int currentVertex) {
    visited[currentVertex] = true;

    for (int i=0; i<v; i++) {
        if (graph[currentVertex][i]==1 && !visited[i]) {
            DFS(graph,v,visited,i);
        }
    }
}

bool isConnected (int **graph, int v) {
    bool *visited = new bool[v]();
    DFS(graph, v, visited, 0);
    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}


int main () {
    int v,e;
    cin >> v >> e;

    int **graph = new int*[v];
    for (int i=0; i<v; i++) {
        graph[i] = new int[v];
        for (int j=0; j<v; j++) {
            graph[i][j] = 0;
        }
    } 

    for (int i=0; i<e; i++) {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }

    bool *visited = new bool[v];
    for (int i=0; i<v; i++) {
        visited[i] = false;
    }

    cout << (isConnected(graph,v) ? "true" : "false") << endl; 

    for (int i=0; i<v; i++) {
        delete [] graph[i];
    }
    delete [] graph;
    delete [] visited;

    return 0;
}