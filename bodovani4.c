#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct Bod
{
    float x;
    float y;
} Bod;

float prumernaVzdalenost (int delka, Bod pole[]);
void stredMnoziny (int delka, Bod pole[], Bod* S);
Bod* nejblizsiBod (int delka, Bod pole[], Bod S);

float vzdalenost (Bod A, Bod B)
{
    return sqrtf((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
}

int main()
{
    Bod poleBodu1[] = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 2.0}, {2.0, 0.0}};
    Bod stred;
    Bod* aNejblizsiBod;

    printf("poleBodu1:\n");
    printf("Prumerna vzdalenost: %.6f\n", prumernaVzdalenost(4, poleBodu1));
    stredMnoziny(4, poleBodu1, &stred);
    printf("Stred mnoziny: (%.2f, %.2f)\n", stred.x, stred.y);
    aNejblizsiBod = nejblizsiBod(4, poleBodu1, stred);
    printf("Nejblizsi bod ke stredu: (%.2f, %.2f)\n\n", aNejblizsiBod->x, aNejblizsiBod->y);

    free(aNejblizsiBod);
    aNejblizsiBod = NULL;
    
    Bod poleBodu2[] = {{0.0, 0.0}, {1.0, 3.0}, {3.0, 2.0}, {3.0, 0.0}};

    printf("poleBodu2:\n");
    printf("Prumerna vzdalenost: %.6f\n", prumernaVzdalenost(4, poleBodu2));
    stredMnoziny(4, poleBodu2, &stred);
    printf("Stred mnoziny: (%.2f, %.2f)\n", stred.x, stred.y);
    aNejblizsiBod = nejblizsiBod(4, poleBodu2, stred);
    printf("Nejblizsi bod ke stredu: (%.2f, %.2f)\n", aNejblizsiBod->x, aNejblizsiBod->y);
    free(aNejblizsiBod);

}

float prumernaVzdalenost (int delka, Bod pole[])
{
    float vzdalenostCelkem = 0.0f;
    int vypocitaneVzdalenosti = 0;

    for(int i = 0; i < delka - 1; i++)
    {
        for (int j = i + 1; j < delka; j++)
        {
            vzdalenostCelkem += vzdalenost(pole[i], pole[j]);
            vypocitaneVzdalenosti++;
        }
    }
    return vzdalenostCelkem / vypocitaneVzdalenosti;
}

void stredMnoziny (int delka, Bod pole[], Bod* S)
{
    float x = 0, y = 0;
    float pocet = 0;

    for(int i = 0; i < delka; i++)
    {
        x += pole[i].x;
        y += pole[i].y;
        pocet++;
    }

    x = x / pocet;
    y = y / pocet;

    S->x = x;
    S->y = y;
}

Bod* nejblizsiBod (int delka, Bod pole[], Bod S)
{
    Bod *N = malloc(sizeof(Bod));

    float nejmensiVzdalenost = 0.0f, aVzdalenost = 0.0f;

    *N = pole[0];
    nejmensiVzdalenost = vzdalenost(pole[0], S);

    for(int i = 1; i < delka; i++)
    {
        aVzdalenost = vzdalenost(pole[i], S);

        if(aVzdalenost < nejmensiVzdalenost)
        {
            *N = pole[i];
            nejmensiVzdalenost = aVzdalenost;
        }
    }
    return N;
}