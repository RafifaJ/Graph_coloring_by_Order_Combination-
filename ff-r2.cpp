//done by rafifa jahir

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> FFColoring() {
        vector<int> colors(V, -1);
        vector<int> order(V);

        for (int i = 0; i < V; ++i) {
            order[i] = i;
        }

        for (int i = 0; i < V; ++i) {
            int u = order[i];
            vector<bool> useColors(V, false);

            for (int v : adj[u]) {
                if (colors[v] != -1) {
                    useColors[colors[v]] = true;
                }
            }

            int colorGiven = 0;
            while (useColors[colorGiven]) {
                colorGiven++;
            }

            colors[u] = colorGiven;
        }

        return colors;
    }


    vector<int> randomOrdering() {
        vector<int> ordering(V);
        for (int i = 0; i < V; ++i) {
            ordering[i] = i;
        }


        srand(static_cast<unsigned>(time(0)));
        random_shuffle(ordering.begin(), ordering.end());

        return ordering;
    }
};

int main() {
    int V = 20;
    Graph g(V);
    g.addEdge(0, 2);
    g.addEdge(0, 5);
    g.addEdge(0, 13);
    g.addEdge(1, 3);
    g.addEdge(1, 14);
    g.addEdge(2, 18);
    g.addEdge(2, 10);
    g.addEdge(2, 19);
    g.addEdge(3, 14);
    g.addEdge(3, 8);
    g.addEdge(4, 17);
    g.addEdge(4, 16);
    g.addEdge(4, 18);
    g.addEdge(5, 14);
    g.addEdge(5, 17);
    g.addEdge(6, 15);
    g.addEdge(6, 13);
    g.addEdge(7, 15);
    g.addEdge(8, 19);
    g.addEdge(9, 1);
    g.addEdge(10, 7);
    g.addEdge(10, 5);
    g.addEdge(10, 4);
    g.addEdge(11, 6);
    g.addEdge(11, 2);
    g.addEdge(12, 9);
    g.addEdge(12, 0);
    g.addEdge(13, 11);
    g.addEdge(14, 10);
    g.addEdge(15, 5);
    g.addEdge(16, 2);
    g.addEdge(16, 0);
    g.addEdge(17,11);
    g.addEdge(18,13);
    g.addEdge(18,8);
    g.addEdge(19,2);
    g.addEdge(19, 9);



    vector<int> randomOrder = g.randomOrdering();
    vector<int> FFColors = g.FFColoring();

    cout << "Random Heuristic Ordering vertices : ";
    for (int vertex : randomOrder) {
        cout << vertex << " ";
    }
    cout << endl;

    cout << "The Combination of First Fit and Random Heuristic Ordering Vertices are :\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << randomOrder[i] << ": Color " << FFColors[randomOrder[i]] << "\n";
    }

    return 0;
}
