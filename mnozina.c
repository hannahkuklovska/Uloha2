
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
     int N;
     int *p; // dynamická alokácia
} MNOZINA;

void tlac_mnoziny(MNOZINA mnozina)
{

     int i;
     for (i = 0; i < mnozina.N; i++)
     {
          printf("%6d", mnozina.p[i]);
     }
     printf("\n");
}

void sort(MNOZINA *mnozina)
{
     int i, j, min_index, temp;
     for (i = 0; i < mnozina->N - 1; i++)
     {
          min_index = i;

          for (j = i + 1; j < mnozina->N; j++)
          {
               if (mnozina->p[j] < mnozina->p[min_index])
               {
                    min_index = j;
               }
          }

          temp = mnozina->p[i];
          mnozina->p[i] = mnozina->p[min_index];
          mnozina->p[min_index] = temp;
     }
}

MNOZINA prienik_mnozin(MNOZINA mnozina_1, MNOZINA mnozina_2, int *pocet_op)
{

     int j, i;
     MNOZINA vysledok;
     vysledok.N = 0;
     i = 0;
     j = 0;
     vysledok.p = malloc((mnozina_1.N < mnozina_2.N ? mnozina_1.N : mnozina_2.N) * sizeof(int));
     if (vysledok.p == NULL)
     {
          return vysledok;
     }
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
     int i, j, pritomny;

     MNOZINA vysledok;
     vysledok.N = 0;
     vysledok.p = malloc((mnozina_1.N + mnozina_2.N) * sizeof(int));
     if (vysledok.p == NULL)
     {
          return vysledok;
     }

     for (i = 0, j = 0; i < mnozina_1.N || j < mnozina_2.N;)
     {
          (*pocet_op)++;
          if (i < mnozina_1.N && (j >= mnozina_2.N || mnozina_1.p[i] < mnozina_2.p[j]))
          {
               if (vysledok.N == 0 || vysledok.p[vysledok.N - 1] != mnozina_1.p[i])
               {
                    vysledok.p[vysledok.N++] = mnozina_1.p[i];
               }
               i++;
          }
          else if (j < mnozina_2.N && (i >= mnozina_1.N || mnozina_2.p[j] < mnozina_1.p[i]))
          {
               if (vysledok.N == 0 || vysledok.p[vysledok.N - 1] != mnozina_2.p[j])
               {
                    vysledok.p[vysledok.N++] = mnozina_2.p[j];
               }
               j++;
          }
          else
          {
               if (vysledok.N == 0 || vysledok.p[vysledok.N - 1] != mnozina_1.p[i])
               {
               }
          }
     }

     for (i = 0; i < mnozina_2.N; i++)
     {
          pritomny = 0;
          for (j = 0; j < mnozina_1.N; j++)
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
     int i;
     mnozina.p = malloc(velkost * sizeof(int));
     if (mnozina.p == NULL)
     {
          mnozina.N = 0;
          return mnozina;
     }
     for (i = 0; i < velkost; i++)
     {
          mnozina.p[i] = 0;
     }
     for (i = 0; i < velkost; i++)
     {
          mnozina.p[i] = dh + rand() % (hh - dh + 1);
     }

     return mnozina;
}

void main()
{

     int x, i, j;
     int total_pocet_op_prienik, total_pocet_op_zjednotenie, pocet_op_prienik, pocet_op_zjednotenie;
     MNOZINA vygenerovana_1, vygenerovana_2;
     MNOZINA prienik, zjednotenie, vygenerovana;
     double average_prienik, average_zjednotenie;
     pocet_op_prienik = 0;
     pocet_op_zjednotenie = 0;
     srand(time(NULL));

     MNOZINA mnozina_1 = {6, (int[]){1, 2, 3, 8, 9, 5}};
     MNOZINA mnozina_2 = {6, (int[]){2, 5, 3, 1, 4, 7}};
     sort(&mnozina_1);
     sort(&mnozina_2);
     tlac_mnoziny(mnozina_1);

     prienik = prienik_mnozin(mnozina_1, mnozina_2, &pocet_op_prienik);
     if (prienik.p != NULL)

     {
          tlac_mnoziny(prienik);
          free(prienik.p);
     }
     else
     {
          printf("Alokácia sa nepodarila.\n");
     }

     zjednotenie = zjednotenie_mnozin(mnozina_1, mnozina_2, &pocet_op_zjednotenie);
     if (zjednotenie.p != NULL)
     {
          tlac_mnoziny(zjednotenie);
          free(zjednotenie.p);
     }
     else
     {
          printf("Alokácia sa nepodarila.\n");
     }

     vygenerovana = generator_mnoziny(5, 1, 80);
     if (vygenerovana.p != NULL)
     {
          tlac_mnoziny(vygenerovana);
          free(vygenerovana.p);
     }
     else
     {
          printf("Alokácia sa nepodarila.\n");
     }

     for (i = 1; i < 21; i++)
     {

          total_pocet_op_prienik = 0.0;
          total_pocet_op_zjednotenie = 0.0;

          for (j = 0; j < 100; j++)
          {

               pocet_op_prienik = 0;
               pocet_op_zjednotenie = 0;

               vygenerovana_1 = generator_mnoziny(i, 1, 100);
               vygenerovana_2 = generator_mnoziny(i, 1, 100);

               if (vygenerovana_1.p == NULL || vygenerovana_2.p == NULL)
               {
                    printf("Alokácia sa nepodarila\n");
                    free(vygenerovana_1.p);
                    free(vygenerovana_2.p);
                    continue;
               }
               prienik = prienik_mnozin(vygenerovana_1, vygenerovana_2, &pocet_op_prienik);
               zjednotenie = zjednotenie_mnozin(vygenerovana_1, vygenerovana_2, &pocet_op_zjednotenie);

               if (prienik.p == NULL || zjednotenie.p == NULL)
               {
                    printf("Alokácia sa nepodarila\n");
                    free(vygenerovana_1.p);
                    free(vygenerovana_2.p);
                    free(prienik.p);
                    free(zjednotenie.p);
                    continue;
               }

               total_pocet_op_prienik += pocet_op_prienik;
               total_pocet_op_zjednotenie += pocet_op_zjednotenie;

               free(vygenerovana_1.p);
               free(vygenerovana_2.p);
               free(prienik.p);
               free(zjednotenie.p);
          }

          average_prienik = total_pocet_op_prienik / 100.0;
          average_zjednotenie = total_pocet_op_zjednotenie / 100.0;

          printf("%d, %.2f, %.2f\n", i, average_prienik, average_zjednotenie);
          // printf("%d, %d, %d\n", i, total_pocet_op_prienik, total_pocet_op_zjednotenie);
     }
}
