/*  BACKTRAKING */

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>
#include<iomanip>
#include<cmath>

using namespace std;

bool sledeca_podela(vector<bool> &podela)
{
  int i = podela.size() - 1;
  while (i >= 0 && podela[i] == 1) 
    podela[i--] = 0;
  
  if (i < 0)
    return false;

  podela[i] = 1;

  return true;
}

/*  OVO JE SPORIJE RESENJE O(n*2^n)
    MORAMO DA PRODJEMO KROZ SVE PODELE
 */
double sve_podele(vector<double> &v)
{
  vector<bool> podela(v.size());
  double res = numeric_limits<double>::max();

  do {
    // obradi podelu

    double zbir1 = 0;
    double zbir2 = 0;

    for (i = 0; i < v.size(); i++) {
      if (podela[i])
        zbir1 += v[i];
      else 
        zbir2 += v[i];
    }

    res = min(res, abs(zbir1 - zbir2));    
  } while (sledeca_podela(podela));

  return res;
}

double sve_podele2(vector<double> &v, vector<bool> &podela)
{
  if (podela.size() == v.size()) {
    // obrada podele 

    double zbir1 = 0, zbir2 = 0;

    for (int i = 0; i < v.size(); i++) {
      if (podela[i])
        zbir1 += v[i];
      else 
        zbir2 += v[i];
    }

    return abs(zbir1 - zbir2);
  }

  podela.push_back(0);
  double resL = sve_podele2(v, podela);
  podela.pop_back();

  podela.push_back(1);
  double resD = sve_podele2(v, podela);
  podela.pop_back();

  return min(resL, resD);
}

// zbir = zbir nerasporedjenih
double sve_podele3(vector<double> &v, int i, double zbir, double zbir1, double zbir2)
{
  if (i == v.size()) {
    return abs(zbir1 - zbir2);
  }

  /* 
      ODSECI PRETRAGU ONDA KADA ZNAS KOJE JE NAJBOLJE RESENJE U GRANI PRETRAGE
      
   */
  if (zbir1 + zbir < zbir2) {
    return zbir2 - (zbir1 + zbir);
  }

  if (zbir2 + zbir < zbir1) 
    return zbir1 - (zbir2 + zbir);

  double resL = sve_podele3(v, i + 1, zbir - v[i], zbir1 + v[i], zbir2);
  double resD = sve_podele3(v, i + 1, zbir - v[i], zbir1, zbir2 + v[i]);

  return min(resL, resD);
}

int main()
{
  int n;
  cin >> n;

  vector<double> v(n);
  double zbir = 0.0;

  for (int i = 0; i < n; i++) {
    cin >> v[i];  
    zbir += v[i];
  }


  // cout << sve_podele(v) << endl;
  // cout << fixed << setprecision(2) << sve_podele(v) << endl;

  // vector<bool> podela(n);
  // cout << fixed << setprecision(2) << sve_podele2(v, podela) << endl;

  cout << fixed << setprecision(2) << sve_podele3(v, 0, 0.0, 0.0) << endl;

  return 0;
}