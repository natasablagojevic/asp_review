#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool sledeci_broj(string &s)
{
  int n = s.length();
  int i = n-1;

  while ((i >= 0 && s[i] == '1') || (i > 0 && s[i-1] == '1'))
    s[i--] = '0';

  if (i < 0)
    return false;

  s[i] = '1';
  return true;
}

void svi_brojevi(int n)
{
  string s(n, '0');

  do {
    cout << s << endl;
  } while (sledeci_broj(s));
}

int main()
{ 
  int n;
  cin >> n;

  svi_brojevi(n);

  return 0;
}