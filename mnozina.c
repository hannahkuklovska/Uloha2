
#include <stdio.h>

void tlac_mnoziny(int mnozina[], int N)
{
     for (int i = 0; i < N; i++)
     {
          printf("%d ", mnozina[i]);
     }
     printf("\n");
}

int prienik_mnozin(int mnozina_1[], int mnozina_2[], int N, int L)
{
     int K;
     int mnozina_3[K];
     for (int i = 0; i < N; i++)
     {
          for (int j = 0; i < L; i++)
          {
               if (mnozina_1[i] == mnozina_2[j])
               {

                    mnozina_3[K++] = mnozina_2[j];
               }
          }
     }
     tlac_mnoziny(mnozina_3, K);
}

void main()
{

     int mnozina_1[3] = {1, 2, 3};
     int mnozina_2[2] = {2, 4};
     int velkost_prieniku;
     tlac_mnoziny(mnozina_1, 3);
     prienik_mnozin(mnozina_1, mnozina_2, 3, 2);
}
