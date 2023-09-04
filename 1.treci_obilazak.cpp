#include <iostream>
#include <vector>

using namespace std;

string postfiks(string prefiks, string infiks)
{
	if (prefiks == "" || infiks == "")
		return "";

	char koren = prefiks[0];

	int duzinaL = infiks.find(koren);

	string preL = prefiks.substr(1, duzinaL);
	string inL = infiks.substr(0, duzinaL);

	string preD = prefiks.substr(1+duzinaL);
	string inD = infiks.substr(1+duzinaL);

	return postfiks(preL, inL) + postfiks(preD, inD) + koren;
}

int main(int argc, char const *argv[])
{
	string prefiks;
	string infiks;

	cin >> prefiks >> infiks;

	cout << postfiks(prefiks, infiks) << endl;


	return 0;
}