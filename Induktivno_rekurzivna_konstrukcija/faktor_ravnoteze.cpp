#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits>

using namespace std;

int visina(Cvor *koren)
{
	if (koren == nullptr)
		return 0;

	return 1 + max(visina(koren->levo), visina(koren->desno))
}

int max_faktor(Cvor *koren)
{
	if (koren == nullptr)
		return 0;

	int levo = visina(koren->levo);
	int desno = visina(koren->desno);
	int faktor = abs(levo - desno);
	int max_levo = max_faktor(koren->levo);
	int max_desno = max_faktor(koren->desno);

	return max({faktor, max_levo, max_desno});
}

void max_faktor_visina(Cvor *koren, int &visina, int &max_faktor)
{
	if (koren == nullptr) {
		visina = max_faktor = 0;
		return ;
	}

	int v_levo, m_levo;
	max_faktor_visina(koren->levo, v_levo, m_levo);

	int v_desno, m_desno;
	max_faktor_visina(koren->desno, v_desno, m_desno);

	int faktor = abs(v_levo-v_desno);
	max_faktor = max({faktor, m_levo, m_desno});
	visina = 1 + max(v_levo, v_desno);
}

int main()
{



	return 0;
}
