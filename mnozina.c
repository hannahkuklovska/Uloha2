
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
     int N;
     int p[1000];
} MNOZINA;

void tlac_mnoziny(MNOZINA mnozina)
{

     for (int i = 0; i < mnozina.N; i++)
     {
          printf("%6d", mnozina.p[i]);
     }
     printf("\n");
}

void sort(MNOZINA *mnozina)
{

     for (int i = 0; i < mnozina->N - 1; i++)
     {
          int min_index = i;

          for (int j = i + 1; j < mnozina->N; j++)
          {
               if (mnozina->p[j] < mnozina->p[min_index])
               {
                    min_index = j;
               }
          }

          int temp = mnozina->p[i];
          mnozina->p[i] = mnozina->p[min_index];
          mnozina->p[min_index] = temp;
     }
}

MNOZINA prienik_mnozin(MNOZINA mnozina_1, MNOZINA mnozina_2, int *pocet_op)
{

     sort(&mnozina_1);
     sort(&mnozina_2);
     MNOZINA vysledok = {0};
     int i = 0;
     int j = 0;
     for (i = 0, j = 0; i < mnozina_1.N && j < mnozina_2.N;)
     {
          (*pocet_op)++;
          if (mnozina_1.p[i] == mnozina_2.p[j])
          {
               vysledok.p[vysledok.N++] = mnozina_1.p[i];
               i++;
               j++;
          }
          else if (mnozina_1.p[i] > mnozina_2.p[j])
          {
               j++;
          }
          else
          {
               i++;
          }
     }
     return vysledok;
}

MNOZINA zjednotenie_mnozin(MNOZINA mnozina_1, MNOZINA mnozina_2, int *pocet_op)
{
     sort(&mnozina_1);
     sort(&mnozina_2);
     MNOZINA vysledok = {0};

     for (int i = 0; i < mnozina_1.N; i++)
     {
          vysledok.p[vysledok.N++] = mnozina_1.p[i];
          (*pocet_op)++;
     }

     for (int i = 0; i < mnozina_2.N; i++)
     {
          int pritomny = 0;
          for (int j = 0; j < mnozina_1.N; j++)
          {
               (*pocet_op)++;
               if (mnozina_2.p[i] == mnozina_1.p[j])
               {
                    pritomny = 1;
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
     mnozina.N = velkost;

     for (int i = 0; i < velkost; i++)
     {
          mnozina.p[i] = dh + rand() % (hh - dh + 1);
     }

     return mnozina;
}

void main()
{
     srand(time(NULL));
     int x;
     int pocet_op_prienik = 0;
     int pocet_op_zjednotenie = 0;
     MNOZINA mnozina_1 = {3, {1, 2, 3, 8, 9, 5}};
     MNOZINA mnozina_2 = {3, {2, 5, 3, 1, 4, 7}};
     sort(&mnozina_1);
     tlac_mnoziny(mnozina_1);

     MNOZINA prienik = prienik_mnozin(mnozina_1, mnozina_2, &pocet_op_prienik);
     // printf("Funkcia prienik pocet porovnaní: %d \n", pocet_op_prienik);
     tlac_mnoziny(prienik);

     // MNOZINA zjednotenie = zjednotenie_mnozin(mnozina_1, mnozina_2, &pocet_op_zjednotenie);
     // tlac_mnoziny(zjednotenie);
     // printf("Funkcia zjednotenie pocet porovnaní: %d\n", pocet_op_zjednotenie);
     // MNOZINA vygenerovana = generator_mnoziny(5, 1, 80);
     // tlac_mnoziny(vygenerovana);

     for (int i = 1; i < 21; i++)
     {
          int total_pocet_op_prienik = 0.0;
          int total_pocet_op_zjednotenie = 0.0;

          for (int j = 0; j < 100; j++)
          {

               int pocet_op_prienik = 0;
               int pocet_op_zjednotenie = 0;

               MNOZINA vygenerovana_1 = generator_mnoziny(i, 1, 100);
               MNOZINA vygenerovana_2 = generator_mnoziny(i, 1, 100);

               // vygenerovana_1 = sort(vygenerovana_1);
               // vygenerovana_2 = sort(vygenerovana_2);

               MNOZINA prienik = prienik_mnozin(vygenerovana_1, vygenerovana_2, &pocet_op_prienik);
               MNOZINA zjednotenie = zjednotenie_mnozin(vygenerovana_1, vygenerovana_2, &pocet_op_zjednotenie);

               total_pocet_op_prienik += pocet_op_prienik;
               total_pocet_op_zjednotenie += pocet_op_zjednotenie;
          }

          double average_prienik = total_pocet_op_prienik / 100.0;
          double average_zjednotenie = total_pocet_op_zjednotenie / 100.0;

          printf("%d, %.2f, %.2f\n", i, average_prienik, average_zjednotenie);
          // printf("%d, %d, %d\n", i, total_pocet_op_prienik, total_pocet_op_zjednotenie);
     }
}
