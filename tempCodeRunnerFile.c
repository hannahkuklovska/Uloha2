int prienik_mnozin(int mnozina_1[], int mnozina_2[], int N, int L)
{

     int K = 0;
     int mnozina_3[N];
     for (int i = 0; i < N; i++)
     {
          for (int j = 0; i < L; j++)
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