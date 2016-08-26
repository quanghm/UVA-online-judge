/*
 * =====================================================================================
 *
 *       Filename:  11131.cpp
 *
 *    Description:  Close Relatives
 *
 *        Version:  1.0
 *        Created:  08/22/2016 15:37:17
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
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef class Quesnot{
public:
    string name;
    vector<Quesnot*> children;

    // constructors
    Quesnot():  name(""),
                children(vector<Quesnot*>())
                {};

    Quesnot(string &name):  name(name),
                            children(vector<Quesnot*>())
                            {};
} Quesnot;

void printLeft(Quesnot& quesnot){
    for (vector<Quesnot*>::iterator it = quesnot.children.begin();
            it != quesnot.children.end(); ++it){
        printLeft(*(*it));
    }
    cout<<quesnot.name<<"\n";
} 

void printRight(Quesnot &quesnot){
    for (vector<Quesnot*>::reverse_iterator rit = quesnot.children.rbegin();
            rit != quesnot.children.rend(); ++rit){
        printRight(*(*rit) );
    }
    cout<<quesnot.name<<"\n";
}


map<string, int> names;
vector<Quesnot*> all(1);

char getNextName(string& name,int &count){
    char ch;
    name.clear();
    for (;;){
        ch=getchar();
        if (ch==',' || ch=='\n' || ch ==EOF){
            break;
        }
        name +=ch;
    }

    if (!names[name]){
        names[name] = ++count;
        all.push_back(new Quesnot(name));
    }
    return ch;
}

int main(){
    string line, // store the input lines
           name; // store parsed name 

    int count = 0;
    int maxChild=1;
    char ch=0;

    // read names
    while (ch!=EOF){
        for (;;){  // read input line by line
            ch=getNextName(name,count);
            if (ch==10||ch==EOF) break; // single entry
            
            Quesnot* temp = all[names[name]];

            // read the rest of the entries
            while (ch!=10&& ch!=EOF){
                ch = getNextName(name,count);
                (temp->children).push_back(all[names[name]]);
            }

            if ((temp->children).size()>1) {maxChild=2;}
        }
    }

    Quesnot root = *(all[1]);
    if (maxChild==2){
        cout<<"2\n\n";
        printLeft(root);
        cout<<"\n";
        printRight(root);
    } else {
        cout<<"1\n\n";
        printLeft(root);
    }
}
