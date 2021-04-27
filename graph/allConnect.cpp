#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> singleComponent(int **graph, int startingVertex, int v, bool *visited) {
    vector<int> component;
    queue<int> pendingNodes;
    pendingNodes.push(startingVertex);
    visited[startingVertex] = true;

    while (!pendingNodes.empty()) {
        int current = pendingNodes.front();
        pendingNodes.pop();
        component.push_back(current);
        for (int i=0; i<v; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }

    return component;

}

vector<vector<int>> getAllConnected (int **graph, int v) {
    vector<vector<int>> result;
    bool *visited = new bool[v]();

    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            vector<int> component = singleComponent(graph,i,v,visited);
            result.push_back(component);
        }
    } 

    delete [] visited;
    return result;
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

    vector<vector<int>> connectedComponents = getAllConnected(graph,v);
    for (int i=0; i<connectedComponents.size(); i++) {
        sort(connectedComponents[i].begin(),connectedComponents[i].end());
        for (int j=0; j<connectedComponents[i].size(); j++) {
            cout << connectedComponents[i][j] << " ";
        }
        cout << "\n";
    }


    for (int i=0; i<v; i++) {
        delete [] graph[i];
    }
    delete [] graph;

    return 0;
}