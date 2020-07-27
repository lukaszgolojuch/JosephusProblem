/*
 Jezyk programowania: C/C++
 Środowisko programistyczne: Visual Studio
 Algorytm: Rozbudowany Josephus Problem
 Opis: w pliku readme
 Autor: Lukasz Golojuch
*/
#include <stdio.h>

long long n; // ilosc osob znajdujaca sie w kolku "sekty"
long long k; // miejsce na ktorym mamy zginac
long long miejsce; // przechowuje wartosc zwracana przez funkcje pierwszewolne()
long long zabojstwo; // przechowuje ilosc dotychczasowych zabojstw
bool pierwsza; // przechowuje wartosc pierwsze zajete miejsce w danycm "okrazeniu"
long long p; //zmienna pomocnicza
int ilosc; // przechowuje ilosc testow ktore beda przeprowadzane

/*
 Funkcja long long pierwszewolne(long long tablica[]):
 
 Funkcja przeszukujaca tablice z rozmiejscowieniem osob w kolku sekty i zwracajaca miejsce gdzie znajduje sie pierwsza zywa osoba.
*/
long long pierwszewolne(long long tablica[])
{
    for(long long i = 1; i<=n; i+=2)
    {
        if(tablica[i]==1)
        {
            return i;
        }
    }
    return 0;
}

/*
 Funkcja void szukaj():
 
 Funkcja implikujaca algorytm wyszukujacy na ktorym miejscu musimy sie umiejscowic aby zginac na okreslonej pozycji.
*/
void szukaj()
{
    if(n%2==0)
    {
        zabojstwo = n/2;
        miejsce = 1;
    } else
    {
        zabojstwo=(n-1)/2;
        miejsce = n;
    }
    pierwsza = 0;
    long long * tablica = new long long [n+1];
    for(long long i = 1; i<=n; i+=2)
    {
        tablica[i]=1;
    }
    
    while(1)
    {
        if(pierwsza==false && tablica[miejsce]==1)
        {
            pierwsza = true;
        }
        else if(pierwsza==true && tablica[miejsce]==1)
        {
            tablica[miejsce]=0;
            pierwsza = false;
            zabojstwo++;
            if(zabojstwo==k)
            {
                printf("%lld \n",miejsce);
                break;
            }
        }
        if(miejsce+2<=n)
        {
            miejsce+=2;
        }else
        {
            miejsce = pierwszewolne(tablica);
        }
    }
    
    delete [] tablica;
}

/*
 Funkcja void rowne():
 
 Funkcja zostaje uruchomiona gdy mamy zginac przy pierwyszym okrazeniu dzialania funkcji, czyli kiedy mamy zginac na miejscu mniejszym niz k/2, gdzie k to ilosc osob znajdujacych sie w okrazeniu.
 
 Funkcja wypisuje na ekranie wartosc n-tej wielokrotnosci liczby 2, gdzie n to numer w kolejnosci ktorej chcemy zginac.
*/
void parzyste()
{
    p=0;
    for(long long i=0; i<k; i++)
    {
        p+=2;
    }
    printf("%lld \n",p);
}
/*
 Funkcja void rowne():
 
 Funkcja zostaje uruchomiona gdy mamy zginac jako ostatni, czyli jako n-ta osoba z n-tej grupy osob.
 
 Funkcja ta wypisuje na ekaranie wartosc wyrazenia: (2 * n) - p + 1, które jest wzorem na rozwiązanie podstawowego problemy Josephusa
*/
void rowne()
{
    p = 1;
    while (p <= n)
        p *= 2;
    // potega liczby p mniejsza od n odjeta od podwojonej liczby osob dodajemy 1
    printf("%lld \n",(2 * n) - p + 1);
}




int main()
{
    scanf("%d",&ilosc);
    for(int i=0;i<ilosc;i++)
    {
        scanf("%lld",&n);
        scanf("%lld",&k);
        if(n%2!=0)
        {
            p=(n-1)/2;
        }
        else
        {
            p=n/2;
        }
        if(k<0)
        {
            k+=(n+1);
        }
        if(k==n)
        {
            rowne();
        }
        else if(p>=k)
        {
            parzyste();
        }
        else
        {
            szukaj();
        }
    }
    return 0;
}
