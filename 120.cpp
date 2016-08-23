/*
 * =====================================================================================
 *
 *       Filename:  120.cpp
 *
 *    Description:  Stacks of Flapjacks
 *
 *        Version:  1.0
 *        Created:  08/15/2016 11:52:39
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
#include <list>
#include <queue>
#include <vector> 

using namespace std;

int main(){
    char ch;

    int temp, max, count,toMove,val;

    for (;;){
        if (scanf("%d",&temp) == EOF){ // end of input
            return 0;
        }

        list<int> diam;
        list<int>::iterator it;
        priority_queue<int> pq;
        
        printf("%d",temp);
        
        diam.push_back(temp);
        pq.push(temp);

        ch=getchar(), count = 1;
        
        while (ch!='\n'){
            scanf("%d",&temp);
            diam.push_back(temp);
            pq.push(temp);

            printf(" %d",temp);
            
            count++,ch=getchar();
        }
        printf("\n");
        
        int finished = 0,head;

        while (finished++ < count){
            head = finished;
            // get next max
            max = pq.top(), pq.pop();
            it = diam.begin();

            for (;;){
                // look at end of list
                val = diam.back(),diam.pop_back();
                if (val==max){
                    break;
                } else {
                    diam.insert(it,val);
                    head++;
                }
            }

            if (head == finished){
                continue;
            }

            if (head == count){
                printf("%d ", finished);
            } else {
                printf("%d %d ",head, finished);
            }
        }

        printf("0\n");

    }
}
