/*
 * =====================================================================================
 *
 *       Filename:  11650.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/09/2016 20:03:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<cstdio>

using namespace std;

int main(){
	int n,hh,mm;
	char ch;
	scanf("%d",&n);

	while (n--){
		scanf("%d:%d",&hh,&mm);
//		printf("hh:mm = %d:%d\n",hh,mm);

		if (mm){
			if (hh==12){
				printf("11:%02d\n",60-mm);
			} else if (hh==11){
				printf("12:%02d\n",60-mm);
			}else {
				printf("%02d:%02d\n",11-hh,60-mm);
			}
		} else {
			if (hh==12){
				printf("12:00\n");
			} else {
				printf("%02d:00\n",12-hh);
			}
		}
	}
}
