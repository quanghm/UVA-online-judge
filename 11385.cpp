/*
 * 11385.cpp
 *
 *  Created on: May 17, 2015
 *      Author: quanghoang
 */
#include<map>
#include<cstdio>

using namespace std;

int main(){
	unsigned int n,f1,f2,f;
	map<int,int> fib;
	char str[100];
	int c;
	int de[46];

	fib[1]=1;fib[2]=2;
	f1=1;f2=2;
	n=2;
	while (1){
		n++;
		f=f1+f2;
		if (f>2147483648){
			break;
		}else{
			fib[f]=n;
			f1=f2;
			f2=f;
			printf("%d %d\n",n,f);
		}
	}
	return 0;
	scanf("%d",&c);
	while (c--){
		memset(de,0,sizeof(de));

		scanf("%d",&f1);
		for (int i=0;i<f1;i++){// read
			scanf("%d",&f);
			de[i]=fib[f];
		}
		fgets(str,100,stdin);
		f2=0;f=sizeof(str)/sizeof(char);
		while (f2<f){
			if (str[f2]>='A'&&str[f2]<='Z'){

			}
		}
	}
}



