#include <iostream>
#include <vector>
//#include <string>

using namespace std;

vector<string> beolvas_felhasznalo(const int& N) {
    vector<string> result (N);
    for (int i = 0; i < N; i++)
    {
        string veznev;
        string kernev;
        cin >> veznev >> kernev;
        result[i] = veznev + " " + kernev;
    }
    return result;
}

vector<vector<int>> beolvas_kapcsolatok(const int& N, const int& E) {
    vector<vector<int>> graf (N, vector<int>());

    for (int i = 0; i < E; i++)
    {
        int honnan;
        int hova;
        cin >> honnan >> hova;
        graf[honnan].push_back(hova);
    }

    return graf;
}

void diagnosztika(vector<vector<int>>& graf, const int& N) {
    for (int i = 0; i < N; i++)
    {
        cout << i << ": [ ";
        for (int& elem : graf[i])
        {
            cout << elem << " ";
        }
        cout << "]\n";
    }

    //graf[0] = vector<int>();
}

int feladat4_szam(vector<vector<int>>& graf) {
    for( int i = 0; i<graf.size();i++)
    {
        if (graf[i].size() == 0)
        {
            return i ;
        }
    }
    return -1;
}

vector<int> onkovetok_kivalogatasa(vector<vector<int>>& graf) 
{
    vector<int> result;
    for (int i = 0; i < graf.size(); i++)
    {
        for (int j = 0; j < graf[i].size(); j++)
        {
            if (graf[i][j]==i)
            {
                result.push_back(i);
            }
        }
    }
    return result;
}

bool ismeri(int i, int j) {
    //...már megcsináltuk korábban. 
}

vector<vector<int>> egymast_kovetok_megoldasa(vector<vector<int>> graf) 
{
    vector<vector<int>> result;
    for (int i = 0; i < graf.size(); i++)
    {
        for (int j = i+1; j < graf.size(); j++)
        {
            if (ismeri(i,j) && ismeri(j,i))
            {
                result.push_back({ i, j });
            }
        }
    }
    return result;
}

int main()
{
    int N;
    int E;
    cin >> N;
    cin >> E;
    vector<vector<int>> graf = beolvas_kapcsolatok(N, E);
    vector<string> felhasznalok = beolvas_felhasznalo(N);

    cout << "\n\nIgy nez ki a graf szomszedsagi listas reprezentacioban:" << endl;

    diagnosztika(graf, N);

    //cout << graf[0].size(); // 0-ra számítunk, mert a diagnosztika utolsó sorában lenulláztuk a 0. elem szomszédait!

    cout << "2.1. feladat: " << graf[0].size() << endl;

    cout << "2.2. feladat: " << endl;

    for (int& csucs : graf[1])
    {
        cout << csucs << " ";
    }
    cout << endl;
    cout << "2.3. feladat: " << graf[4].size() << endl;

    cout << "2.4. feladat: " << endl;
    int n = feladat4_szam(graf);

    if (0 < n)
    {
        cout << "Igen, van: " << felhasznalok[n] << "\n";
    }
    else 
    {
        cout << "Nem, nincs." << endl;
    }

    //cout << "árvíztûrõ tükörfúrógép";

    n = feladat4_szam(graf);

    cout << "2.5. feladat: " << (n == -1 ? "Van" : "Nincs") << "\n";

    cout << "2.6. feladat: \n";
    vector<int> onkovetok = onkovetok_kivalogatasa(graf);
    cout << "önkövetõk: ";
    for (int& elem : onkovetok)
    {
        cout << elem << " ";
    }

    cout << "2.7. feladat: egymást követõk\n";

    vector<vector<int>> egymast_kovetok = egymast_kovetok_megoldasa(graf);
}




/** /
10
16
0 1
0 3
1 2
1 4
2 1
2 5
3 0
3 4
4 4
4 6
5 2
6 1
6 7
7 6
7 8
8 4
Krumpli Kapitány
Pöttyös Pista
Uborka Ubul
Zokni Zénó
Morzsa Móric
Palacsinta Panka
Buborék Béla
Csiga Csenge
Túrórudi Tóbiás
Láthatatlan Lajos

/**/





/** / 
1. feladat.Alakítsd át az éllistát szomszédsági listás reprezentációba!Minden csúcshoz sorold fel azokat a csúcsokat, amelyekbe belõle él vezet!

2. A követési kapcsolatok vizsgálata
A következõ kérdésekre a szomszédsági lista alapján válaszolj!
1. Hány felhasználót követ a 0 - s felhasználó ?
2. Kik azok a felhasználók, akiket az 1 - es felhasználó követ ?
3. Hány felhasználót követ a 4 - es felhasználó ?
4. Van - e olyan felhasználó, aki senkit sem követ ? Ki az ?
5. Van - e olyan felhasználó, akit senki sem követ ?
6. Mely felhasználók követik saját magukat ?
7. Mely felhasználópárok követik egymást kölcsönösen ?
8. Kik követik a 4 - es felhasználót ?
9. Melyik felhasználó követi a legtöbb különbözõ felhasználót ?
10. Hány követési kapcsolat van összesen a rendszerben ?

3. Gráfelméleti alapfogalmak
11. Hány csúcsa és hány éle van a gráfnak ?
12. Van - e a gráfban hurokél ? Ha igen, melyik csúcsnál ?
13. Van - e a gráfban izolált csúcs, vagyis olyan csúcs, amelyhez egyetlen él sem kapcsolódik ?
14. Mely csúcsok kifoka 2 ?
15. Mennyi a 4 - es csúcs befoka és kifoka ?
16. Van - e olyan csúcs, amelynek kifoka 0, de befoka nem 0 ?
17. Van - e olyan csúcs, amelynek befoka 0, de kifoka nem 0 ?
18. Igaz - e, hogy a csúcsok kifokainak összege megegyezik az élek számával ? Ellenõrizd!

4. Összetettebb kérdések
19. A 0 - s felhasználó szeretne eljutni a 2 - es felhasználó profiljához úgy, hogy mindig egy általa követett felhasználó profiljára lép tovább.Megteheti - e ezt legfeljebb két lépésben ?
20. El lehet - e jutni a 8 - as felhasználó profiljáról a 0 - s felhasználó profiljára a követési kapcsolatok mentén ?
21. Mely felhasználók érhetõk el a 6 - os felhasználótól legfeljebb két követési lépéssel ?
22. Ha megszüntetjük a(4, 4) kapcsolatot, hogyan változik a 4 - es csúcs befoka és kifoka ?
/**/