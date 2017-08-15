#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int mul(int a, int b)
{
    int i = 1;
    int x = a;
    for(i; i < b; i++)
    {
        a =  a + x;
    }
    return(a);
}

int pot (int a , int b)
{
    int i = 1;
    int x = a;
    for (i ; i < b; i++)
    {
        a = mul(a,x);
    }
    return (a);

}

int factorial (int a)
{

    int i = 1;
    int x = a;
    for (i; i< x; i++)
    {
        a = mul(i,a);
    }
    return (a);
}

int division(int a, int b, int c)
{
    c= a / b;
    
    return(c);
    }
    
int main ()
{
    int a,b,c ;
    printf("digite a \n");
    scanf("%d",&a);
    printf("digite b\n");
    scanf("%d",&b);
    c = mul(a,b);
    printf("\nmultiplicacion: %d",c);
    c = pot(a,b);
    printf("\npotencia: %d",c);
    c = factorial(a);
    printf("\nfactorial de a: %d",c);
}
