/*
 * 11057.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>


using namespace std;

int main(){
	int n,b,s;
	bool first=true;
	while (scanf("%d",&n)!=EOF){
		vector<int> books;
		stack<pair<int, int> > st;
		for (int i=0;i<n;i++){
			scanf("%d",&b);
			books.push_back(b);
		}
		scanf("%d",&s);

		sort(books.begin(),books.end());
//		for (int i=0;i<n;i++){
//			printf("%d ",books[i]);
//		}
//		printf("\n");
		int i=0,j=n-1,sum=0;
		while (i<j){
//			printf("%d:%d\n",i,j);
			sum=books[i]+books[j];
			if (sum==s){
				st.push(pair<int,int>(books[i],books[j]));
				i++;
			}else if (sum<s){
				i++;
			}else {
				j--;
			}
		}
//		if (first){
//			first=false;
//		}
//		else{
//			printf("\n");
//		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",st.top().first,st.top().second);
	}
}


