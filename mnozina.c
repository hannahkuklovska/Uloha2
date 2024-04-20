
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
     int N;
     int p[100];
} MNOZINA;

void tlac_mnoziny(MNOZINA mnozina)
{

     for (int i = 0; i < mnozina.N; i++)
     {
          printf("%6d", mnozina.p[i]);
     }
     printf("\n");
}

MNOZINA prienik_mnozin(MNOZINA mnozina_1, MNOZINA mnozina_2, int *pocet_op)
{

     MNOZINA vysledok = {0};
     for (int i = 0; i < mnozina_1.N; i++)
     {
          for (int j = 0; j < mnozina_2.N; j++)
          {
               if (mnozina_1.p[i] == mnozina_2.p[j])
               {
                    vysledok.p[vysledok.N++] = mnozina_1.p[i];
                    pocet_op++;
                    break;
               }
          }
     }
     return vysledok;
}

MNOZINA zjednotenie_mnozin(MNOZINA mnozina_1, MNOZINA mnozina_2, int *pocet_op)
{
     MNOZINA vysledok = {0};
     for (int i = 0; i < mnozina_1.N; i++)
     {
          vysledok.p[vysledok.N++] = mnozina_1.p[i];
     }

     for (int i = 0; i < mnozina_2.N; i++)
     {
          int pritomny = 0;
          for (int j = 0; j < mnozina_1.N; j++)
          {
               if (mnozina_2.p[i] == mnozina_1.p[j])
               {
                    pritomny = 1;
                    pocet_op++;
                    break;
               }
          }

          if (!pritomny)
          {
               vysledok.p[vysledok.N++] = mnozina_2.p[i];
          }
     }
     return vysledok;
}

MNOZINA generator_mnoziny(int velkost, int dh, int hh)
{
     MNOZINA mnozina;
     mnozina.N = 0;

     srand(time(NULL));

     for (int i = 0; i < velkost; i++)
     {
          mnozina.p[i] = dh + rand() % (hh - dh + 1);
          mnozina.N++;
     }

     return mnozina;
}

void main()
{
     int x;
     int pocet_op_prienik;
     int pocet_op_zjednotenie;
     MNOZINA mnozina_1 = {3, {1, 2, 3}};
     MNOZINA mnozina_2 = {3, {2, 5, 7}};
     MNOZINA prienik = prienik_mnozin(mnozina_1, mnozina_2, &pocet_op_prienik);
     printf("Funkcia prienik pocet porovnaní: %d \n", pocet_op_prienik);
     tlac_mnoziny(prienik);

     MNOZINA zjednotenie = zjednotenie_mnozin(mnozina_1, mnozina_2, &pocet_op_zjednotenie);
     tlac_mnoziny(zjednotenie);
     printf("Funkcia zjednotenie pocet porovnaní: %d\n", pocet_op_zjednotenie);
     MNOZINA vygenerovana = generator_mnoziny(5, 1, 80);
     tlac_mnoziny(vygenerovana);
}
