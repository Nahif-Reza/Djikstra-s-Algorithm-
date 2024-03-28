//This is my implementation of Djikstra's Algorithm.
//To represent the Graph I have used an Adjacency List. 
//I have used priority queue (Min Heap) to efficiently find the node with the shortest distance.

#include<bits/stdc++.h>
using namespace std;
 
#define nl '\n'
const int INF = 1000000000;

class Graph
{
    public:
        int vertices;
        Graph(int vertices)
        {
            this->vertices = vertices;
        }
        void add_edge(vector<pair<int, int>>adj[], int u, int v, int w)
        {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); //If it is a directed graph delete this line.
        }

        void djikstra(vector<pair<int, int>> adj[], int root)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
            vector<int>dist(vertices+1, INF);
 
            dist[root] = 0;
            pq.push({0, root}); // distance, vertex
 
            while(!pq.empty())
            {
                int curr_node = pq.top().second;
                pq.pop();
 
                for(auto node : adj[curr_node])
                {
                    if(dist[node.first] > dist[curr_node] + node.second)
                    {
                        dist[node.first] = dist[curr_node] + node.second;
                        pq.push({dist[node.first], node.first});
                    }
                }
            }
 
            for(int i = 0;i < dist.size();i++)
            {
                if(dist[i] != INF)
                {
                    cout << i << "  " << dist[i] << nl;
                }
                else
                {
                    cout << i << "  " << -1 << nl;
                }
            }
        }
};
 
int main()
{
    int n, m, root;
    cout << "How many vertices/nodes? ";
    cin >> n;
    cout << "How many edges? ";
    cin >> m;
    cout << "Which node is the root node? ";
    cin >> root;
    vector<pair<int, int>> adj_list[n+1];
    Graph graph(n);
    for(int i = 0;i < m;++i)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        graph.add_edge(adj_list, x, y, wt);
    }
    graph.djikstra(adj_list, root);
    return 0;
}
