#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

//Comparator for priority queue
struct CompareEdge{    //Help to sort the priority queue such that the smallest edge is always up next
    bool operator()(const Edge &e1, const Edge &e2){
        return e1.weight > e2.weight;
    }
};

class Graph{
    private:
        int v;
        vector<vector<pair<int, int>>> adjList; //Adjacency list
    
    public:
        Graph(int vertices) : v(vertices){
            adjList.resize(v);
        } 
        
        void addEdge(int src, int dest, int weight){
            adjList[src].push_back(make_pair(dest,weight));
            adjList[dest].push_back(make_pair(src,weight)); //Due to this being an undirected graph
        }

        vector<Edge> primMST(int startNode){
            priority_queue<Edge, vector<Edge>, CompareEdge> pq; //Priority queue for the edges
            vector<bool> inMST(v, false);
            vector<Edge> mstEdges;

            inMST[startNode] = true;

            for(auto neighbour : adjList[startNode]){
                pq.push(Edge(startNode,neighbour.first,neighbour.second));
            }

            while(!pq.empty()){
                Edge e = pq.top();
                pq.pop();

                int u = e.dest;

                //If dest is already in the MST skip this edge
                if(inMST[u]){
                    continue;
                }

                //Add edge to MST
                mstEdges.push_back(e);
                inMST[u] = true;

                for(auto neighbour : adjList[u]){
                    pq.push(Edge(u,neighbour.first,neighbour.second));
                }
            }
            return mstEdges;
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

    int startNode;
    cout << "Enter start node for Prim's Algorithm: ";
    cin >> startNode;

    vector<Edge> primMst = g.primMST(startNode);
    g.printMST(primMst);
    cout << "Total weight of MST is: " << g.getTotalWeight(primMst) << endl;

    return 0;
}