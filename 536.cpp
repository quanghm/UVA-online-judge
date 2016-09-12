/*
 * =====================================================================================
 *
 *       Filename:  536.cpp
 *
 *    Description:  Tree Recovery
 *
 *        Version:  1.0
 *        Created:  09/09/2016 14:07:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <stack>


using namespace std;

void getPostOrder(string &s1,
                  int (&map)[100],
                  stack<char> &post,
                  int b1,
                  int b2,
                  int length){
    if (length==0) {
        return;
    }
    int rootPos = map[s1[b1]], // root
        left = rootPos - b2;
    post.push(s1[b1]);
    
    // right subtree
    getPostOrder(s1, map, post, b1+1+rootPos -b2,rootPos+1, length-left-1 );
    // left subtree
    getPostOrder(s1, map, post, b1+1, b2, left);

}

int main(){
    string s1,s2;

    while (cin>>s1>>s2){
        int map[100]={};
        int length=s2.length();
        stack<char> post;

        // record map
        for (int i=0; i<length; i++){
            map[s2[i]] = i;
        }

        getPostOrder(s1,map,post,0,0,length);

        while (!post.empty()){
            cout<<post.top();
            post.pop();
        }
        cout<<"\n";
    }
}
