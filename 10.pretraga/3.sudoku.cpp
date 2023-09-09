#include<iostream>
#include<numeric>
#include<vector>
#include<limits>
#include<cmath>

using namespace std;

const int n = 9;

bool sudoku(vector<string> &s, int pos)
{
  int i = pos / n;
  int j = pos % n;

  if (pos == n*n) 
    return true;

  if (s[i][j] != '0') 
    return sudoku(s, pos + 1);
  
  for (char c = '1'; c < '9'; c++) {
    s[i][j] = c;

    // da li na polju (i,j) moze da se nalazi zadati broj
    if (provera(s, i, j)) 
      if (sudoku(s, pos + 1))
        return true;    
  }

  /*  NISMO UPALI U RETURN TRUE (28) TO ZNACI DA SMO PROBALI SVE BROJEVE OD
      1 DO 9 I DA NIJEDAN OD NJIH NIJE MOGAO DA SE POSTAVI TAMO I DA PRITOM RESIMO SUDOKU
      VRACAMO POLJE KOJE JE BILO NA NULI NA POCETKU
   */

  s[i][j] = '0';
  return false;
}

int main()
{ 
  vector<string> s(n);  

  for (int i = 0; i < n; i++)
    cin >> s[i];

  


  return 0;
}