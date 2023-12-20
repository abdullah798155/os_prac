#include<iostream>
using namespace std;
int main(){
    int n,f;
    cin>>n>>f;
    int d[f],b[n],id=0,hc=0;
    for(int i=0;i<f;i++) d[i]=-1;
   for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++){
        if(id>=f) id=0;
        bool hit=false;
        for(int j=0;j<f;j++) if(b[i]==d[j]) {hit=true;hc++;}
        if(!hit){
            d[id++]=b[i];
        }
       for(int k=0;k<f;k++) cout<<d[k]<<" ";
       cout<<endl;


    }
    cout<<"hits:"<<hc<<endl;
    cout<<"faults:"<<n-hc<<endl;
    cout<<"hit ratio:"<<(double)hc/n<<endl;
    
}