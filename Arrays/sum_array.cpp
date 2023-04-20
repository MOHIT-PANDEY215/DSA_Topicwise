#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[10]={1,2,3,4,5,1,2,3,4,5};
    int sum=0;
    for(int i=0;i<10;++i){
        sum+=arr[i];
    }
    cout<<"sum of array="<<sum;

    return 0;
}