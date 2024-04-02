
#include <stdio.h>

void tlac_mnoziny(int mnozina[], int N)
{
     for (int i = 0; i < N; i++)
     {
          printf("%d ", mnozina[i]);
     }
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
                    K++;
                    mnozina_3[i] = mnozina_2[j];
               }
          }
     }
     return K;
}

void main()
{

     int mnozina_1[3] = {1, 2, 3};
     int mnozina_2[2] = {2, 4};

     prienik_mnozin(mnozina_1, mnozina_2, 3, 2);
}
