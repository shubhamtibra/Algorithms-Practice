// Network Delay Time: Leetcode
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        K--;
        vector<vector<int>> mat(N, vector<int>(N, -1));
        for(auto e: times){
            mat[e[0] - 1][e[1]-1] = e[2];
        }
        
        vector<int> dis(N, INT_MAX);
        dis[K] = 0;
        typedef pair<int, int> mypair;
        priority_queue< mypair, vector <mypair> , greater<mypair> > q;
        q.push(make_pair(0, K));
        while(q.empty() == false){
            mypair temp = q.top();
            int u = temp.second;
            q.pop();
            for(int v = 0; v < N; v++){
                if (mat[u][v] != -1 && dis[v] > dis[u] + mat[u][v]){
                    dis[v] = dis[u] + mat[u][v];
                    q.push(make_pair(dis[v], v));
                }
            }
        }
        for(auto e: dis) cout << e << ", "; 
        int ans = *max_element(dis.begin(), dis.end());
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};
