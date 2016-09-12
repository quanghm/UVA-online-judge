/*
 * =====================================================================================
 *
 *       Filename:  10409.cpp
 *
 *    Description:  Die Game
 *
 *        Version:  1.0
 *        Created:  09/10/2016 06:17:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int nums,temp;
    string command;
    int faces[7];

    while (cin>>nums && nums){
        // reset faces
        for (int i=1; i<7; i++){
            faces[i] = i;
        }

        while (nums--){
            cin>>command;

            switch (command[0]){
                case 'n':
                    temp=faces[1],faces[1]=faces[5],
                    faces[5]=faces[6],faces[6]=faces[2],
                    faces[2]=temp;
                    break;
                case 's':
                    temp=faces[1],faces[1]=faces[2],
                    faces[2]=faces[6],faces[6]=faces[5],
                    faces[5]=temp;
                    break;
                case 'w':
                    temp=faces[1],faces[1]=faces[4],
                    faces[4]=faces[6],faces[6]=faces[3],
                    faces[3]=temp;
                    break;
                case 'e':
                    temp=faces[1],faces[1]=faces[3],
                    faces[3]=faces[6],faces[6]=faces[4],
                    faces[4]=temp;
                    break;
            }
        }
        cout<<faces[1]<<"\n";
    }
}
