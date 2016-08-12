/*
 * =====================================================================================
 *
 *       Filename:  10653.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/03/2016 16:14:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int r, c; // row and column
    int sr, sc, dr, dc; // source and destination coordinates 

    int numRowsWithBombs, row, numBombsinRow, col;
    while ((cin>>r>>c)&& (r||c)){

        vector<vector<int> > land(r, vector<int>(c,0));

        cin >> numRowsWithBombs;

        // read the bomb locations
        while (numRowsWithBombs--){
            cin >> row>> numBombsinRow;

            while (numBombsinRow--){
                cin >> col;
                land[row][col]=-1;
            }
        }

        // read source and dest
        cin >> sr >> sc >> dr >>dc;

    }
}
