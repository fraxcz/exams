#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_LENGTH 20

typedef struct Osoba{
    char jmeno[NAME_LENGTH];
    int vek;
} Osoba;

int porovnej (Osoba A, Osoba B);
void vymen(Osoba* A, Osoba* B);
int nejmensi (int delka, Osoba pole[]);
void serad(int serazeno, int delka, Osoba pole[]);
void print_porovnej(int a);
void print_osoba(Osoba A);
void print_osoby(Osoba *A, int len);
int main()
{
    Osoba osoby[] = {{"Bob", 23}, {"Cecil", 23}, {"Bob", 22}, {"Alice", 24}, {"Daniela", 21}};


    //porovnej
    int porovnejab = porovnej(osoby[0], osoby[1]);
    int porovnejac = porovnej(osoby[0], osoby[2]);

    print_osoba(osoby[0]);
    print_osoba(osoby[1]);
    print_porovnej(porovnejab);
    printf("\n");

    print_osoba(osoby[0]);
    print_osoba(osoby[2]);
    print_porovnej(porovnejac);
    printf("\n");
    //vymen
    printf("Vymen 2 a 5 osobu:\n");
    print_osoby(osoby, 5);
    vymen(&(osoby[1]), &(osoby[4]));
    print_osoby(osoby, 5);
    printf("\n");
    //nejmensi
    print_osoby(osoby, 5);
    printf("Index osoby s nejmenší hodnotou: %d\n", nejmensi(5, osoby));
    printf("\n");
    //serad
    printf("serad:\n");
    serad(0, 5, osoby);
    print_osoby(osoby, 5);
    return 0;
}

int nejmensi (int delka, Osoba pole[])
{
    int nejmensiIndex = 0;

    for(int i = 1; i < delka; i++)
    {
        if(porovnej(pole[i], pole[nejmensiIndex]) < 0)
            nejmensiIndex = i;
    }
    return nejmensiIndex;
}

void serad(int serazeno, int delka, Osoba pole[])
{
    if(serazeno + 1 >= delka)
        return;
    
    int iNejmensi = serazeno;

    for(int i = serazeno + 1; i < delka; i++)
    {
        if(porovnej(pole[i], pole[iNejmensi]) < 0)
            iNejmensi = i;
    }
    vymen(&(pole[serazeno]), &(pole[iNejmensi]));
    serad(serazeno + 1, delka, pole);
}

void vymen(Osoba* A, Osoba* B)
{
    char jmenoA[NAME_LENGTH];
    int vekA = A->vek;

    strcpy(jmenoA, A->jmeno);

    strcpy(A->jmeno, B->jmeno);
    A->vek = B->vek;

    strcpy(B->jmeno, jmenoA);
    B->vek = vekA;
}
void print_osoby(Osoba *A, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("{%s, %d}, ", A[i].jmeno, A[i].vek);
    }
    printf("\n");
}

void print_osoba(Osoba A)
{
    printf("{%s, %d}\n", A.jmeno, A.vek);
}

void print_porovnej(int a)
{
    switch (a)
    {
    case -1:
        printf("Druhá osoba je abecedně větší.\n");
        break;

    case 1:
        printf("První osoba je abecedně větší.\n");
        break;

    case -2:
        printf("Jména jsou stejná, ale první osoba má menší věk.\n");
        break;

    case 2:
        printf("Jména jsou stejná, ale první osoba má větší věk.\n");
        break;
    }
}

int porovnej (Osoba A, Osoba B)
{
    char a, b;
    for(int i = 0; i < NAME_LENGTH; i++)
    {
        a = tolower(A.jmeno[i]);
        b = tolower(B.jmeno[i]);

        if(a == '\0' && b != '\0')
            return -1;

        if(a != '\0' && b == '\0')
            return 1;

        if(a < b)
            return -1;

        if(a > b)
            return 1;
    }

    if(A.vek < B.vek)
        return -2;
    
    if(A.vek > B.vek)
        return 2;

    return 0;
}