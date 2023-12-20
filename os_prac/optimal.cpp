#include<iostream>
using namespace std;
int main(){
    int n,f;
    cin>>n>>f;
    int d[f],b[n],id=0,hc=0;
    for(int i=0;i<f;i++) d[i]=-1;
   for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++){
        bool hit=false;
        for(int j=0;j<f;j++) if(b[i]==d[j]) {hit=true;hc++;}
        if(!hit){
            int li=-1;
            int com=i;
            if(id>=f){
            for(int k=0;k<f;k++){
    
                    int s=i;
                    while(s<=n){
                        if(d[k]==b[s]){
                            
                            if(s>com) {
                                com=s;
                               
                                li=k;
                                break;
                            }
                            else break;
                            

                        }
                        s++;
                    }
                
                    if(s-1==n) {
                        li=k;
                        break;
                    }
                    
                
            }
            }
            if(li==-1) d[id++]=b[i];
            else {
             
                d[li]=b[i];
            }
        }
       for(int k=0;k<f;k++) cout<<d[k]<<" ";
       cout<<endl;


    }
    cout<<"hits:"<<hc<<endl;
    cout<<"faults:"<<n-hc<<endl;
    cout<<"hit ratio:"<<(double)hc/n<<endl;
    
}