#include <iostream>
#include<algorithm>
using namespace std;

class Edge {
    public:
    int source;
    int destination;
    int weight;

    Edge() {}
    Edge(int s, int d, int w) {
        source = s;
        destination = d;
        weight = w;
    }
};

bool comp (Edge const &a, Edge const &b) {
    return a.weight < b.weight;
}

int findParent(int *parent, int v) {
    if (parent[v] == v) {
        return v;
    }

    return findParent(parent, parent[v]);
}

void kruskalMST(Edge *input, int v, int e) {
    // sort array in ascending order on bases of weight
    sort(input,input+e,comp);

    int *parent = new int[v];
    for (int i=0; i<v; i++) {
        parent[i] = i;
    }

    Edge *output = new Edge[v-1];
    int count=0;
    int i=0;
    while (count != v-1) {
        Edge currentEdge = input[i];

        int parent_s = findParent(parent,currentEdge.source);
        int parent_d = findParent(parent,currentEdge.destination);

        if (parent_s != parent_d) {
            output[count] = currentEdge;
            count++;

            parent[parent_s] =parent_d;
        }
        i++;
    }

    // print
    for (int i=0; i<v-1; i++) {
        if (output[i].source < output[i].destination) {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        } else {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }

    delete [] output;
    delete [] parent;
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

    Edge *input = new Edge[e];

    for (int i=0; i<e; i++) {
        int s,d,w;
        cin >> s >> d >> w;
        input[i] = Edge(s,d,w);
    }

    kruskalMST(input,v,e);

    delete [] input;


}