/*
 * 10935.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<queue>
using namespace std;

int main() {
	int n,t;
	while (scanf("%d", &n) != EOF && (n)) {
		queue<int> deck;
		printf("Discarded cards:");
		for (int i = 1; i <= n; i++) {
			deck.push(i);
		}
		//n--;
		while (n--){
			t=deck.front();
			deck.pop();
			if (deck.empty()){
				printf("\nRemaining card: %d\n",t);
				break;
			}else{
				printf(" %d",t);
				if (n>1){printf(",");}
				t=deck.front();
				deck.pop();
				deck.push(t);
			}
		}
	}
}

