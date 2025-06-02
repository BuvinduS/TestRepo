#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class DSU{
    vector<int> parent, rank;

    public:
        DSU(int n){
            parent.resize(n);
            rank.resize(n);
            for(int i = 0; i < n; i++){
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int find(int i){
            return (parent[i] == i) ? i : (parent[i] = find(parent[i])); 
        }

        void unite(int x, int y){
            int s1 = find(x); int s2 = find(y);
            if(s1 != s2){
                if(rank[s1] < rank[s2]) parent[s1] = s2;
                else if(rank[s1] > rank[s2]) parent[s2] = s1;
                else parent[s2] = s1, rank[s1]++;
            }
        }
};

bool customComparator(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

class Graph{
    private:
        int v;
        vector<Edge> allEdges;      //Kruskals algorithms requires edges not vertices
    
    public:
        Graph(int vertices) : v(vertices){} 
        
        void addEdge(int src, int dest, int weight){
            allEdges.push_back(Edge(src,dest,weight));
        }
        void printMST(const vector<Edge> &mst){
            for(const Edge edge : mst){
                cout << "(" << min(edge.src,edge.dest) << "," << max(edge.src, edge.dest) << ") - Weight: " << edge.weight << endl;
            }
        }

        int getTotalWeight(const vector<Edge> &mst){
            int total = 0;
            for(Edge e : mst){
                total += e.weight;
            }
            return total;
        }

        vector<Edge> kruskalsAlgo(){
            vector<Edge> mst;
            sort(allEdges.begin(), allEdges.end(), customComparator);

            DSU ds(v);

            for(Edge &e : allEdges){
                int u = e.src;
                int v = e.dest;

                if(ds.find(u) != ds.find(v)){
                    ds.unite(u, v);
                    mst.push_back(e);
                }
            }
            return mst;
        }

};

int main(){
    Graph g(6);

    // Add edges to the graph
    g.addEdge(0, 1, 3);
    g.addEdge(0, 5, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 10);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 5, 5);
    g.addEdge(3, 4, 5);
    g.addEdge(4, 5, 4);

    vector<Edge> kruskalsMST = g.kruskalsAlgo();
    g.printMST(kruskalsMST);
    cout << "Total weight of MST is: " << g.getTotalWeight(kruskalsMST) << endl;

    return 0;
}