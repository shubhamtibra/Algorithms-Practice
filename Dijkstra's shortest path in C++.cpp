#include <vector>
#include <list>
#include <utility>
#include <limits>
#include <queue>
#include <iostream>

using namespace std;

typedef pair< int, int > edge;

class Graph{
    
    int N;
    vector< list<edge> > adjlist;
    
    public:
    
    Graph(int N);
    void addEdge(int a, int b, int w);
    vector<int> dijkstra(int source, vector<int> &pi);
  
};

Graph::Graph(int _N): N(_N), adjlist(_N) {}

void Graph::addEdge(int a, int b, int w){
    adjlist[a].push_back(make_pair(b, w));
}

vector<int> Graph::dijkstra(int source, vector<int> &pi){
    
    vector<int> dist(N, numeric_limits<int>::max());
    dist[source] = 0;
    
    priority_queue<edge, vector<edge>, greater<edge> > discovered;
    discovered.push(make_pair(0, source));
    
    while(!discovered.empty()){
        edge E = discovered.top();
        discovered.pop();
        int u = E.second;
        
        for(auto it = adjlist[u].begin(); it != adjlist[u].end(); it++){
            int w = it->second;
            int v = it->first;
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                discovered.push(make_pair(dist[v], v));
                pi[v] = u;
            }
        }
    }
   return dist; 
}

int main(){
    Graph* x = new Graph(7);
    x->addEdge(0, 1, 14);
    x->addEdge(0, 3, 22);
    x->addEdge(0, 4, 4);
    x->addEdge(1, 6, 3);
    x->addEdge(2, 1, 16);
    x->addEdge(2, 3, 12);
    x->addEdge(4, 5, 10);
    x->addEdge(6, 5, 1);
    vector<int> pi(7, -1);
    for(auto e: x->dijkstra(0, pi)){
        cout<<e<<" ";
    }
    cout<<endl;
    for(auto e: pi){
        cout<<e<<" ";
    }
    cout<<endl;
    return 0;
}
