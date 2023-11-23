//done by rafifa jahir

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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


    vector<int> FFColoring(const vector<int>& ordering) {
        vector<int> colors(V, -1);
        set<int> availableColors;

        for (int u : ordering) {
            availableColors.clear();
            for (int v : adj[u]) {
                if (colors[v] != -1) {
                    availableColors.insert(colors[v]);
                }
            }

            int colorGiven = 0;
            while (availableColors.find(colorGiven) != availableColors.end()) {
                ++colorGiven;
            }

            colors[u] = colorGiven;
        }

        return colors;
    }


    vector<int> saturationDegreeOrdering() {
        vector<int> ordering(V);
        vector<int> saturation(V, 0);

        for (int u = 0; u < V; ++u) {
            ordering[u] = u;
            for (int v : adj[u]) {
                if (saturation[u] > saturation[v] || (saturation[u] == saturation[v] && u > v)) {
                    ++saturation[u];
                }
            }
        }

        sort(ordering.begin(), ordering.end(), [this, &saturation](int u, int v) {
            return saturation[u] > saturation[v];
        });

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


    vector<int> saturationDegreeOrder = g.saturationDegreeOrdering();
    vector<int> FFColors = g.FFColoring(saturationDegreeOrder);

    cout << "Saturation Degree Ordering: ";
    for (int vertex : saturationDegreeOrder) {
        cout << vertex << " ";
    }
    cout << endl;

    cout << "The combination of First Fit and Saturation Degree Heuristic Order Coloring of the vertices:\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << saturationDegreeOrder[i] << ": Color " << FFColors[saturationDegreeOrder[i]] << "\n";
    }

    return 0;
}
