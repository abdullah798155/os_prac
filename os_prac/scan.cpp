#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"req seq"<<endl;
    int mr;
    cout<<"mr"<<endl;
    cin>>mr;
    cin>>n;
    int r[n];
    for(int i=0;i<n;i++) cin>>r[i];
    sort(r,r+n);
    int head;
    cout<<"head"<<endl;
    cin>>head;
    int start;
    for(int i=0;i<n;i++){
        if(r[i]>=head){
            start=i;
            break;
        }
    }
    for(int i=start;i<n;i++){
        cout<<"disk moves from "<<head<<" to "<<r[i]<<"seek: "<<r[i]-head<<endl;
        head=r[i];
    }
    for(int i=start-1;i>=0;i--){
        cout<<"disk moves from "<<head<<" to "<<r[i]<<"seek: "<<head-r[i]<<endl;
        head=r[i];
        
    }

}