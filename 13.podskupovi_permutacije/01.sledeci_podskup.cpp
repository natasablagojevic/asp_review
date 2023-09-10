#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

bool sledeci_podskup(vector<int> &skup, int n)
{
  if (skup.empty())  {
    skup.push_back(1);
    return true;
  }

  if (skup.back() < n) {
    skup.push_back(skup.back() + 1);
    return true;
  }

  skup.pop_back();

  if (skup.empty())
    return false;

  skup.back()++;
  return true;
}

int main()
{




  return 0;
}