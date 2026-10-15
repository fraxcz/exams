#include <stdio.h>
#include <math.h>

typedef struct Bod
{
    float x;
    float y;
} Bod;

typedef struct Trojuhelnik
{
    Bod bodA;
    Bod bodB;
    Bod bodC;
} Trojuhelnik;

void vypisSouradnice ( Trojuhelnik T);
float vzdalenost (Bod A, Bod B);
float obvod( Trojuhelnik T);
float obsah( Trojuhelnik T);
Bod teziste ( Trojuhelnik T);

int main()
{
    // První Trojuhelnik

    Trojuhelnik trojuhelnik1 = {{0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0}};
    Bod tezisteTrojuhelniku1 = teziste(trojuhelnik1);

    printf("Prvni trojuhelnik: \n");

    vypisSouradnice(trojuhelnik1);
    
    printf("Vzdalenost BC: %.3f\n", vzdalenost(trojuhelnik1.bodB, trojuhelnik1.bodC));
    printf("Obvod: %.3f\n", obvod(trojuhelnik1));
    printf("Obsah: %.3f\n", obsah(trojuhelnik1));
    printf("Teziste: (%.3f, %.3f)\n\n", tezisteTrojuhelniku1.x, tezisteTrojuhelniku1.y);

    Trojuhelnik trojuhelnik2 = {{0.0, 0.0}, {2.0, 0.0}, {1.0, 2.0}};
    Bod tezisteTrojuhelniku2 = teziste(trojuhelnik2);

    printf("Druhy trojuhelnik: \n");

    vypisSouradnice(trojuhelnik2);
    printf("Vzdalenost BC: %.3f\n", vzdalenost(trojuhelnik2.bodB, trojuhelnik2.bodC));
    printf("Obvod: %.3f\n", obvod(trojuhelnik2));
    printf("Obsah: %.3f\n", obsah(trojuhelnik2));
    printf("Teziste: (%.3f, %.3f)\n", tezisteTrojuhelniku2.x, tezisteTrojuhelniku2.y);

}

void vypisSouradnice(Trojuhelnik T)
{
    printf("A = (%.3f, %.3f)\n", T.bodA.x, T.bodA.y);
    printf("B = (%.3f, %.3f)\n", T.bodB.x, T.bodB.y);
    printf("C = (%.3f, %.3f)\n", T.bodC.x, T.bodC.y);
}

float vzdalenost (Bod A, Bod B)
{
    return sqrtf(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

float obvod( Trojuhelnik T)
{
    float stranaA, stranaB, stranaC;

    stranaA = vzdalenost(T.bodB, T.bodC);
    stranaB = vzdalenost(T.bodA, T.bodC);
    stranaC = vzdalenost(T.bodA, T.bodB);

    return stranaA + stranaB + stranaC;
}

float obsah( Trojuhelnik T)
{
    // Heronův vzorec

    float a = vzdalenost(T.bodB, T.bodC);
    float b = vzdalenost(T.bodA, T.bodC);
    float c = vzdalenost(T.bodA, T.bodB);

    float s = a + b + c / 2.0f;

    return sqrtf(s * (s - a) * (s - b) * (s - c));
}

Bod teziste ( Trojuhelnik T)
{
    Bod teziste1 = {(T.bodA.x + T.bodB.x + T.bodC.x) / 3, (T.bodA.y + T.bodB.y + T.bodC.y) / 3};
    return teziste1;
}