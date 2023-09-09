#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#include<numeric>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  sort(v.begin(), v.end());

  int broj_parova = 0;
  int mentor = 0;

  for (int ucenik = 0; ucenik < n; ucenik++) {
    while (mentor < n && v[mentor] < 2*v[ucenik])
      mentor++;

    if (mentor == n)
      break;

    broj_parova++;
    mentor++;
  } 

  cout << broj_parova << endl;

  return 0;
}