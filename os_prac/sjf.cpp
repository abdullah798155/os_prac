#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int b[n],a[n],f[n],c[n],p[n],time=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        cin>>b[i];
        p[i]=i+1;
    }
    // int start;
    for(int i=0;i<n;i++) f[i]=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

            }
        }
    }


    cout<<"process\tarrival\tburst\tcompletion\tTAT\twaiting"<<endl;
    cout<<"-------\t-------\t-----\t----------\t---\t-------"<<endl;
   int over=0;
    while(over<n){
        int count =0;
        for(int i=over;i<n;i++){
            if(a[i]<time) count++;
            else break;
        }
        if(count>1){
            for(int i=over;i<over+count-1;i++){
                for(int j=i+1;j<over+count;j++){
                     if(b[i]>b[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

            }
        }

        
    }
}
        // start=time;
        time+=b[over];
        cout<<p[over]<<"\t"<<a[over]<<"\t"<<b[over]<<"\t"<<time<<"\t"<<time-a[over]<<"\t"<<time-a[over]-b[over]<<endl;
        over++;
   
    }

    
  
}