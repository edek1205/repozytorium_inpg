#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct sLista{
    int d, m, y;
    string tresc_zadania;
    sLista *nastepny;
};

void addBack (sLista *&glowa, int d, int m, int y, string tresc_zadania)
{
    sLista *n;

        if(glowa!=NULL)
        {
            while(glowa->nastepny)           
            {
                glowa=glowa->nastepny;
                n = new sLista;

                glowa->d = d;
                glowa->m = m;
                glowa->y = y;
                glowa->tresc_zadania = tresc_zadania;

                n->nastepny=NULL;
                glowa->nastepny=n;
            }
        }
        else
        {
            cout<<"\n Lista pusta" <<endl;
        }
}

void *wczytanie_danych_do_listy(string adres)
{
        sLista *glowa=0;

        ifstream plik(adres.c_str());

            if(!plik.good())
            {
                cout << "Nastapil blad otwarcia pliku, wprowadz sciezke pliku ponownie: " << endl;
                cin>>adres;
            }

            while(!plik.eof())
            {
                int d, m, y;
                string tresc_zadania;
                plik >> d >> m >> y;
                getline(plik, tresc_zadania);
                addBack(glowa, d, m, y, tresc_zadania);
            }

          //return glowa;
}

void printList(sLista *&glowa)
{

        while(glowa!=NULL)
        {
            cout<<glowa->d <<'\t';
            cout<<glowa->m <<'\t';
            cout<<glowa->y <<'\t';
            cout<<glowa->tresc_zadania <<'\t';

            glowa=glowa->nastepny;
        }

}

int main()
{
    sLista *glowa;
    glowa=NULL;

    string adres;
    cout<<"Wczytaj adres" <<endl;
    cin>>adres;

    wczytanie_danych_do_listy(adres, glowa);

    printList(glowa);

    return 0;