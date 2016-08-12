/*
 * =====================================================================================
 *
 *       Filename:  122.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/10/2016 16:11:42
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
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool comparePair(pair<string,int> p1, pair<string,int> p2);
void getTree(vector<pair<string,int> > &tree);
void sortTree(vector<pair<string,int> > &tree);


int main(){
    string s1("LLLR");
    string s2("LLR");

    while (cin>>s1>> s2)
    cout<< s1.compare(s2)<<"\n";
}
