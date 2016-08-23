/*
 * =====================================================================================
 *
 *       Filename:  12626.cpp
 *
 *    Description:  I love pizza
 *
 *        Version:  1.0
 *        Created:  08/20/2016 01:52:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quang M. Hoang (QH), quanghm@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cstdio>

using namespace std;

int main(){
    int n;
    char ch;
    
    scanf("%d",&n);

    ch=getchar();

    while (n--){
        int total[6]={}; // MARGARITA -- A I M G R T
        for(;;){
            ch=getchar();
            putchar(ch);
            
            if (ch=='\n'||ch==EOF) {
                for (int i=0;i<6;++i){
                    printf("total[%d]=%d\n", i, total[i]);
                }
                
                total[0] /= 3, total[4] /= 2;
                int a=total[0];
                for (int i=1;i<6;++i){
                    if (a>total[i]) a=total[i];
                }
                printf("%d\n",a);
                break;
            }

            switch (ch){
                case 'A':
                    total[0] ++;
                    break;
                case 'I':
                    total[1]++;
                    break;
                case 'M':
                    total[2]++;
                    break;
                case 'G':
                    total[3]++;
                    break;
                case 'R':
                    total[4]++;
                    break;
                case 'T':
                    total[5]++;
                    break;
            }
        }
    }

}
