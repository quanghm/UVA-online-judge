// Example program
#include <iostream>
using namespace std;

int main(){
    int i[101]={};
    int v[101]={};
    int x[101]={};
    int l[101]={};
    int c[101]={};
    int u,n;
    for (int n=1;n<101;n++){
        i[n]=i[n-1];
        v[n]=v[n-1];
        x[n]=x[n-1];
        l[n]=l[n-1];
        c[n]=c[n-1];
        u=n%10;
        if (u<4){
            i[n]+=u;
        } else if (u==4){
            i[n]+=1;
            v[n]+=1;
        } else if (u<9){// u>4
            i[n]+=u-5;
            v[n]+=1;
        } else {
            i[n]+=1;
            x[n]+=1;
        }
        u=n/10;
        if (u<4){
            x[n]+=u;
        } else if (u==4){
            x[n]+=1;
            l[n]+=1;
        } else if (u<9){// u>4
            x[n]+=u-5;
            l[n]+=1;
        } else {
            x[n]+=1;
            c[n]+=1;
        }
    }
    while ((cin>>n)&&n){
        cout<< n<<": "<<i[n]<<" i, "<<v[n]<<" v, "<< x[n]<<" x, "<<l[n]<<" l, "<< c[n]<<" c\n";
    }
}