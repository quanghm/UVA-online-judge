#include <iostream>

using namespace std;
//stack<bool> b; // binary string

int main() {
	int n = 0, i = 0, j = 0,p=0;
	string m;
	bool c, l;
	bool b[100] = { };
	int d[40] = { };
	int a[3];
	while ((cin >> n >> m) && (n)) {
		//	if (m) {

		// string to int
		i = m.length();
		for (int k = 0; k < i; k++) {
			d[k] = m[k] - 48;
		}

		// build binary string
		j = 0;	//index of binary position
		p=0;	//leading non-zero
		while ((p!=i-1)||(d[i-1])) {
			l = 0;
			//get first non-zero digit
			while(d[p]==0){p++;}
			// divide by 2
			for (int k = 0; k < i; k++) {
				c = d[k] % 2;
				d[k] = d[k] / 2+ 5*l;
				l = c;
			}
			b[j++] = c;
		}

		// m has j binary digits
		a[0] = n-j;
		a[1] = 0;
		a[2] = 0;

		 p = 0;	//current position
		while (j--) {	// j digits in stack
			//cout << j << ":" << endl;
			i = 1;	//reset counter
			p = (b[j] ^ (j % 2)) ? ((p + 1) % 3) : ((p + 2) % 3);// set current position
			while (j && (b[j] == b[j - 1])) { // track the number of moved disks
				j--;
				i++;
			}
			a[p] += i;
		}
		cout << a[0] << " " << a[1] << " " << a[2] << endl;
//		} else {
//			cout << n << " 0 0" << endl;
//		}
	}
}
