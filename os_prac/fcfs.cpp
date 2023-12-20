#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b[n],a[n],p[n],t[n];
    for(int i=0;i<n;i++) {cin>>a[i]; t[i]=a[i];}
    for(int i=0;i<n;i++) {cin>>b[i]; p[i]=i+1;}
    int c[n];
    int time=0,idle=0;
    for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
           }
    }
    for(int i=0;i<n;i++) cout<<p[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++){
        if(time>=a[i]) {
            time+=b[i];
            c[i]=time;
        }
        // else {
        //     idle++;
        //     time+=abs(a[i]-time)+b[i];
        //     c[i]=time;
        //     cout<<"else"<<endl;
        // }

    }
    cout<<"process\tarrival\tburst\tcompletion\tTAT\twaiting"<<endl;
    cout<<"-------\t-------\t-----\t----------\t---\t-------"<<endl;
    for(int i=0;i<n;i++){
        int tat=c[i]-a[i];
        cout<<p[i]<<"\t"<<a[i]<<"\t"<<b[i]<<"\t"<<c[i]<<"\t"<<tat<<"\t"<<tat-b[i]<<endl;
    }
    cout<<"Idle time:"<<idle<<endl;
}