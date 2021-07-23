#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long n=0,tmp=0;
    int cont=0,sum1=0,sum2=0;

    do
    {
        n = get_long("Number: ");
    } while (n < 1);
    
    tmp = n;

    while(tmp>0)
    {
        sum1 = sum1 + tmp%10;
        tmp = tmp/10;
        cont++;

        if(tmp>0)
        {
            if(tmp%10 < 5)
            {
                sum2 = sum2 + tmp%10*2;
            }
            else{
                sum2 = sum2 + tmp%10*2%10 + tmp%10*2/10;
            }
            tmp = tmp/10;
            cont++;
        }
        
    }

    if((sum1+sum2)%10 == 0)
    {
        if((cont==13 && n/(long)pow(10,12)==4) || (cont==16 && n/(long)pow(10,15)==4))
        {
            printf("VISA\n");
        }
        else if(cont==15 && (n/(long)pow(10,13)==34 || n/(long)pow(10,13)==37))
        {
            printf("AMEX\n");
        }
        else if(cont==16 && (n/(long)pow(10,14)>=51 || n/(long)pow(10,14)<=55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
        
    }
    else
    {
        printf("INVALID\n");
    }
    

}