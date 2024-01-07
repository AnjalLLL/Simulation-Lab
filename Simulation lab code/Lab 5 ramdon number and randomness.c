#include<stdio.h>
#include<math.h>
int main()
{
    randomNo();
}
int randomNo(){
     int n, i, m, c, a, X[20];
     float f[20];
     printf("Enter the number of random no.\n ");
     scanf("%d",&n);
     printf("Enter the value of seed X0. \n ");
     scanf("%d",&X[0]);
     printf("Enter the value of a.\n ");
     scanf("%d",&a);
     printf("Enter the value of c greater than 0.\n ");
     scanf("%d",&c);
     printf("Enter the value of modulus m.\n ");
     scanf("%d",&m);
     f[0]= (float) X[0]/m;
     if(c>=1)
     {
         for(i=0;i<n;i++)
     {
          X[i+1]=(a*X[i]+c)%m;
          f[i+1]= (float)X[i+1]/m;
     }
     //Print random number
     printf("\nRandom integers are :\n");
     for(i=0;i<n;i++)
     {
         printf("%d \t",X[i]);
     }

     printf("\nRandom numbers are :\n");

     for(i=0;i<n;i++)
     {
         printf("%.2f \t",f[i]);
     }

     }
     else
     {
         printf("Enter the value of c is greater than 0.");
     }
     //Kolmogoros-Smirnov test for checking randomness

     return testRandomness(X,n);

}
int testRandomness(float X[],int N)
{
    float C_plus[20],C_minus[20],i=1,C,C1max,C2max,Dmax;
    int j;
    float D_alpha[20]={0.975,0.841,0.707,0.623,0.563,0.519,0.483,0.454,0.430,0.409,0.391,0.375,0.361,0.348,0.337,0.327,0.317,0.309,0.301,0.294};
    //Calculate C_plus
    for(j=0;j<N;j++)
    {
       C_plus[j]= (float)(i/N)-X[j];
       i++;
    }
    for(j=0;j<N;j++)
    {
       C_minus[j]= (float) X[j]-(i-1/N);
       i++;
    }
    C1max=C_plus[0];
    C2max = C_minus[0];
    for (j = 1; j< N; j++) {
        //Compare elements of array with max
       if(C_plus[j] > C1max)
           C1max = C_plus[j];
    }
    for (j = 1; j < N; j++) {
        //Compare elements of array with max
       if(C_minus[j] > C2max)
           C2max = C_minus[j];
    }
    if(C1max>C2max){
        Dmax=C1max;
    }
    else{
        Dmax=C2max;
    }
    printf("\n\nChecking randomness of generated random no at 0.05 level of significance ....\n");

    printf("\n D+");
   for(j=0;j<N;j++)
   {
       printf("\t| %.3f |",C_plus[j]);
   }
   printf("\n D-");
   for(j=0;j<N;j++)
   {
       printf("\t| %.3f |",C_minus[j]);
   }
    printf("\n\n D+ max : %f \n D- max : %f",C1max,C2max);
    printf("\nCalculated D_Max : %.3f\n Tabulated value D_alpha : %.2f",Dmax,D_alpha[N-1]);

    if(Dmax<D_alpha[N-1])
    {
        printf("\nThe hypothesis of given random number distributions is accepted.\n");
    }
    else{
        printf("\n'Dmax>D_alpha'. Hence The hypothesis of given random number distributions is not accepted.\n");
    }

}

