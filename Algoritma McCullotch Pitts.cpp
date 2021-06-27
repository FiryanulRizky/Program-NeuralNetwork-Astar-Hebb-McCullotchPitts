#include<iostream>
#include <windows.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n[4],a[4];
    int x1[4] = {0, 0, 1, 1};
    int x2[4] = {0, 1, 0, 1};
    int target[4] = {0, 0, 0, 1};
    int target2[4] = {0, 1, 1, 1};
    int target3[4] = {0, 1, 1, 0};
    int w=1;

    cout<<"JST-Model Neuron McCulloch-Pitts";

    cout<<"\n\n#gerbang AND\n\n";
    cout<<"[x1]\t[x2]\t[N]\t[target]\t[Y]\n\n";
for(int i=0; i<4; i++){
        n[i]= w*x1[i]+w*x2[i];
        if(n[i]<2){
            a[i]=0;
        }
else{
            a[i]=1;
        }
        cout<<" "<<x1[i]<<"\t "<<x2[i]<<"\t "<<n[i]<<"\t   "<<target[i]<<"\t\t "<<a[i]<<"\n";
    }

    cout<<"\n\n#gerbang OR\n\n";
    cout<<"[x1]\t[x2]\t[N]\t[target]\t[Y]\n\n";
for(int i=0; i<4; i++){
        n[i]= w*x1[i]+w*x2[i];
        if(n[i]<1){
            a[i]=0;
        }
else{
            a[i]=1;
        }
        cout<<" "<<x1[i]<<"\t "<<x2[i]<<"\t "<<n[i]<<"\t   "<<target2[i]<<"\t\t "<<a[i]<<"\n";
    }

    cout<<"\n\n#gerbang XOR\n\n";
    int w0[2]={-1, 2};
    int z1[4],z2[4],a1[4],n1[4],n2[4];
    cout<<"[x1]\t[x2]\t[z1]\t[z2]\t[N]\t[target]\t[Y]\n\n";

for(int i=0; i<4; i++){
        n1[i]= w0[1]*x1[i]+w0[0]*x2[i];
        if(n1[i]<2){
            z1[i]=0;
        }
else{
            z1[i]=1;
        }

        n2[i]= w0[0]*x1[i]+w0[1]*x2[i];
        if(n2[i]<2){
            z2[i]=0;
        }
else{
            z2[i]=1;
        }
        n[i]= w*z1[i]+w*z2[i];
        if(n[i]<1){
            a1[i]=0;
        }
else{
            a1[i]=1;
        }
        cout<<" "<<x1[i]<<"\t "<<x2[i]<<"\t"<<z1[i]<<"\t"<<z2[i]<<"\t  "<<n[i]<<"\t    "<<target3[i]<<"\t\t "<<a1[i]<<"\n";
    }
    system("pause");
    return 0;
}
