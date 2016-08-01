/*
 * 136.cpp
 *
 *  Created on: May 19, 2015
 *      Author: qhoang
 */

#include<stdio.h>
long num1, num2, num3, marker[4], index;
long number[1510]={0,1,2,3,4,5};
int main(){
	index=6; marker[0]=3; marker[1]=3; marker[2]=5;
	while ( index <= 1500 ) {
		num1 = 2 * number[marker[0]];
		num2 = 3 * number[marker[1]];
		if( num2 == num1 ) num2 = 3 * number[++marker[1]];
		num3 = 5 * number[marker[2]];
		if(num3==num1) num3=5*number[++marker[2]];
		if(num3==num2) num3=5*number[++marker[2]];
		if(num2<num1||num3<num1){
			if(num3<num2){
				number[index]=num3;marker[2]++;
			} else {
				number[index]=num2;marker[1]++;
			}
		} else {
			number[index]=num1;marker[0]++;
		}
		index++;
	}
	printf("The 1500'th ugly number is %li.\n",number[1500]);
}
