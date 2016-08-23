/*
 * =====================================================================================
 *
 *       Filename:  10670.1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/08/2016 23:50:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void getAgentName(vector<char> &agentName);
void printAgentName(vector<char> agentName);

vector<vector<char> > agents(100, vector<char>(16,0));
vector<long long> costs(100,0);

bool compareAgents(char a1, char a2){
    if (costs[a1]<costs[a2]) return true;
    if (costs[a1]==costs[a2]){
        int i = 0;
        while (i<16&&agents[a1][i]== agents[a2][i]){
            i++;
        }
        return (i<16 && agents[a1][i]<agents[a2][i]);
    }
    return false;
}
long long getCost(int n, int m, int a, int b);

int main(){
	int c, n, m, l, a, b;
	string agentName;
	scanf("%d",&c);

	int t=0;
	char ch=0;

	while (t++<c){
		printf("Case %d\n",t);

		scanf("%d %d %d", &n, &m, &l);

                vector<char> orders(l);

		
		
		vector<char>::iterator it; 
		ch=getchar();

		for (int i = 0; i< l; ++i){
                    // reset agent name
                    fill(agents[i].begin(),agents[i].end(),0);
                    orders[i] = i;		    
                    while (ch < 'A' || ch > 'Z'){ // get rid of non-alpha characters
				ch = getchar();
			}	// ch is now the first alpha
			
                    for(it = agents[i].begin();;++it){ // read string
                                // get agent name
				*it = ch; 
				ch = getchar();
				if (ch==':') break;
			}

			// read a,b
			scanf("%d,%d",&a, &b);
			costs[i] = getCost(n,m,a,b);
		}

                // sort agents
                sort(orders.begin(),orders.end(),compareAgents);

		// print result
		for (int i = 0; i<l;++i){
			it = agents[orders[i]].begin();
			while (*it){
				putchar(*it);
				it++;
			}
			printf(" %lld\n", costs[orders[i]]);
		}
	}
}

long long getCost(int n, int m, int a, int b){
	if (m>=n) return 0;
        long long single = (n-m)*a;
	if (n<2*m){
		return single;
	}
	long long cost = getCost( n/2, m, a,b) + b;
	if (cost < single){
		return cost;
	} else {
		return single;
	}
}
