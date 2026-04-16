/*
You are initially given  a graph with n vertices and m edges
You are given q queries
in which you may be asked two type of queries
given u, v, w, if there exist an edge between u and v, update its weight to w
if does not exist then add and edges between then with weight w
given u, v delete the edge between u, v
You have to find the minimum tree cost after each queries , constraints are tight
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    int id;
    Node *l,*r,*p;
    bool rev;
    ll weight,maxw;
    Node* maxNode;
    int cnt,sumCnt;
    Node(int _id=0):id(_id),l(NULL),r(NULL),p(NULL),rev(0),weight(-4e18),
        maxw(-4e18),maxNode(this),cnt(0),sumCnt(0){}
};

inline bool isRoot(Node* x){return !x->p||(x->p->l!=x&&x->p->r!=x);}
void push_up(Node* x){
    x->maxw=x->weight; x->maxNode=x; x->sumCnt=x->cnt;
    if(x->l){
        if(x->l->maxw>x->maxw){x->maxw=x->l->maxw; x->maxNode=x->l->maxNode;}
        x->sumCnt+=x->l->sumCnt;
    }
    if(x->r){
        if(x->r->maxw>x->maxw){x->maxw=x->r->maxw; x->maxNode=x->r->maxNode;}
        x->sumCnt+=x->r->sumCnt;
    }
}
void push_down(Node* x){
    if(!x||!x->rev)return;
    x->rev=0; swap(x->l,x->r);
    if(x->l)x->l->rev^=1;
    if(x->r)x->r->rev^=1;
}
void pushAll(Node* x){ if(!isRoot(x)) pushAll(x->p); push_down(x); }
void rotate(Node* x){
    Node* p=x->p; Node* g=p->p;
    if(!isRoot(p)){ if(g->l==p) g->l=x; else g->r=x; }
    x->p=g;
    if(p->l==x){
        p->l=x->r; if(x->r)x->r->p=p;
        x->r=p; p->p=x;
    } else {
        p->r=x->l; if(x->l)x->l->p=p;
        x->l=p; p->p=x;
    }
    push_up(p); push_up(x);
}
void splay(Node* x){
    pushAll(x);
    while(!isRoot(x)){
        Node* p=x->p; Node* g=p->p;
        if(!isRoot(p)){
            if((p->l==x)^(g->l==p)) rotate(x);
            else rotate(p);
        }
        rotate(x);
    }
}

Node* access(Node* x){
    Node* last=NULL;
    for(Node* y=x; y; y=y->p){
        splay(y); y->r=last; push_up(y); last=y;
    }
    splay(x);
    return last;
}
void makeRoot(Node* x){ access(x); x->rev^=1; push_down(x); }
Node* findRoot(Node* x){
    access(x);
    while(x->l){ push_down(x); x=x->l; }
    splay(x); return x;
}
bool connected(Node* x,Node* y){ return findRoot(x)==findRoot(y); }
void link(Node* x,Node* y){ makeRoot(x); if(findRoot(y)!=x) x->p=y; }
void cut(Node* x,Node* y){
    makeRoot(x); access(y);
    if(y->l==x && !x->r){ y->l->p=NULL; y->l=NULL; push_up(y); }
}
Node* queryMaxNode(Node* u,Node* v){
    makeRoot(u); access(v); return v->maxNode;
}

inline long long packKey(int a,int b){
    if(a>b) swap(a,b);
    return ((long long)a<<32) | (unsigned long long)b;
}

struct Edge { int u,v; ll w; int id; bool inTree; };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q; cin>>n>>m>>q;
    int maxN=n+m+q+5;
    vector<Node*> nd(maxN,NULL);

    for(int i=1;i<=n;i++){
        nd[i]=new Node(i);
        nd[i]->weight=-4e18;
        nd[i]->cnt=1;
        push_up(nd[i]);
    }

    int curE=n+1;
    auto insertEdge=[&](int u,int v,ll w){
        int id=curE++;
        nd[id]=new Node(id);
        nd[id]->weight=w;
        nd[id]->cnt=0;
        push_up(nd[id]);
        link(nd[u],nd[id]);
        link(nd[id],nd[v]);
        return id;
    };

    vector<array<ll,3>> init(m);
    for(int i=0;i<m;i++) cin>>init[i][0]>>init[i][1]>>init[i][2];
    vector<int> p(n+1);
    iota(p.begin(),p.end(),0);
    function<int(int)> fp=[&](int x){return p[x]==x?x:p[x]=fp(p[x]);};

    vector<array<ll,4>> ke(m);
    for(int i=0;i<m;i++){
        ke[i]={init[i][2],init[i][0],init[i][1],(ll)i};
    }
    sort(ke.begin(),ke.end());

    unordered_map<long long,Edge> edges,nonTree;
    ll mst=0; int cnt=0;

    for(auto &x:ke){
        ll w=x[0],u=x[1],v=x[2];
        if(fp(u)!=fp(v)){
            p[fp(u)]=fp(v);
            int id=insertEdge(u,v,w);
            long long K=packKey(u,v);
            edges[K]={u,v,w,id,true};
            mst+=w; cnt++;
        } else {
            long long K=packKey(u,v);
            edges[K]={u,v,w,-1,false};
            nonTree[K]=edges[K];
        }
    }

    for(int i=0;i<q;i++){
        int t; cin>>t;
        if(t==1){
            int u,v; ll w; cin>>u>>v>>w;
            long long K=packKey(u,v);
            if(edges.count(K)){
                Edge old=edges[K];
                if(old.inTree){
                    Node* e=nd[old.id];
                    cut(nd[old.u],e); cut(e,nd[old.v]);
                    mst-=old.w; cnt--;
                } else nonTree.erase(K);
                edges.erase(K);
            }

            if(!connected(nd[u],nd[v])){
                int id=insertEdge(u,v,w);
                edges[K]={u,v,w,id,true};
                mst+=w; cnt++;
            } else {
                Node* mx=queryMaxNode(nd[u],nd[v]);
                if(mx && mx->weight>w){
                    int oldid=mx->id;
                    long long k2=-1;
                    for(auto &it:edges){
                        if(it.second.inTree && it.second.id==oldid){ k2=it.first; break; }
                    }
                    if(k2!=-1){
                        Edge oe=edges[k2];
                        cut(nd[oe.u],nd[oe.id]);
                        cut(nd[oe.id],nd[oe.v]);
                        mst-=oe.w; cnt--;
                        oe.inTree=false; oe.id=-1;
                        nonTree[k2]=oe; edges[k2]=oe;
                    }
                    int id=insertEdge(u,v,w);
                    edges[K]={u,v,w,id,true};
                    mst+=w; cnt++;
                } else {
                    edges[K]={u,v,w,-1,false};
                    nonTree[K]=edges[K];
                }
            }
        } else {
            int u,v; cin>>u>>v;
            long long K=packKey(u,v);
            if(edges.count(K)){
                Edge e=edges[K];
                if(!e.inTree){
                    nonTree.erase(K);
                    edges.erase(K);
                } else {
                    Node* ed=nd[e.id];
                    cut(nd[e.u],ed); cut(ed,nd[e.v]);
                    mst-=e.w; cnt--;
                    edges.erase(K);

                    long long bk=-1; ll bw=LLONG_MAX; Edge be;
                    for(auto &it:nonTree){
                        auto &ne=it.second;
                        if(!connected(nd[ne.u],nd[ne.v]) && ne.w<bw){
                            bw=ne.w; bk=it.first; be=ne;
                        }
                    }
                    if(bk!=-1){
                        int id=insertEdge(be.u,be.v,be.w);
                        be.inTree=true; be.id=id;
                        edges[bk]=be;
                        nonTree.erase(bk);
                        mst+=be.w; cnt++;
                    }
                }
            }
        }
        if(cnt==n-1) cout<<mst<<"\n";
        else cout<<"-1\n";
    }
    return 0;
}
