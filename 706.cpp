/*
 * =====================================================================================
 *
 *       Filename:  706.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/09/2016 17:42:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include <vector>

using namespace std;

int main(){
    int s;
    char c;
    string n;

    while ((cin>>s>>n) && s){
        size_t l = n.length();
        string upper((s+3)*l,32);
        string lower((s+3)*l,32);

        upper.back()='\n';
	lower.back()='\n';
	// draw upper horizontal
        for (int i = 0;;){
            switch (n[i]){
                case '0':
                case '2':
                case '3':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    cout << ' ';
                    for (int j = 0;j<s;++j){
                        cout<<'-';
                    }
                    cout << ' ';
                    break;
                case '1':
                case '4':
                    for (int j = 0; j<s+2; ++j){
                        cout<<' ';
                    }
                    break;
            } 
            if (++i<l){
	        cout<<' ';
	    } else{
		cout<<'\n';
		break;
	    }
	}
//        cout<<"\n";
        // build upper vertical lines
        for (int i=0; i<l; ++i){
            switch (n[i]) {
                case '1':
                case '2':
                case '3':
                case '7':
                    upper[i*(s+3)+s+1]='|';
                    break;
                case '5':
                case '6':
                    upper[i*(s+3)]='|';
                    break;
                case '0':
                case '4':
                case '8':
                case '9':
                    upper[i*(s+3)]='|';
                    upper[i*(s+3)+s+1]='|';
                    break;
            }
        }

        // print s upper vertical line
        for (int i = 0; i<s;++i){
            cout<<upper;
        }

        // print middle horizontal line
        for (int i = 0; ;){
            switch (n[i]) {
                case '0':
                case '1':
                case '7':
                    for (int j = s+2; j; --j){
                        cout<<' ';
                    }
                    break;
                default:
                    cout<<' ';
                    for (int j = s; j; --j){
                        cout<<'-';
                    }
                    cout<<' ';
                    break;
            }
	    if (++i<l){
		    cout<<' ';
	    } else {
		    cout<<'\n';
		    break;
	    }
        }

        // build lower vertical line
        for (int i = 0; i <l; ++i){
            switch(n[i]) {
                case '2':
                    lower[i*(s+3)]='|';
                    break;
                case '0':
                case '6':
                case '8':
                    lower[i*(s+3)]='|';
                case '1':
                case '3':
                case '4':
                case '5':
                case '7':
                case '9':
                    lower[i*(s+3)+s+1]='|';
                    break;
            }
        }
        // print s lower vertical line
        for (int i = s; i; --i){
            cout<<lower;
        }

        // print bottom horizontal line
        for (int i = 0; ;){
            switch (n[i]){
                case '1':
                case '4':
                case '7':
                    for (int j = s+2;j;--j){
                        cout<<' ';
                    }
                    break;
                default: 
                    cout << ' ';
                    for (int j = s; j;--j){
                        cout<< '-';
                    }
                    cout<< ' ';
            }
	    if (++i<l){
		    cout<<' ';
	    } else{
		    cout<<'\n';
		    break;
	    }
        }
        cout<<"\n";
    }
}
