
#include <stdio.h>

void tlac_mnoziny(int mnozina[])
{
     for (int i = 0; i < N; i++)
     {
          printf("%d ", mnozina[i]);
     }
}

void prienik_mnozin(int mnozina_1[], int mnozina_2[])
{
     int N;
     int mnozina_3[N];
     for (int i = 0; i < 3; i++)
     {
          for (int j = 0; i < 2; i++)
          {
               if (mnozina_1[i] == mnozina_2[j])
               {
                    N++;
                    mnozina_3[i] = mnozina_2[j];
               }
          }
     }
}

void main()
{

     int mnozina_1[3] = {1, 2, 3};
     int mnozina_2[2] = {2, 4};
}
