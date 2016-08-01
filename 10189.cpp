
/*
 * uva10189.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quang
 */
#include <iostream>

using namespace std;

int main(){
	int fn=1,m,n;
	char t;

	while ((cin>> m>>n)&&(m)&&(n)){
		if (fn>1){cout<< endl;}
		int f[102][102]={};

		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				cin>> t;
				if(t==42){
					f[i][j]=42;
					for (int k=i-1;k<i+2;k++){
						for (int l=j-1;l<j+2;l++){
							if (f[k][l]!=42){f[k][l]++;}
						}
					}
				}
			}
		}
		// print
		cout<< "Field #"<<fn++<<":"<<endl;
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				if(f[i][j]==42){cout<<"*";}else{cout<<f[i][j];}
			}
			cout<<endl;
		}
	}
}
