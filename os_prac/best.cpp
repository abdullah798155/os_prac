#include<iostream>
using namespace std;
int main(){
    int np,nb;
    cin>>np>>nb;
    int p[np],b[nb];
    for(int i=0;i<np;i++) cin>>p[i];
    for(int i=0;i<nb;i++) cin>>b[i];

    for(int i=0;i<np;i++){
        int bi=9999;
        int diff=9999;
        for(int j=0;j<nb;j++){
            if(b[j]>=p[i]){
                if(b[j]-p[i]<=diff){
                    bi=j;
                    diff=b[j]-p[i];
                }
            }

        }
        b[bi]-=p[i];
        cout<<"process "<<i+1<<" allocated to "<<bi+1<<endl;
    }
}