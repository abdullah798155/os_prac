#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b[n],a[n],f[n],c[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) f[i]=0;
    int min =a[0];
     for(int j=1;j<n;j++){
            if(a[j]<min){
                min=a[j];
            
            }

        }
    int time=min,k=0;
    cout<<"time "<<time<<endl;
   while(k<15){
        int min =99999;
        int mi;
        for(int j=0;j<n;j++){
            if(b[j]<min && f[j]==0){
                min=b[j];
                mi=j;
            }

        }
        if(time==0) {
            time+=b[0];
            f[0]=1;
        }
        if(time>=a[mi]){
            time+=b[mi];
            cout<<"time "<<time<<endl;
            c[mi]=time;
            f[mi]=1;
        }
        // else{
        //     time+=b[k];
        //     f[k]=1;
        // }
        int brk=0;
        for(int i=0;i<n;i++){
            cout<<"f"<<f[i]<<" ";
            if(f[i]==1) brk++;
        }
        cout<<endl;
        if(brk==n) break;
        // cout<<endl<<"no "<<endl;
        k++;
        }
      

    
    cout<<"process\tarrival\tburst\tcompletion\tTAT\twaiting"<<endl;
    cout<<"-------\t-------\t-----\t----------\t---\t-------"<<endl;
    for(int i=0;i<n;i++){
        int tat=c[i]-a[i];
        cout<<i+1<<"\t"<<a[i]<<"\t"<<b[i]<<"\t"<<c[i]<<"\t"<<tat<<"\t"<<tat-b[i]<<endl;
    }
    // cout<<"Idle time:"<<idle<<endl;
}