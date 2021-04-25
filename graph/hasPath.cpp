#include <iostream>
#include <queue>
using namespace std;


bool hasPath(int **edges, int n, int sv, int ev, bool *visited) {
    if (edges[sv][ev] == 1) return true;

    visited[sv] = true;
    bool res=false;

    for (int i=0; i<n; i++) {
        if (!visited[i] && edges[sv][i]==1) {
            res = hasPath(edges,n,i,ev,visited);
        }
        if (res==true) {
            return true;
        }
    } 

    return res;
}

int main () {
    int n,e;
    cin >> n >> e;

    int **edges = new int*[n];
    for (int i=0; i<n; i++) {
        edges[i] = new int[n];
        for (int j=0; j<n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i=0; i<e; i++) {
        int f,s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }

    int sv, ev;
    cin >> sv >> ev;

    if (hasPath(edges,n,sv,ev,visited)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    for (int i=0; i<n; i++) {
        delete [] edges[i];
    }

    delete [] edges;
    delete [] visited;
}


