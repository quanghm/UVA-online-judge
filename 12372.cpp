/*
 * =====================================================================================
 *
 *       Filename:  12732.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/03/2016 13:13:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main(){
    int t, n;
    bool isFit;

    cin >> t;

    int i=0;
    while (i<t){
        isFit =true;
        for (int j=0; j<3; ++j){
            cin >> n;
            isFit = isFit && (n<=20);
        }
        cout<<"Case "<< ++i<<": "<<((isFit)?("good\n"):("bad\n"));
    }
}


