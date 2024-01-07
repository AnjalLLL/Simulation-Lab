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
     printf("Enter the value of a greater than 0.\n ");
     scanf("%d",&a);
     printf("Enter the value of modulus m.\n ");
     scanf("%d",&m);
     f[0]= (float) X[0]/m;
     if(a>=1)
     {
         for(i=0;i<n;i++)
     {
          X[i+1]=(a*X[i])%m;
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


}
