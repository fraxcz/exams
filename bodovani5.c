#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN 5 // velikost pole vektoru

typedef struct vektor
{
    int *arr;
    int delka;
} vektor;

vektor * alokujVektor (int delka);
void nactiVektor (vektor * A);
void vypisVektor (vektor * A);
vektor * konkatenace (vektor * A, vektor * B);
bool jeMnozina (vektor * A);
void uvolniVektor (vektor **A);
vektor * prunik (vektor * A, vektor * B);

int main()
{
    printf("prvni vektor:\n");
    vektor *v1 = alokujVektor(ARR_LEN);

    if(v1 == NULL)
    {
        printf("Alloc failure.\n");
        return 0;
    }

    nactiVektor(v1);

    printf("\n Druhy vektor: ");
    vektor *v2 = alokujVektor(ARR_LEN);

    if(v2 == NULL)
    {
        printf("Alloc failure.\n");
    }
    nactiVektor(v2);

    vektor *kv = konkatenace(v1, v2);

    if(kv == NULL)
    {
        printf("Alloc failure.\n");
    }

    vypisVektor(v1);
    vypisVektor(v2);
    printf("\n konkatenace: ");
    vypisVektor(kv);

    printf("\n");
    vypisVektor(v1);

    if(jeMnozina(v1))
        printf(" je mnozina.\n");
    else
        printf(" neni mnozina.\n");

    printf("\n");
    vypisVektor(v2);

    if(jeMnozina(v2))
        printf(" je mnozina.\n");
    else
        printf(" neni mnozina.\n");
    
    printf("\n");

    vektor *pv = prunik(v1, v2);

    if(pv)
    {
        printf("Prunik 2 vektoru: ");
        vypisVektor(pv);
    }
    printf("\n");

    uvolniVektor(&v1);
    uvolniVektor(&v2);
    uvolniVektor(&kv);
    uvolniVektor(&pv);
    return 0;
}

vektor* alokujVektor (int delka)
{
    vektor *v = malloc(sizeof(vektor));
    v->arr = malloc(sizeof(int) * delka);
    v->delka = delka;
    return v;
}

void nactiVektor(vektor *a)
{
    for(int i = 0; i < a->delka; i++)
    {
        printf("Napis %d. cislo: ", i + 1);
        scanf("%d", a->arr + i);
    }
}

void vypisVektor (vektor * A)
{
    if(!(A->delka))
    {
        printf("Delka neni specifikovana. (Takovy vektor neexistuje)\n");
        return;
    }

    printf("(");
    for(int i = 0; i < A->delka - 1; i++)
    {
        printf("%d, ", A->arr[i]);
    }
    printf("%d)\n", A->arr[A->delka - 1]);
}

vektor *konkatenace (vektor * A, vektor * B)
{
    vektor *v = alokujVektor(A->delka + B->delka);

    memcpy(v->arr, A->arr, sizeof(int) * A->delka);
    memcpy((v->arr) + A->delka, B->arr, sizeof(int) * B->delka);
    return v;
}

bool jeMnozina (vektor * A)
{
        for(int i = 0; i < A->delka / 2 + 1; i++)
    {
        for(int j = 0; j < A->delka; j++)
        {
            if(i != j && A->arr[i] == A->arr[j])
                return false;
        }
    }
    return true;
}

void uvolniVektor (vektor **A)
{
    free((*A)->arr);
    (*A)->arr = NULL;
    free(*A);
    *A = NULL;
}

vektor *prunik (vektor * A, vektor * B)
{
    if(!jeMnozina(A) || !jeMnozina(B))
    {
        printf("jedno z vektoru neni mnozina!\n");
        return NULL;
    }
    vektor *v = alokujVektor(A->delka + B->delka);
    int delka = 0;

    for(int i = 0; i < A->delka; i++)
    {
        for(int j = 0; j < B->delka; j++)
        {
            if(A->arr[i] == B->arr[j])
            {
                v->arr[delka] = A->arr[i];
                delka++;
            }
        }   
    }
    v->delka = delka;
    return v;
}