/* #include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>
#include<stack>

using namespace std;

int main()
{
	int k, n;
	cin >> k >> n;

	stack<int> vrednosti;
	stack<int> duzine;
	int t;

	while (n--) {
		cin >> t;

		if (!vrednosti.empty() && vrednosti.top() != t && duzine.top() >= k) {
			vrednosti.pop();
			duzine.pop();
		} 

		if (!vrednosti.empty() && vrednosti.top() == t)
			duzine.top()++;
		else {
			vrednosti.push(t);
			duzine.push(1);
		}		
	}

	// oprada posednjeg segmenta kada dodjemo do kraja niza
	if (vrednosti.top() != t && duzine.top() >= k) {
		vrednosti.pop();
		duzine.pop();
	} 



	return 0;
}
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>
#include<stack>

using namespace std;

int main()
{
	int k, n;
	cin >> k >> n;

	vector<int> vrednosti;
	vector<int> duzine;
	int t;

	while (n--) {
		cin >> t;

		if (!vrednosti.empty() && vrednosti.back() != t && duzine.back() >= k) {
			vrednosti.pop_back();
			duzine.pop_back();
		} 

		if (!vrednosti.empty() && vrednosti.back() == t)
			duzine.back()++;
		else {
			vrednosti.push_back(t);
			duzine.push_back(1);
		}		
	}

	// oprada posednjeg segmenta kada dodjemo do kraja niza
	if (vrednosti.back() != t && duzine.back() >= k) {
		vrednosti.back();
		duzine.pop_back();
	} 

	for (int i = 0; i < vrednosti.size(); i++) {
		while (duzine[i]--)
			cout << vrednosti[i] << ' ';
	}

	cout << endl;

	return 0;
}
