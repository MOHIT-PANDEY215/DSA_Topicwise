#include<bits/stdc++.h>

using namespace std;

class SegmentTree {
    vector<int> seg;
    public:
    SegmentTree(int n){
        seg.resize(4*n+1);
    }

    void formSegmentTreeForMinVal(vector<int> elems,int low,int high,int index){
    if(low==high){
        seg[index]=elems[low];
        return;
    }
    int mid=(low+high)/2;
    formSegmentTreeForMinVal(elems,low,mid,(2*index)+1);
    formSegmentTreeForMinVal(elems,mid+1,high,(2*index)+2);
    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}

void formSegmentTreeForSum(vector<int> elems,int low,int high,int index){
    if(low==high){
        seg[index]=elems[low];
        return;
    }
    int mid=(low+high)/2;
    formSegmentTreeForSum(elems,low,mid,(2*index)+1);
    formSegmentTreeForSum(elems,mid+1,high,(2*index)+2);
    seg[index]=(seg[2*index+1]+seg[2*index+2]);

}

void pointUpdateInSegmentTreeForMinVal(int low,int high,int index,int val,int i){
 if(low==high){
    seg[index]=val;
    return;
 }
 int mid=(low+high)/2;
 if(i<=mid){
    pointUpdateInSegmentTreeForMinVal(low,mid,2*index+1,val,i);
 }
 else{
    pointUpdateInSegmentTreeForMinVal(mid+1,high,2*index+2,val,i);
 }
 seg[index]=min(seg[2*index+1],seg[2*index+2]);
}

int queryForMinVal(int low,int high,int l,int r,int index){
    // No overlap r<low || high<l
    if(low>r || high<l){
        return INT_MAX;
    }

    // Complete overlap
    if(l<=low && high<=r){
        return seg[index];
    }

    // Partial Overlap
    int mid=(low+high)/2;
    int left=queryForMinVal(low,mid,l,r,2*index+1);
    int right=queryForMinVal(mid+1,high,l,r,2*index+2);
    
    return min(left,right);

}

void queryForSum(){

}

vector<int> getSegmentTree() {
        return seg;
    }

};

int main(){

    int n;
    cin>>n;
    vector<int> elems;
    // vector<int> segMinVal(4*n),segSum(4*n);
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        elems.push_back(a);
    }

    // Form the segment tree containing min value for a range using the inputs given.
    SegmentTree segMinVal(n);
    SegmentTree segSumTree(n);
    
    segMinVal.formSegmentTreeForMinVal(elems,0,n-1,0);
    segSumTree.formSegmentTreeForSum(elems,0,n-1,0);



    // Display all elements in segment tree
    vector<int> segSum = segSumTree.getSegmentTree();
    for(auto x:segSum){
        cout<<x<<" ";
    }

    // Here we have stored all the values in a list(vector). This problem requires us to find the minimum value in the given range.

    // int q; // Number of queries
    // cin>>q;

    // while (q--)
    // {
    //     int l,r;   // Range of query [l to r]
    //     cin>>l>>r;

    // }
    
    
    return 0;
}