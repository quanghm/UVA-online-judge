/*
 * 458.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: quang
 */
#include<cstdio>
using namespace std;

int main(){
	char ch;

	while ((ch=getchar())!=EOF){
		if (ch==10){
			putchar(ch);
		}else{
			putchar(ch-7);
		}
	}
}



