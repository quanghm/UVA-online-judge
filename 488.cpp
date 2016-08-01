#include <iostream>
using namespace std;

int main() {
	int n, w, a;

	cin >> n;


	while (n--) {
		//getline(cin,l);
		cin >> a >> w;

		int k=0;
		while (w--) {

			for (int i = 1; i <= a; i++) {
					k=i;
					while(k--) {
						cout<<i;
					}
					cout << endl;
			}
			for (int j = a- 1; j > 0; j--) {
					k=j;
					while(k--){
						cout<<j;
					}
					cout<<endl;
				}
			if ((w)||(n))
							cout << endl;
		}
	}
}
