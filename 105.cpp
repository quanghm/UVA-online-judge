/*
 * =====================================================================================
 *
 *       Filename:  105.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/05/2016 12:59:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int l,h,r, s=0,e=0;
    vector<int> f(10002,0);

    cin >> l >> h >> r;
    s = l;
    for (;;){
        if (r>e) { e=r;}    
        for (int i =l; i<r; i++){
            if (h>f[i]) f[i]=h;
        } 
//        printf("%d::%d::%d, ",l,h,r);
        if (scanf("%d %d %d",&l, &h, &r)==EOF){
		break;
	}
    }

//    for (int i = s; i<=e;++i){
//        printf("%d ",f[i]);
//    }
//    cout<<"\n";
//    
    l = s,h=f[l];
    
    while (l<e){
        h=f[l];
        cout << l<< " "<< h << " ";

        while (h==f[l]&&l<e){
            l++;
        }
    }
    
    cout << e<< " 0\n";
}
