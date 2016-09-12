/*
 * =====================================================================================
 *
 *       Filename:  624.cpp
 *
 *    Description:  CD -- max subsequence with threshold
 *
 *        Version:  1.0
 *        Created:  09/09/2016 08:28:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

int tracks[21];


vector<int> getSum(int i, int thresh){
    if (thresh<=0 || i==0) return vector<int>(1,0);

    vector<int> temp1 = getSum(i-1, thresh);

    if (thresh < tracks[i]) return temp1;

    vector<int> temp2 = getSum(i-1, thresh-tracks[i]);

    temp2[0] += tracks[i];
    if (temp1[0]>=temp2[0]) return temp1;

    temp2.push_back(tracks[i]);  
    
    return temp2;

}
int main(){
    int numTracks, sum, thresh;

    while (cin>>thresh>>numTracks){
        // read the track lengths
        for (int i=1; i<=numTracks; i++){
            cin>> tracks[i];
        }
        vector<int> result = getSum(numTracks,thresh);

        for (vector<int>::iterator it = result.begin()+1;
                it != result.end(); it++){
            cout<<*it<<" ";
        }
        cout<<"sum:"<<result[0]<<"\n";
    }
}
