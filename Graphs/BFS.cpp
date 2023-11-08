#include<bits/stdc++.h>

using namespace std;
class Solution{
public:
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> ans;
        vector<int> vis(V,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
}

};
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main(){
    vector<int> adj[5];

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,3,1);
    addEdge(adj,0,3);

    Solution obj;
    vector<int> ans= obj.bfsOfGraph(4,adj);
    printAns(ans);
}