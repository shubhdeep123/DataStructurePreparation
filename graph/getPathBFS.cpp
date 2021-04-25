#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> *getPath(int **graph, int v, int sv, int ev, bool *visited) {
    queue<int> pendingVertices;
    unordered_map<int,int> vertexMap;
    pendingVertices.push(sv);
    visited[sv] = true;

    while(!pendingVertices.empty()) {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        for (int i=0; i<v; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
                vertexMap[i] = currentVertex;

                if (i==ev) {
                    vector<int> *output = new vector<int>();
                    output->push_back(ev);
                    int x = ev;
                    while (vertexMap[x] != sv) {
                        output->push_back(vertexMap[x]);
                        x = vertexMap[x];
                    }
                    output->push_back(sv);
                    return output;
                }
            }
        }
    }

    return NULL;
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

    int sv,ev;
    cin >> sv >> ev;

    vector<int> *output = getPath(graph,v,sv,ev,visited);

    if (output) {
        for (int i=0; i<output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete output;

    for (int i=0; i<v; i++) {
        delete [] graph[i];
    }
    delete [] graph;
    delete [] visited;

    return 0;
}