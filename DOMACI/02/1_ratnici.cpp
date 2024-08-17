#include <bits/stdc++.h>

using namespace std;

struct Ratnik
{
    uint64_t pozicija;
    uint64_t snaga;
    char smer;
    int broj;
};

bool kriterijum(const Ratnik a, const Ratnik b)
{
    return a.pozicija < b.pozicija;
}

bool kriterijum1(const Ratnik a, const Ratnik b)
{
    return a.broj < b.broj;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;
    
    int l = 0;
    int d = 0;
    
    vector<Ratnik> ratnici(n);
    vector<Ratnik> desni;
    vector<Ratnik> levi;

    for (int i = 0; i < n; i++) {
        cin >> ratnici[i].pozicija;
        ratnici[i].broj = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> ratnici[i].snaga;
    }

    for (int i = 0; i < n; i++) {
        cin >> ratnici[i].smer;
    }

    for (int i = 0; i < n; i++) {
        if (ratnici[i].smer == 'D') {
            levi.push_back(ratnici[i]);
            l++;
        } else {
            desni.push_back(ratnici[i]);
            d++;
        }
    }

    if (l == n || d == n) {
        for (int i = 0; i < n; i++)
            cout << ratnici[i].snaga << " ";
        return 0;
    }

    sort(levi.begin(), levi.end(), kriterijum);
    sort(desni.begin(), desni.end(), kriterijum);

    for (int i = l-1; i >= 0; i--) {
        for (int j = 0; j < d; j++) {
            if (levi[i].snaga > 0 && desni[j].snaga > 0 && (levi[i].pozicija <= desni[j].pozicija)) {
                if (levi[i].snaga > desni[j].snaga) {
                    desni[j].snaga = 0;
                    levi[i].snaga--;
                } else if (levi[i].snaga == desni[j].snaga) {
                    desni[j].snaga = 0;
                    levi[i].snaga = 0;
                    break;
                } else {
                    levi[i].snaga = 0;
                    desni[j].snaga--;
                    break;
                }
            }
        }
    }

    vector<Ratnik> svi;
    for (int i = 0; i < l; i++)
        svi.push_back(levi[i]);
    
    for (int i = 0; i < d; i++)
        svi.push_back(desni[i]);
    
    sort (svi.begin(), svi.end(), kriterijum1);
    
    bool preziveli = false;
    for (int i = 0; i < n; i++) {
        if (svi[i].snaga > 0){
        cout << svi[i].snaga << " ";
        preziveli = true;
        }
    }

    if (preziveli == false)
        cout << " ";
    
    return 0;
}
