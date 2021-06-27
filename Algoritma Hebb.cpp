#include<iostream>
#include<windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    int n[8];
     int x1[8] = {-1,-1,-1,-1,1,1,1,1};
    int x2[8] = {-1,-1,1,1,-1,-1,1,1};
    int x3[8] = {-1,1,-1,1,-1,1,-1,1};
    int t[8] = {-1,-1,-1,-1,-1,-1,-1,1};
    int w=0;
    int w1[8],w2[8],w3[8],wb[8];
    int nw1[8],nw2[8],nw3[8],nwb[8];
    int lw1, lw2, lw3, lwb;
    int b=1;
    int a[8];

    cout<<"\t\t\tModel Hebbian";
    cout<<"\n\n\t\tuntuk penyelesaian gerbang AND\n\n";
    cout<<"[x1]\t[x2]\t[x3]\t[b]\t[t]\n\n";

for(int i=0; i<8; i++){
        cout<<" "<<x1[i]<<"\t "<<x2[i]<<"\t "<<x3[i]<<"\t "<<b<<"\t "<<t[i]<<"\n";
    }

    cout<<"\n\n[x1*t]\t[x2*t]\t[x3*t]\t[b*t]\t[nw1]\t[nw2]\t[nw3]\t[nwb]\n\n";
for(int i=0; i<8; i++){
        w1[i]= t[i]*x1[i];
        w2[i]= t[i]*x2[i];
        w3[i]= t[i]*x3[i];
        wb[i]= t[i]*1;

        nw1[0]=(t[0]*x1[0])+0;
        nw2[0]=(t[0]*x2[0])+0;
        nw3[0]=(t[0]*x3[0])+0;
        nwb[0]=(t[0]*1)+0;

        nw1[i+1]= (t[i+1]*x1[i+1])+nw1[i];
        nw2[i+1]= (t[i+1]*x2[i+1])+nw2[i];
        nw3[i+1]= (t[i+1]*x3[i+1])+nw3[i];
        nwb[i+1]= (t[i+1]*1)+nwb[i];

        lw1=nw1[7];
        lw2=nw2[7];
        lw3=nw3[7];
        lwb=nwb[7];

        cout<<" "<<w1[i]<<"\t "<<w2[i]<<"\t "<<w3[i]<<"\t "<<wb[i]<<"\t "<<nw1[i]<<"\t "<<nw2[i]<<"\t "<<nw3[i]<<"\t "<<nwb[i]<<"\n";
    }

    cout<<"\nbobot baru jaringan hasil training\n";
    cout<<"w1="<<lw1<<"\nw2="<<lw2<<"\nw3="<<lw3<<"\nwb="<<lwb<<"\n";

    cout<<"\nSimulasinya\n";
    cout<<"[w1]\t[w2]\t[w3]\t[net=total(xi*wi)+wb]   [Y]\n\n";
for(int i=0; i<8; i++){
        n[i]= (x1[i]*lw1)+(x2[i]*lw2)+(x3[i]*lw3)+lwb;
        if(n[i]<0){
            a[i]=-1;
        }
else{
            a[i]=1;
        }
        cout<<"   "<<x1[i]<<"\t "<<x2[i]<<"\t "<<x3[i]<<"\t     "<<n[i]<<"                 "<<a[i]<<"\n";
    }

    system("pause");
    return 0;
}
