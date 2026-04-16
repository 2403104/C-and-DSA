#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int,int> pii;
int cross(pii O,pii A, pii B){
    //OA x OB (if >0 counterClockwise , if <0 clockwise , =0 colliear)
    return (A.first-O.first)*(B.second-O.second)-(A.second-O.second)*(B.first-O.first);
}
vector<pii> convexHull(vector<pii>&pts){
    int n=pts.size();
    if(n<=3) return pts;
    sort(pts.begin(),pts.end());
    vector<pii> hull(n*2);
    int k=0;
    //lower hull
    for(int i=0;i<n;i++){
        while(k>=2 && cross(hull[k-2],hull[k-1],pts[i])<=0){
            k--;
        }
        hull[k++]=pts[i];
    }
    //upper hull
    for(int i=n-2,t=k+1;i>=0 ;i--){
        if(k>=t && cross(hull[k-2],hull[k-1],pts[i])<=0){
            k--;
        }
        hull[k++]=pts[i];
    }
    hull.resize(k-1);
    return hull;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif

    vector<pair<int, int>> points = {
        {0, 3}, {2, 2}, {1, 1}, {2, 1},
        {3, 0}, {0, 0}, {3, 3}
    };
    vector<pair<int, int>> hull = convexHull(points);
    for(auto p : hull) cout << "(" << p.first << ", " << p.second << ")\n";

    return 0;
}