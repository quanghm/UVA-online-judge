#include <iostream>
#include <cmath>
#include <string>
using namespace std;
char reverses[91];

int main(){
	reverses[48]=(char)48; 
	reverses[49]=(char)49; 
	reverses[50]=(char)83;
	reverses[51]=(char)69; 
	reverses[52]=(char)0;
	reverses[53]=(char)90;
	reverses[54]=(char)0;
	reverses[55]=(char)0;
	reverses[56]=(char)56;
	reverses[57]=(char)0;
	reverses[65]=(char)65;	//A
	reverses[66]=(char)0;
	reverses[67]=(char)0;
	reverses[68]=(char)0;
	reverses[69]=(char)51;	//E
	reverses[70]=(char)0;
	reverses[71]=(char)0;
	reverses[72]=(char)72;	//H
	reverses[73]=(char)73;	//I
	reverses[74]=(char)'L';	//J
	reverses[75]=(char)0;	
	reverses[76]=(char)'J';	//L
	reverses[77]=(char)77;	//M
	reverses[78]=(char)0;
	reverses[79]=(char)79;	//O
	reverses[80]=(char)0;
	reverses[81]=(char)0;
	reverses[82]=(char)0;
	reverses[83]=(char)50;	//S
	reverses[84]=(char)84;	//T
	reverses[85]=(char)85;	//U
	reverses[86]=(char)86;	//V
	reverses[87]=(char)87;	//W
	reverses[88]=(char)88;	//X
	reverses[89]=(char)89;	//Y
	reverses[90]=(char)53;	//Z->5

        

	string line;
	int n;
	while (cin>>line){
		n=line.length();
		bool isMirror=true;
		bool isPalin =true;
		
		// check mirrored
		for (int i=0,j=n-1;i<=j;++i,--j){
			if (reverses[line[i]]!=line[j]){
				isMirror = false;
				break;
			}
		}
		
		// check palindrome
		for (int i=0,j=n-1;i<=j;++i,--j){
			if (line[i]!=line[j]){
				isPalin = false;
				break;
			}
		}

		n = 2*isMirror + isPalin;
		switch (n){
			case 0:
				cout<<line<< " -- is not a palindrome.\n\n";
				break;
			case 1:
				cout<<line<< " -- is a regular palindrome.\n\n";
				break;
			case 2: 
				cout<< line<< " -- is a mirrored string.\n\n";
				break;
			case 3:
				cout<< line<< " -- is a mirrored palindrome.\n\n";
				break;
		}
	}

}
