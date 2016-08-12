/*
 * =====================================================================================
 *
 *       Filename:  763.cpp
 *
 *    Description:  Fibinary Numbers
 *
 *        Version:  1.0
 *        Created:  08/05/2016 21:17:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define N 102

int flipBit(vector<int> &f, int & strLength,  int bitNum);
bool getString (vector<int> &f, int &length);
void printString( vector<int> &f, int &length);

char buff[N];

int main(){
	bool isLastCase,isFirstCase=true;;                        // detect when last case is read

	while (1){
            vector<int> f1(N,0);
            vector<int> f2(N,0);
            int l1=0,l2=0;
            isLastCase = getString(f1,l1);
            if (isLastCase) {
                break;
            }
            
            if (isLastCase) {
                break;
            }
            
            getString(f2,l2);
            for (int i = l1-1; i>=0 ;--i){
                if (f1[i]) flipBit(f2,l2,i);
            }
            
            if (isFirstCase){
                isFirstCase = false;
            } else {
                cout<<"\n";
            }

            printString(f2,l2);       
            
            getchar();
	}
	
	return 0;
}

void printString(vector<int>&f, int &length){
    for (int i = length-1; i>=0;--i){
        cout<< (int)(f[i]);
    }
    cout<<"\n";
}

bool getString(vector<int>&f, int&length){
	char c;
	int i = 0;

	while ( (c=getchar())!=EOF && c!='\n' ){
		buff[i++]=c;
	}

	// get new length:
	length = i;

	int j = 0;
	
	while (i--){
		f[j++] = buff[i]-'0';
	}

	return (c==EOF);
}

int flipBit(vector<int>&f, int & strLength, int bitNum){
//    printf("bitNum %d, strLength: %d\n",bitNum,strLength);
//    printf("bitNum: %d\n",bitNum);
//    printString(f,strLength);
//    printf("----\n");
//
    // edge case
    if (bitNum >= strLength){
        if (f[bitNum-1]){
            f[bitNum-1]=0;
            f[bitNum+1]=1;
            strLength = bitNum +2;
        } else {
            f[bitNum]=1;
            strLength = bitNum+1;
        }
	return 0;
    }
	
	// recursion:
	if (f[bitNum]){                         // case 01* + *1*
            if (bitNum ==0){	// last position
                f[0]=0; 
                flipBit(f,strLength,1);
                return 0;
            } else if (bitNum==1){
                f[0]=1;f[1]=0;
                flipBit(f,strLength,2);
                return 0;
            }else{	// bitNum > 1
                if (bitNum == strLength-1) strLength++;	// if bitNum is at head
                f[bitNum] = 0;
                flipBit(f, strLength, bitNum + 1);
                flipBit(f, strLength, bitNum - 2);
                return 0;
            }
	} else { // f[bitNum]=0
            if (bitNum == strLength-1){ // case 10 + 0* 
		if (f[strLength-2]){ // case 10 + 01
                    f[strLength - 2]=0;
                    f[strLength++]=1;
                    return 0;
		} else {
                    f[bitNum]=1;
                    return 0;
                }
            } else if (f[bitNum+1]) {
                f[bitNum+1]=0;
                flipBit(f,strLength,bitNum+2);
                return 0;
            } else if (f[bitNum-1]){
                f[bitNum-1] = 0;
                flipBit(f,strLength,bitNum+1);
                return 0;
            }
            else {
                f[bitNum]=1;
                return 0;
            }
        }
	
	return 0;
}
