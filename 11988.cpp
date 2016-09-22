/*
 * =====================================================================================
 *
 *       Filename:  11988.cpp
 *
 *    Description:  Broken Keyboard
 *
 *        Version:  1.0
 *        Created:  09/12/2016 22:28:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main(){
    char ch=0;
    string buff;
    bool mode;

    for (;ch!=EOF;){
        buff="",mode=1,ch=0;
        list<string> line;
        for (;ch!=10;){
            ch=getchar();
            switch (ch){
                case '[':
                    (mode)?(line.push_front(buff)):
                        (line.push_back(buff));
                    mode=1;
                    buff="";
                    break;
                case ']':
                    (mode)?(line.push_front(buff)):
                        (line.push_back(buff));
                    mode=0;
                    buff="";
                    break;
                case 10:
                    (mode)?(line.push_front(buff)):
                        (line.push_back(buff));
                    for (list<string>::iterator it=line.begin();
                            it!=line.end();it++){
                        cout<<*it;
                    }
                    cout<<"\n";
                    break;
                case EOF:
                    break;
                default:
                    buff=buff+ch;
                    break;
            }
            if (ch==EOF) return 0;
        }
    }
}
