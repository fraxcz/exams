#define poleA_LEN 4
#define poleB_LEN 5
#define poleC_LEN 6
#include <stdio.h>
#include <stdbool.h>

bool jeVMnozine (int delka, int pole[], int cislo);
bool jeMnozina (int delka, int pole[]);
void vypisPrunik (int delkaA , int poleA[], int delkaB , int poleB[]);
void vypisSjednoceni (int delkaA , int poleA[], int delkaB , int poleB[]);

int main()
{
    int poleA[poleA_LEN] = {1, 2, 3, 4};
    int poleB[poleB_LEN] = {0, 2, 4, 6, 8};
    int poleC[poleC_LEN] = {1, 0, 3, 5, 0, 7};
    int cislo1 = 0;

    // ------------------- jeVMnozine -------------------
    if(jeVMnozine(poleA_LEN, poleA, cislo1))
    {
        printf("Pole A obsahuje hodnotu %d.\n\n", cislo1);
    }
    else
    {
        printf("Pole A neobsahuje hodnotu %d.\n\n", cislo1);
    }

    if(jeVMnozine(poleB_LEN, poleB, cislo1))
    {
        printf("Pole B obsahuje hodnotu %d.\n\n", cislo1);
    }
    else
    {
        printf("Pole B neobsahuje hodnotu %d.\n\n", cislo1);
    }

    if(jeVMnozine(poleC_LEN, poleC, cislo1))
    {
        printf("Pole C obsahuje hodnotu %d.\n\n", cislo1);
    }
    else
    {
        printf("Pole C neobsahuje hodnotu %d.\n\n", cislo1);
    }


    // ------------------- jeMnozina -------------------
    if(jeMnozina(poleA_LEN, poleA))
    {
        printf("Pole A je mnozina.\n\n");
    }
    else
    {
        printf("Pole A neni mnozina.\n\n");
    }

    if(jeMnozina(poleB_LEN, poleB))
    {
        printf("Pole B je mnozina.\n\n");
    }
    else
    {
        printf("Pole B neni mnozina.\n\n");
    }

    if(jeMnozina(poleC_LEN, poleC))
    {
        printf("Pole C je mnozina.\n\n");
    }
    else
    {
        printf("Pole C neni mnozina.\n\n");
    }

    // ------------------- vypis prunik -------------------
    vypisPrunik(poleA_LEN, poleA, poleB_LEN, poleB);


    // ------------------- vypis sjednoceni -------------------
    vypisSjednoceni(poleA_LEN, poleA, poleB_LEN, poleB);
    return 0;
}

bool jeVMnozine (int delka, int pole[], int cislo)
{
    for(int i = 0; i < delka; i++)
    {
        if(cislo == pole[i])
            return true;
    }
    return false;
}

bool jeMnozina (int delka, int pole[])
{
    if(!delka)
        return true;
    
    for(int i = 0; i < delka / 2 + 1; i++)
    {
        for(int j = 0; j < delka; j++)
        {
            if(i != j && pole[i] == pole[j])
                return false;
        }
    }
    return true;
}

void vypisPrunik (int delkaA , int poleA[], int delkaB , int poleB[])
{
    printf("Prunik mnozin A a B: \n");

    for(int i = 0; i < delkaA; i++)
    {
        for(int j = 0; j < delkaB; j++)
        {
            if(poleA[i] == poleB[j])
            {

                printf("%d ", poleA[i]);
            }
        }   
    }
    printf("\n");
}

void vypisSjednoceni (int delkaA , int poleA[], int delkaB , int poleB[])
{
    if(!jeMnozina(delkaA, poleA) || !jeMnozina(delkaB, poleB))
    {
        printf("Jedno nebo obe pole nejsou mnoziny!\n");
        return;
    }

    printf("Sjednoceni mnozin A a B: \n");

    for(int i = 0; i < delkaA; i++)
    {
        printf("%d ", poleA[i]);
    }

    bool lezi;
    for(int i = 0; i < delkaB; i++)
    {   
        lezi = false;
        for(int j = 0; j < delkaA; j++)
        {
            if(poleB[i] == poleA[j])
            {
                lezi = true;
                break;
            }
        }

        if(!lezi)
            printf("%d ", poleB[i]);
    }
    printf("\n");
}

