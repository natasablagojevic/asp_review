#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& room, int x, int y, int& paths) {
    int n = room.size();
    int m = room[0].size();

    // Provera da li smo stigli do kraja
    if (room[x][y] == 2) {
        ++paths;
        return;
    }

    // Označavanje polja koja smo posetili
    room[x][y] = -1;

    // Pokretanje u četiri smera
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // Provera da li su novi indeksi unutar granica i da li je polje moguće posećeno
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && room[newX][newY] != -1) {
            dfs(room, newX, newY, paths);
        }
    }

    // Vraćanje polja u stanje pre posećivanja
    room[x][y] = 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> room(n, vector<int>(m));
    int start_x, start_y;

    // Učitavanje matrice i pronalazak startne pozicije
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> room[i][j];
            if (room[i][j] == 1) {
                start_x = i;
                start_y = j;
            }
        }
    }

    int paths = 0;
    dfs(room, start_x, start_y, paths);

    cout << paths << endl;

    return 0;
}
