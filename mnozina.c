
#include <stdio.h>

void tlac_mnoziny(int mnozina[], int N)
{

     for (int i = 0; i < N; i++)
     {
          printf("%6d", mnozina[i]);
     }
     printf("\n");
}

int prienik_mnozin(int mnozina_1[], int mnozina_2[], int N, int L)
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
     tlac_mnoziny(mnozina_3, K);
}

int zjednotenie_mnozin(int mnozina_1[], int mnozina_2[], int N, int L)
{
     int K = 0;
     int mnozina_3[N + L];
     for (int i = 0; i < N; i++)
     {
          for (int j = 0; i < L; i++)
          {
               {

                    mnozina_3[K++] = mnozina_1[i];
                    mnozina_3[K++] = mnozina_2[j];
               }
          }
     }
     tlac_mnoziny(mnozina_3, K);
}

void main()
{

     int mnozina_1[3] = {1, 2, 3};
     int mnozina_2[3] = {2, 5, 7};
     tlac_mnoziny(mnozina_1, 3);
     prienik_mnozin(mnozina_1, mnozina_2, 3, 3);
     zjednotenie_mnozin(mnozina_1, mnozina_2, 3, 3);
}
