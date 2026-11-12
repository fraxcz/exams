#include <stdio.h>
#include <stdlib.h>

typedef struct vektor
{
    int *arr;
    int delka;
} vektor;

vektor* alokujVektor ();
void vypisVektor (vektor * A);
void uvolniVektor (vektor **A);
void pridejPosledni (vektor * A, int cislo);
void odeberPosledni (vektor * A);
void odeberVsechny (vektor * A);
void pridejPrvni (vektor * A, int cislo);
void odeberIndex (vektor * A, int index);

int main()
{
    vektor *v = alokujVektor();

    // přidej poslední
    vypisVektor(v);
    pridejPosledni(v, 10);
    vypisVektor(v);

    pridejPosledni(v, 20);
    vypisVektor(v);

    pridejPosledni(v, 30);
    vypisVektor(v);

    odeberPosledni(v);
    vypisVektor(v);

    odeberVsechny(v);
    vypisVektor(v);

    //přidej první
    pridejPrvni(v, 40);
    vypisVektor(v);

    pridejPrvni(v, 50);
    vypisVektor(v);

    pridejPrvni(v, 60);
    vypisVektor(v);

    //odeber index
    odeberIndex(v, 100);
    vypisVektor(v);

    odeberIndex(v, -100);
    vypisVektor(v);

    odeberIndex(v, 1);
    vypisVektor(v);

    uvolniVektor(&v);
    return 0;
}

void vypisVektor (vektor * A)
{   
    printf("Vektor: ");
    if(!(A->delka))
    {
        printf("\n");
        return;
    }

    printf("(");
    for(int i = 0; i < A->delka - 1; i++)
    {
        printf("%d, ", A->arr[i]);
    }
    printf("%d)\n", A->arr[A->delka - 1]);
}

vektor* alokujVektor()
{
    vektor *v = malloc(sizeof(vektor));
    v->delka = 0;
    v->arr = NULL;
    return v;
}

void uvolniVektor (vektor **A)
{
    if(*A != NULL)
    {
        if((*A)->arr != NULL)
        {
            free((*A)->arr);
            (*A)->arr = NULL;
        }
        free(*A);
        *A = NULL;
    }
}

void pridejPosledni (vektor * A, int cislo)
{   
    if(A->delka == 0)
    {
        A->arr = malloc(sizeof(int));
        A->delka += 1;
        A->arr[A->delka - 1] = cislo;
        return;
    }

    A->arr = realloc(A->arr, sizeof(int) * (A->delka + 1));
    A->delka += 1;
    A->arr[A->delka - 1] = cislo;
}

void odeberPosledni (vektor * A)
{
    if(A->delka == 0)
        return;

    A->arr = realloc(A->arr, sizeof(int) * (A->delka - 1));
    A->delka -= 1;
}

void odeberVsechny (vektor * A)
{
    free(A->arr);
    A->arr = NULL;
    A->delka = 0;
}

void pridejPrvni (vektor * A, int cislo)
{
    if(A->delka == 0)
    {
        A->arr = malloc(sizeof(int));
        A->delka += 1;
        A->arr[A->delka - 1] = cislo;
        return;
    }
    A->arr = realloc(A->arr, sizeof(int) * (A->delka + 1));
    A->delka += 1;

    for(int i = A->delka - 1; i > 0; i--)
    {   
        A->arr[i] = A->arr[i - 1];
    }
    A->arr[0] = cislo;
}

void odeberIndex (vektor * A, int index)
{
    if(A == NULL || A->delka < 1 || index >= A->delka || index < 0)
        return;

    for(int i = index + 1; i < A->delka; i++)
    {
        A->arr[i - 1] = A->arr[i];
    }

    odeberPosledni(A);
}