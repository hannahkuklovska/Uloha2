
#include <stdio.h>

typedef struct
{
     int N;
     int *p;
} MNOZINA;

void tlac_mnoziny(MNOZINA mnozina)
{

     for (int i = 0; i < mnozina.N; i++)
     {
          printf("%6d", mnozina.p[i]);
     }
     printf("\n");
}

MNOZINA prienik_mnozin(MNOZINA mnozina_1, MNOZINA mnozina_2)
{

     MNOZINA vysledok = {0};
     for (int i = 0; i < mnozina_1.N; i++)
     {
          for (int j = 0; j < mnozina_2.N; j++)
          {
               if (mnozina_1.p[i] == mnozina_2.p[j])
               {
                    vysledok.p[vysledok.N++] = mnozina_1.p[i];

                    break;
               }
          }
     }
     return vysledok;
}

MNOZINA zjednotenie_mnozin(MNOZINA mnozina_1, MNOZINA mnozina_2)
{
     MNOZINA vysledok = {0};
     for (int i = 0; i < mnozina_1.N; i++)
     {
          vysledok.p[vysledok.N++] = mnozina_1.p[i];
     }

     for (int i = 0; i < L; i++)
     {
          int pritomny = 0;
          for (int j = 0; j < N; j++)
          {
               if (mnozina_2[i] == mnozina_1[j])
               {
                    pritomny = 1;
                    break;
               }
          }

          if (!pritomny)
          {
               mnozina_3[K++] = mnozina_2[i];
          }
     }
     tlac_mnoziny(mnozina_3, K);
}

void main()
{
     int prien_velk;
     int mnozina_1[3] = {1, 2, 3};
     int mnozina_2[3] = {2, 5, 7};
     tlac_mnoziny(mnozina_1, 3);
     prienik_mnozin(mnozina_1, mnozina_2, 3, 3, &prien_velk);
     zjednotenie_mnozin(mnozina_1, mnozina_2, 3, 3);
}
