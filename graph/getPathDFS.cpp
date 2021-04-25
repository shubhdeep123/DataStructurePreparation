#include <iostream>
#include <vector>
using namespace std;

bool getPath(int **graph, int v, int sv, int ev, bool *visited, vector<int> &output) {
    if (sv==ev) {
        output.push_back(sv);
        return true;
    }

     
    visited[sv]=true;

    bool ans =false;

    for(int i=0 ;i<v ;i++){		
        if(!visited[i] && graph[sv][i]==1)
            ans=getPath(graph,v,i,ev,visited,output);
        if( ans== true)
        {
            output.push_back(sv);
            return true;
        }

    }

    return ans;

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

    vector<int> output;
    if(getPath(graph,v,sv,ev,visited,output)) {
        for (auto i : output) {
            cout << i << " ";
        }
    }

    for (int i=0; i<v; i++) {
        delete [] graph[i];
    }
    delete [] graph;
    delete [] visited;

    return 0;
}