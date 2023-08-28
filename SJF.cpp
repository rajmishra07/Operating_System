#include <iostream>
#include<bits/stdc++.h>

using namespace std;

struct data1{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

bool cmp(data1 x,data1 y){
    return (x.bt<y.bt);
}
int main(){
    data1 row[20];
    int n;
    float wtavd,tatavg;
    cout<<"Enter the number of process:";
    cin>>n;
    cout<<"Enter arrival time: ";
    for(int i = 0; i < n; i++){
        row[i].pid = i;
         cin>>row[i].at;
    }
     cout<<"Enter burst time: ";
    for(int i = 0; i < n; i++){
        cin>>row[i].bt;
        
    }
    sort(row,row+n,cmp);
    
        row[0].ct = row[0].bt;
        row[0].tat = row[0].ct-row[0].at;
        row[0].wt = row[0].tat-row[0].bt;
        for(int i=0;i<n;i++){
            row[i].ct = row[i-1].ct+row[i].bt;
            row[i].tat = row[i].ct - row[i].at;
            row[i].wt = row[i].tat - row[i].bt;
        }
        
        for(int i = 0;i<n;i++){
            cout<<row[i].ct<<" "<<row[i].pid<<" "<<row[i].at<<" "<<row[i].wt<<" "<<row[i].tat<<endl;
        }
    
}