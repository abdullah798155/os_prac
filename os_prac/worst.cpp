#include<iostream>
using namespace std;
int main(){
    int np,nb;
    cin>>np>>nb;
    int p[np],b[nb],f[nb];
    for(int i=0;i<np;i++) cin>>p[i];
    for(int i=0;i<nb;i++) cin>>b[i];
    for(int i=0;i<nb;i++) f[i]=0;
    

    for(int i=0;i<np;i++){
        int bi=9999;
        int diff=0;
        for(int j=0;j<nb;j++){
            if(b[j]>=p[i] && f[j]==0){
                if(b[j]-p[i]>=diff){
                    bi=j;
                    diff=b[j]-p[i];
                }
            }

        }
        if(bi==9999) cout<<"COuld not allocate block"<<i+1<<endl;
        else {
            cout<<"process "<<i+1<<" allocated to "<<bi+1<<endl;
            b[bi]-=p[i];
            f[bi]=1;
        }
    }
}