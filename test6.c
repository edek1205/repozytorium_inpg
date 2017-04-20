#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct sLista{
    int d, m, y;
    string tresc_zadania;
    sLista *nastepny;
};

void dodajElement(sLista **glowa, int d, int m, int y, string tresc_zadania)
{
    sLista *nowy = new sLista;
    nowy->d = d;
    nowy->m = m;
    nowy->y = y;
    nowy->tresc_zadania = tresc_zadania;
    nowy->nastepny = NULL;

    sLista *tmp = *glowa;
    if (tmp != NULL)
    {
        while(tmp->nastepny)
            tmp = tmp->nastepny;
            tmp->nastepny = nowy;
    }
    else
    {
        *glowa = nowy;
        (*glowa)->nastepny = NULL;
    }
}

void *wczytanie_danych_do_listy(string adres, sLista *&glowa)
{
            ifstream plik(adres.c_str());

            if(!plik.good())                                                                            //Jak to zrobiæ ¿eby prawid³owo dzia³a³o?
            {
                plik.close();
                cout << "Nastapil blad otwarcia pliku, wprowadz sciezke pliku ponownie: " << endl;
                cin>>adres;
                ifstream plik(adres.c_str());
            }

            int d, m, y;
            string tresc_zadania;
            sLista *a;

            while(!plik.eof())
            {
                plik >> d >> m >> y;
                getline(plik, tresc_zadania);
                if(glowa==0)
                {
                    dodajElement(&glowa, d, m, y, tresc_zadania);
                    a=glowa;
                }
                else
                {
                    dodajElement(&a->nastepny, d, m, y, tresc_zadania);
                    a=a->nastepny;
                }
            }
           // plik.close();

          return a;
}

void drukowanie_listy(sLista *&glowa)
{

    int l=1;   

        while(glowa!=NULL)
        {
            cout<<l++<<". ";
            cout<<glowa->d << "/";
            cout<<glowa->m <<"/";
            cout<<glowa->y <<"   ";
            cout<<glowa->tresc_zadania;
            cout<<endl;

            glowa=glowa->nastepny;
        }

}

void usuwanie_pierwszego_elementu(sLista *&glowa)  
{
  sLista *p = glowa; 

  if(p)
  {
    glowa=p->nastepny; 
    delete p;         
  }
}

void usun_element(sLista *&glowa, sLista *e) 
{
  sLista *p;

  if(glowa==e)
  {
      usuwanie_pierwszego_elementu(glowa);
  }
  else
  {
    p = glowa;
    while(p->nastepny!=e)
    {
        p = p->nastepny;
        p->nastepny = e->nastepny;
    }
    delete e;
  }
}

//====================================================================================================================

int main()
{
    sLista *glowa;
    glowa=NULL;

    string adres;
    cout<<"Wczytaj adres: ";
    cin>>adres;
    cout<< endl;

    wczytanie_danych_do_listy(adres, glowa);

    drukowanie_listy(glowa);

    cout<<"dodawanie zadania"<<endl;
    int d, m, y;
    string tresc_zadania;
    cout<<"dzien_msc_rok_tresc"<<endl;
    cin>>d>>m>>y;
    getline(cin, tresc_zadania);
    dodajElement(&glowa, d, m, y, tresc_zadania);

    ofstream plik;
    plik.open(adres.c_str(), ios::app);
    if(plik.good())
    {
        plik<<d << " ";
        plik<<m <<" ";
        plik<<y <<" ";
        plik<<tresc_zadania;
        plik<<endl;
    }
    else
    {
        cout<< "B³¹d otwarcia pliku"<<endl;
        return 1;
    }

    drukowanie_listy(glowa);
    plik.close();

    return 0;
}