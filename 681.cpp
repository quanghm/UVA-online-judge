/*
 * =====================================================================================
 *
 *       Filename:  681.cpp
 *
 *    Description:  Convex Hull Finding
 *
 *        Version:  1.0
 *        Created:  08/26/2016 10:59:47
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
#include <algorithm>
#include <utility>

using namespace std;

vector<pair<int, int> > points;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ccw
 *  Description:  return postive if p1, p2, p3 are counter clockwise
 *                       negative if they are clockwise
 * =====================================================================================
 */
int ccw(pair<int,int> &p1, pair<int,int> &p2, pair<int,int> & p3){
    return (p2.first - p1.first)*(p3.second-p1.second) - 
           (p2.second- p1.second)*(p3.first - p1.first);
}


bool slope(pair<int,int> p1, pair<int,int>p2){
    int area=ccw(points[0],p1,p2);
    if (area==0) return ((p1.second>p2.second) || 
                (p1.second==p2.second && p1.first>p2.first));
    return (area>0);
}

int main(){
    int k, n, minX, minY, x, y, start;

    cin>> k;
    cout<<k<<"\n";

    while (k--){
        cin>>n;
        cin>> x >> y;

        if (n==1){
            cout<< x<< y << "\n";
            continue;
        }

        points.clear();
        points.push_back(pair<int,int>(x,y));
        minX = x, minY = y, start=0,--n;
        for (int i=1; i<n; i++){
            cin>> x >> y;
            if (y < minY || (y == minY && x < minX)){
                minX=x, minY=y,start=i;
            }
            points.push_back(pair<int,int>(x,y));
        }

        n++;
        // last point:
        cin>>x>>y;

        // swap start to head
        pair<int,int> tmpPoint = points[start];
        points[start] = points[0];
        points[0] = tmpPoint;

        // sort points in increasing polar angle
        sort(points.begin()+1, points.end(),slope);
        points.push_back(points[0]);

        // start now contains number of points in convex hull
        start = 1;
        for (int i = 2;i<n;i++){
            while (ccw(points[start-1],points[start],points[i]) <=0){
                if (start > 1) {
                    start--;
                } else if (i==n){
                    break;
                } else{
                    i++;
                }
            }
            // update number of points and swap points[i]
            start++;
            tmpPoint = points[start];
            points[start] = points[i];
            points[i] = tmpPoint;
        }
        
        start++;
        cout<<start<<"\n";
        for (int i=0;i<start; i++){
            cout<<points[i].first<<" "<<points[i].second<<"\n";
        }
        if(cin>>n){ cout<<n<<"\n";}
    }
}
