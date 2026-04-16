#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define p push
#define F first
#define S second
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
vvi graph;
int n,currPos;
vi parent, depth, size, heavy;
vi head, pos, linTree;
vi segTree,values;
void dfs(int node){
    int maxSize=0;
    for(auto neb : graph[node]){
        if(neb==parent[node]) continue;
        parent[neb]=node;
        depth[neb]=depth[node]+1;
        dfs(neb);
        size[node]+=size[neb];
        if(size[neb]>maxSize){
            heavy[node]=neb;
            maxSize=size[neb];
        }
    }
}

void dfsHLD(int node, int chain){
    head[node]=chain;
    pos[node]=currPos++;
    linTree[pos[node]]=values[node];
    if(heavy[node]!=-1) dfsHLD(heavy[node],chain);
    for(auto neb : graph[node]){
        if(neb==parent[node] || neb==heavy[node]) continue;
        dfsHLD(neb,neb);

    }
}
//PATH QUERY USING SEGMENT TREE
void build(int idx, int low, int high){
    if(low==high){
        segTree[idx]=linTree[low];
        return;
    }
    int  mid=(low+high)/2;
    build(idx*2+1,low,mid);
    build(idx*2+2,mid+1,high);
    segTree[idx]=segTree[idx*2+2]+segTree[idx*2+1];
}
int segTreeQuery(int idx,int l, int r, int qL, int qR){
    if(l>qR || r<qL) return 0;
    if(l>=qL && r<=qR) return segTree[idx];
    int mid=(l+r)/2;
    return segTreeQuery(idx*2+1,l,mid,qL,qR)+segTreeQuery(idx*2+2,mid+1,r,qL,qR);
}
void segTreeUpdate(int idx,int l, int r, int pos,int val){
    if(l==r){
        segTree[idx]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) segTreeUpdate(idx*2+1,l,mid,pos,val);
    else segTreeUpdate(idx*2+2,mid+1,r,pos,val);
    segTree[idx]=segTree[idx*2+2]+segTree[idx*2+1];
}
int queryPath(int u, int v){
    int res=0;
    while(head[u]!=head[v]){
        if(depth[head[u]]<depth[head[v]]) swap(u,v);
        res+=segTreeQuery(0,0,n-1,pos[head[u]],pos[u]);
        u=parent[head[u]];
    }
    if(depth[u]>depth[v]) swap(u,v);
    res+=segTreeQuery(0,0,n-1,pos[u],pos[v]);
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif

    int m;
    cin>>n>>m;
    graph.resize(n + 1);
    size.assign(n + 1, 1);
    heavy.assign(n + 1, -1);
    parent.assign(n + 1, -1);
    depth.assign(n + 1, 0);
    head.assign(n + 1, 0);
    pos.assign(n + 1, 0);
    linTree.assign(n, 0);
    values.assign(n + 1, 0);
    for(int i=1;i<=n;i++) cin>>values[i];
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    parent[1]=-1;
    depth[1]=0;
    dfs(1);
    currPos=0;
    dfsHLD(1,1);
    segTree.resize(n*4,0);
    build(0,0,n-1);//idx,low,high
    int u,v;
    cin>>u>>v;
    cout<<queryPath(u,v);

    return 0;
}
/*PATHS GIVEN WITH EDGEWEIGHTS*/
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define p push
#define F first
#define S second
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
class Solution {
public:
    vvi graph;
    int n, currPos;
    vi parent, depth,size, heavy,head, pos, linTree,segTree,values;
    void dfs(int node){
        int maxSize=0;
        for(int neb : graph[node]){
            if(neb==parent[node]) continue;
            parent[neb]=node;
            depth[neb]=depth[node]+1;
            dfs(neb);
            size[node]+=size[neb];
            if(size[node]>maxSize){
                maxSize=size[node];
                heavy[node]=neb;
            }
        }
    }
    void dfsHLD(int node, int chain){
        head[node]=chain;
        pos[node]=currPos++;
        linTree[pos[node]]=values[node];
        if(heavy[node]!=-1) dfsHLD(heavy[node],chain);
        for(int neb : graph[node]){
            if(neb==parent[node] || neb==heavy[node]) continue;
            dfsHLD(neb,neb);
        }
    }
    void build(int idx, int left, int right){
        if(left==right){
            segTree[idx]=linTree[left];
            return;
        }
        int mid=(left+right)/2;
        build(idx*2+1,left,mid);
        build(idx*2+2,mid+1,right);
        segTree[idx]=segTree[idx*2+1]+segTree[idx*2+2];
    }
    int segTreeQuery(int idx,int l, int r, int qL, int qR){
        if(l>qR || r<qL) return 0;
        if(l>=qL && r<=qR) return segTree[idx];
        int mid=(l+r)/2;
        return segTreeQuery(idx*2+1,l,mid,qL,qR)+segTreeQuery(idx*2+2,mid+1,r,qL,qR);
    }
    void segTreeUpdate(int idx,int l, int r, int pos,int val){
        if(l==r){
            segTree[idx]=val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) segTreeUpdate(idx*2+1,l,mid,pos,val);
        else segTreeUpdate(idx*2+2,mid+1,r,pos,val);
        segTree[idx]=segTree[idx*2+2]+segTree[idx*2+1];
    }
    int queryPath(int u, int v){
        int res=0;
        while(head[u]!=head[v]){
            if(depth[head[u]]<depth[head[v]]) swap(u,v);
            res+=segTreeQuery(0,0,n-1,pos[head[u]],pos[u]);
            u=parent[head[u]];
        }
        if(depth[u]>depth[v]) swap(u,v);
        res+=segTreeQuery(0,0,n-1,pos[u],pos[v]);
        return res;
    }
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        graph.resize(n+1);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        this->n=n;
        currPos=0;
        parent.resize(n+1,-1);
        depth.resize(n+1,0);
        size.resize(n+1,1);
        heavy.resize(n+1,-1);
        head.resize(n+1,0);
        pos.resize(n+1,0);
        linTree.resize(n+1,0);
        segTree.resize(n*4,0);
        values.resize(n+1,0);
        depth[1]=0;
        parent[1]=-1;
        dfs(1);
        for(auto &it : edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(parent[u]==v) {
                values[u]=w;
            }else{
                values[v]=w;
            }
        }
        dfsHLD(1,1);
        build(0,0,n-1);
        vector<int>ans;
        for(auto &it : queries){
            if(it[0]==1){
                int u = it[1], v = it[2], w = it[3];
                if (parent[u] == v) swap(u, v);
                segTreeUpdate(0, 0, n - 1, pos[v], w);
            }else{
                ans.push_back(queryPath(1,it[1]));
            }
        }
        return ans;
    }
};