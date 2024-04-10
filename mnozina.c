
#include <stdio.h>

typedef struct
{
     int N;
     int *p;
} MNOZINA;

void tlac_mnoziny(int mnozina[], int N)
{

     for (int i = 0; i < N; i++)
     {
          printf("%6d", mnozina[i]);
     }
     printf("\n");
}

int prienik_mnozin(int *mnozina_1, int *mnozina_2, int N, int L, int *prien_velk)
{

     int K = 0;
     int mnozina_3[N];
     for (int i = 0; i < N; i++)
     {
          for (int j = 0; j < L; j++)
          {
               if (mnozina_1[i] == mnozina_2[j])
               {

                    mnozina_3[K] = mnozina_1[i];
                    K++;
                    break;
               }
          }
     }
     *prien_velk = K;
     tlac_mnoziny(mnozina_3, K);
}

int zjednotenie_mnozin(int *mnozina_1, int *mnozina_2, int N, int L)
{
     int K = 0;
     int mnozina_3[N + L];
     for (int i = 0; i < N; i++)
     {
          mnozina_3[K++] = mnozina_1[i];
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
